#include "DictPrinter.h"

DictPrinter dprint = DictPrinter();

void setup() {
    Serial.begin(9600);
}

void loop() {
    dprint.start();
    dprint.addCharItem("char", 100); 
    dprint.addIntItem("value", 100); 
    dprint.addStrItem("name", "bob");
    dprint.addLongItem("long", 45000);
    dprint.addDblItem("double", 103.2345);
    dprint.addFltItem("float", 12.34567);
    dprint.stop();
    Serial.println();
    delay(100);
}
