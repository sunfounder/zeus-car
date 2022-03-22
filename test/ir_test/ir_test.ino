#include <IRremote.h>

#define IR_KEY_POWER 0x45
#define IR_KEY_MODE 0x46
#define IR_KEY_MUTE 0x47

#define IR_KEY_PLAY_PAUSE 0x44
#define IR_KEY_BACKWARD 0x40
#define IR_KEY_FORWARD 0x43

#define IR_KEY_EQ 0x07
#define IR_KEY_MINUS 0x15
#define IR_KEY_PLUS 0x09

#define IR_KEY_0 0x16
#define IR_KEY_CYCLE 0x19
#define IR_KEY_U_SD 0x0D

#define IR_KEY_1 0x0C
#define IR_KEY_2 0x18
#define IR_KEY_3 0x5E

#define IR_KEY_4 0x08
#define IR_KEY_5 0x1C
#define IR_KEY_6 0x5A

#define IR_KEY_7 0x42
#define IR_KEY_8 0x52
#define IR_KEY_9 0x4A

#define IR_KEY_ERROR 0x00

int pin = 10;
IRrecv irrecv = IRrecv(pin);

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  int result = IR_KEY_ERROR;
  if (irrecv.decode()) {
    result = irrecv.decodedIRData.command;
    Serial.print("0x");
    Serial.print(result, HEX);
    Serial.print(" ");
    switch (result) {
      case IR_KEY_POWER:
        Serial.println("POWER");
        break;
      case IR_KEY_MODE:
        Serial.println("MODE");
        break;
      case IR_KEY_MUTE:
        Serial.println("MUTE");
        break;
      case IR_KEY_PLAY_PAUSE:
        Serial.println("PLAY_PAUSE");
        break;
      case IR_KEY_BACKWARD:
        Serial.println("BACKWARD");
        break;
      case IR_KEY_FORWARD:
        Serial.println("FORWARD");
        break;
      case IR_KEY_EQ:
        Serial.println("EQ");
        break;
      case IR_KEY_MINUS:
        Serial.println("MINUS");
        break;
      case IR_KEY_PLUS:
        Serial.println("PLUS");
        break;
      case IR_KEY_0:
        Serial.println("0");
        break;
      case IR_KEY_CYCLE:
        Serial.println("CYCLE");
        break;
      case IR_KEY_U_SD:
        Serial.println("U_SD");
        break;
      case IR_KEY_1:
        Serial.println("1");
        break;
      case IR_KEY_2:
        Serial.println("2");
        break;
      case IR_KEY_3:
        Serial.println("3");
        break;
      case IR_KEY_4:
        Serial.println("4");
        break;
      case IR_KEY_5:
        Serial.println("5");
        break;
      case IR_KEY_6:
        Serial.println("6");
        break;
      case IR_KEY_7:
        Serial.println("7");
        break;
      case IR_KEY_8:
        Serial.println("8");
        break;
      case IR_KEY_9:
        Serial.println("9");
        break;
    }
  }
  irrecv.resume();
  delay(100);
}