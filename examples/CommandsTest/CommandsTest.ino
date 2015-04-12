#include "Ai_DictPrinter.h"

DictPrinter dprint = DictPrinter();

void setup() {
    Serial.begin(9600);
}

void loop() {
    dprint.start();
    dprint.addCharItem(F("char"), 100); 
    dprint.addIntItem(F("value"), 100); 
    dprint.addStrItem(F("name"), "bob");
    dprint.addLongItem(F("long"), 45000);
    dprint.addDblItem(F("double"), 103.2345);
    dprint.addFltItem(F("float"), 12.34567);
    dprint.stop();
    Serial.println();
    delay(100);
}
