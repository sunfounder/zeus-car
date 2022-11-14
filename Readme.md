# Zeus Car
The control program of the Ardunio Mecanum wheel car for Ardunio UNO.

Zeur Car is a  omnidirectional moving car with Macnum wheels.It is controlled by Ardunio UNO and ESP32-CAM, with FPV controller, line patrol, obstacle avoidance and many other interesting functions.You can buy it on [our website](https://www.sunfounder.com/), or search sunfounder in Amazon.

- [Zeus Car](#zeus-car)
  - [Development test environment](#development-test-environment)
  - [Dependency libraries](#dependency-libraries)
  - [ESP32-CAM firmware](#esp32-cam-firmware)
  - [Docs](#docs)
  - [Project Tree](#project-tree)
  - [About SunFounder](#about-sunfounder)
  - [Contact us](#contact-us)
## Development test environment
- Board: Ardunio UNO
- IDE: Arduino IDE 1.8.19
- Compiler Tools: Arduino AVR Boards 1.8.3

## Dependency libraries
- IRLremote
- SoftPWM

## ESP32-CAM firmware
https://github.com/sunfounder/ai-camera-firmware
## Docs
https://docs.sunfounder.com

## Project Tree
```
zeus-car                               
├─ Zeus_Car                            //
│  ├─ Zeus_Car.h                       // macro definition of some variables
│  ├─ Zeus_Car.ino                     // Arduino main program
│  ├─ ai_camera.cpp                    // functions for communicating with ESP32-CAM
│  ├─ ai_camera.h                      //
│  ├─ car_control.cpp                  // functions for controll motors 
│  ├─ car_control.h                    //
│  ├─ cmd_code_config.hpp              // the command table for voice control and IR control
│  ├─ compass.cpp                      // functions for compass sensor
│  ├─ compass.h                        //
│  ├─ grayscale.cpp                    // functions for grayscale line patrol module
│  ├─ grayscale.h                      //
│  ├─ hc165.cpp                        // functions for HC165 - IO expansion chip
│  ├─ hc165.h                          //
│  ├─ ir_obstacle.cpp                  // functions for IR obstacle avoidance module
│  ├─ ir_obstacle.h                    //
│  ├─ ir_remote.cpp                    // functions for IR remote
│  ├─ ir_remote.h                      // 
│  ├─ qmc6310.cpp                      // functions for compass sensor
│  ├─ qmc6310.h                        //
│  ├─ rgb.cpp                          // functions for rgb led strip
│  ├─ rgb.h                            //
│  ├─ test.h                           // functions for testing all modules
│  ├─ ultrasonic.cpp                   // functions for ultrasonic module
│  └─ ultrasonic.h                     //
├─ test                                
│  ├─ grayscale_pattern_classifier.py  // status enumeration tool for 8-way line patrol module
│  ├─ qmc6310test                      //
│  │  ├─ qmc6310.cpp                   //
│  │  ├─ qmc6310.h                     //
│  │  └─ qmc6310test.ino               //
│  └─ test.ino                         //
├─ .gitignore                          //
├─ LICENSE                             //
└─ Readme.md  
```
## About SunFounder
SunFounder is a company focused on STEAM education with products like open source robots, development boards, STEAM kit, modules, tools and other smart devices distributed globally. In SunFounder, we strive to help elementary and middle school students as well as hobbyists, through STEAM education, strengthen their hands-on practices and problem-solving abilities. In this way, we hope to disseminate knowledge and provide skill training in a full-of-joy way, thus fostering your interest in programming and making, and exposing you to a fascinating world of science and engineering. To embrace the future of artificial intelligence, it is urgent and meaningful to learn abundant STEAM knowledge.

## Contact us
website:
    www.sunfounder.com

E-mail:
    service@sunfounder.com