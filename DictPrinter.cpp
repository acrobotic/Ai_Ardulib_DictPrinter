#include "DictPrinter.h"

DictPrinter::DictPrinter() {
    numberOfItems = 0;
}

void DictPrinter::start() {
    Serial << "{";
    numberOfItems = 0;
}

void DictPrinter::stop() {
    Serial << "}" << endl;
    numberOfItems = 0;
}

void DictPrinter::addEmptyItem(const __FlashStringHelper* key) {
    addKey(key);
    Serial << "\"" << "\"";
}

void DictPrinter::addCharItem(const __FlashStringHelper* key, char value) {
    addKey(key);
    Serial << "\"" << value << "\"";
}

void DictPrinter::addIntItem(const __FlashStringHelper* key, int value) {
    addKey(key);
    Serial <<  _DEC(value);
}

void DictPrinter::addLongItem(const __FlashStringHelper* key, long value) {
    addKey(key);
    Serial << _DEC(value); 
}

void DictPrinter::addStrItem(const __FlashStringHelper* key, char *value) {
    addKey(key);
    Serial << "\"" << value << "\"";
}

void DictPrinter::addStrItem(const __FlashStringHelper* key, const __FlashStringHelper *value) {
    addKey(key);
    Serial << "\"" << value << "\"";
}

void DictPrinter::addDblItem(const __FlashStringHelper* key, double value) {
    char valueStr[DP_STR_LEN];
    addKey(key);
    //dtostre(value,valueStr,DP_DOUBLE_PREC,0);
    sprintf(valueStr, "%1.5f", value); 
    Serial <<  valueStr; 
}

void DictPrinter::addFltItem(const __FlashStringHelper* key, float value) {
    char valueStr[DP_STR_LEN];
    addKey(key);
    //dtostre((double)value, valueStr, DP_DOUBLE_PREC,0);
    sprintf(valueStr, "%1.5f", value); 
    Serial <<  valueStr; 
}

void DictPrinter::addLongTuple(const __FlashStringHelper* key, uint8_t num, ...) {
    va_list args; 
    long value;
    addKey(key);
    Serial << "(";
    va_start(args,num);
    for (uint8_t i=0; i<num; i++) {
        value = va_arg(args,long);
        Serial << _DEC(value);
        if (i < num-1) {
            Serial << ",";
        }
    }
    Serial << ")";
}

int DictPrinter::len() {
    return numberOfItems;
}

void DictPrinter::addKey(const __FlashStringHelper* key) {
    if (numberOfItems > 0) {
        Serial << ",";
    }
    Serial << "\"" << key << "\"" << ":"; 
    numberOfItems++;
}
