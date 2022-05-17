#include "qmc6310.h"

QMC6310 compass;

int calibrationData[6];
bool changed = false;
bool done = false;
int t = 0;
int c = 0;

void setup() {
  Serial.begin(115200);
  compass.init();
  // calibrateInit();
  compass.setCalibration(2237, 2426, -121, 2529, -3931, -1168);

  Serial.println("Start!");
}

int16_t compassGetAzimuth() {
  compass.read();
  int16_t y = compass.getY();
  int16_t z = compass.getZ();
  int heading = atan2(y, -z) * RAD_TO_DEG;
  return heading;
}

void loop() {
  // calibrate();

  test();
}

void test() {
  compass.read();
  Serial.print("x: ");
  Serial.print(compass.getX());
  Serial.print(", y: ");
  Serial.print(compass.getY());
  Serial.print(", z: ");
  Serial.print(compass.getZ());
  Serial.print(", Azimuth YZ: ");
  Serial.println(compassGetAzimuth());
  delay(100);
}

void calibrateInit() {
  // Serial.println("This will provide calibration settings for your QMC5883L chip. When prompted, move the magnetometer in all directions until the calibration is complete.");
  // Serial.println("Calibration will begin in 5 seconds.");
  // delay(5000);
  compass.read();
  calibrationData[0] = compass.getX();
  calibrationData[1] = compass.getX();
  calibrationData[2] = compass.getY();
  calibrationData[3] = compass.getY();
  calibrationData[4] = compass.getZ();
  calibrationData[5] = compass.getZ();
}

void calibrate() {
  int x, y, z;
  
  // Read compass values
  compass.read();

  // Return XYZ readings
  x = compass.getX();
  y = compass.getY();
  z = compass.getZ();

  changed = false;

  if(x < calibrationData[0]) {
    calibrationData[0] = x;
    changed = true;
  }
  if(x > calibrationData[1]) {
    calibrationData[1] = x;
    changed = true;
  }

  if(y < calibrationData[2]) {
    calibrationData[2] = y;
    changed = true;
  }
  if(y > calibrationData[3]) {
    calibrationData[3] = y;
    changed = true;
  }

  if(z < calibrationData[4]) {
    calibrationData[4] = z;
    changed = true;
  }
  if(z > calibrationData[5]) {
    calibrationData[5] = z;
    changed = true;
  }

  if (changed && !done) {
    Serial.println("CALIBRATING... Keep moving your sensor around.");
    c = millis();
  }
    t = millis();
  
  
  if ( (t - c > 5000) && !done) {
    done = true;
    Serial.println("DONE. Copy the line below and paste it into your projects sketch.);");
    Serial.println();
      
    Serial.print("compass.setCalibration(");
    Serial.print(calibrationData[0]);
    Serial.print(", ");
    Serial.print(calibrationData[1]);
    Serial.print(", ");
    Serial.print(calibrationData[2]);
    Serial.print(", ");
    Serial.print(calibrationData[3]);
    Serial.print(", ");
    Serial.print(calibrationData[4]);
    Serial.print(", ");
    Serial.print(calibrationData[5]);
    Serial.println(");");
  }
}
