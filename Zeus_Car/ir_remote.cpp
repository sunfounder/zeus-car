#include "ir_remote.h"
#include <IRLremote.h>

CNec IRLremote;

void irBegin() {
  if (!IRLremote.begin(IR_RECEIVER_PIN))
    Serial.println(F("You did not choose a valid pin."));
}

uint8_t irRead() {
  long result = IR_KEY_ERROR;
  if (IRLremote.available()) {
    auto data = IRLremote.read();
    result = data.command;
  }
  return result;
}

