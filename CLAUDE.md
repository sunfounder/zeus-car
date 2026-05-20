# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build

```bash
# Compile the main library sketch
arduino-cli compile --fqbn arduino:avr:uno Zeus_Car

# Compile an example sketch (all examples are self-contained with local copies of library files)
arduino-cli compile --fqbn arduino:avr:uno examples/7_compass
```

Board: **Arduino Uno** (`arduino:avr:uno`). Non-standard libraries required: `IRLremote`, `SoftPWM`, `ArduinoJson`.

## Architecture

This is an Arduino firmware for the SunFounder Zeus Car — a Mecanum-wheel robot car with multiple operating modes. The main sketch is `Zeus_Car/Zeus_Car.ino`. Example sketches under `examples/` each contain their own copies of the driver files they depend on (not symlinks — duplicates that must be kept in sync).

### Key layers

```
Zeus_Car.ino          ← main loop: AI camera → IR/app input → mode dispatch
├── car_control       ← Mecanum kinematics, motor PWM (SoftPWM)
├── compass           ← auto-detect QMC6310 or QMC6309, calibration + averaging
│   ├── qmc6310       ← QMC6310 magnetometer driver (I2C 0x1C)
│   └── qmc6309       ← QMC6309 magnetometer driver (I2C 0x7C / 0x0C)
├── ai_camera         ← serial comm with ESP32-CAM, websockets
├── cmd_code_config   ← command dispatch table (IR keys / speech → car actions)
├── ir_remote         ← IR remote input
├── ir_obstacle       ← IR obstacle sensors (HC165 shift register)
├── ultrasonic        ← ultrasonic distance sensor
├── grayscale         ← grayscale line-tracking sensor
└── rgb               ← RGB LED control (SoftPWM)
```

### Operating modes

Mode dispatch happens in `modeHandler()` based on a `currentMode` global:
- `MODE_NONE` — idle
- `MODE_REMOTE_CONTROL` / `MODE_APP_CONTROL` — joystick-driven field-centric movement
- `MODE_LINE_TRACK_WITH_MAG` / `WITHOUT_MAG` — grayscale line following (with/without compass)
- `MODE_OBSTACLE_FOLLOWING` / `AVOIDANCE` — IR + ultrasonic navigation
- `MODE_COMPASS_CALIBRATION` — compass calibration routine

Field-centric drive (`carMoveFieldCentric`) uses the compass heading to translate joystick angles into world-frame motion.

### Magnetometer: QMC6310 / QMC6309

Both chips share the same data format (6 bytes from register 0x01, little-endian int16 X/Y/Z). The differences are in init sequences and register bit layouts. Auto-detection happens in `compassBegin()`:

| Chip | I2C Addr | Init |
|---|---|---|
| QMC6310 | 0x1C | SIGN(0x29)=0x06 → CTL_2 → CTL_1 |
| QMC6309 | 0x7C or 0x0C | Reset → CTL_2 → CTL_1 |

Both driver classes have identical public APIs: `init()`, `read()`, `getX/Y/Z()`, `getAzimuth()`, `setCalibration()`, `clearCalibration()`.

### Calibration storage

Calibration data (6 × int16 min/max values) is stored in EEPROM starting at address 0, with each value offset by `+0xFF` to fit in uint16 range.

### When changing driver files

If you modify any file under `Zeus_Car/` that also exists in `examples/`, you must sync the copies to all 8 example directories that include them. The affected dirs are: `7_compass`, `8_move_field_centric`, `11_obstacle_avoid`, `12_follow`, `14_line_track`, `15_line_track_field_centric`, `17_app_control`, `18_app_control_plus`.
