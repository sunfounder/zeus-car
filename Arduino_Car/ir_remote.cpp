#include "ir_remote.h"
#include <IRremote.h>

int irReceiverPin = 10;
IRrecv irrecv(irReceiverPin);

void irBegin() {
  irrecv.enableIRIn();
}

uint8_t irRead() {
  long result = IR_KEY_ERROR;
  if (irrecv.decode()) {
    result = irrecv.decodedIRData.command;
  }
  irrecv.resume();
  return result;
}
