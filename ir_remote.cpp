#include "ir_remote.h"
#include <IRremote.h>

IRrecv irrecv;

IR_Remote::IR_Remote(int pin) {
  this->pin = pin;
  irrecv = IRrecv(pin);
}

void IR_Remote::begin() {
  irrecv.enableIRIn();
}

int IR_Remote::read() {
  int result = IR_KEY_ERROR;
  if (irrecv.decode()) {
    result = irrecv.decodedIRData.command;
  }
  irrecv.resume();
  return result;
}
