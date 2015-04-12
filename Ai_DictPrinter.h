#ifndef AI_DICTPRINTER_H
#define AI_DICTPRINTER_H
#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
#include <stdlib.h> 
#include "Streaming.h"

#define DP_DOUBLE_PREC 12
#define DP_STR_LEN 30

class DictPrinter {
    public:
        DictPrinter();
        void start();
        void stop();
        void addEmptyItem(const __FlashStringHelper* key);
        void addCharItem(const __FlashStringHelper* key, char value);
        void addStrItem(const __FlashStringHelper* key, char *value);
        void addStrItem(const __FlashStringHelper* key, const __FlashStringHelper *value);
        void addFltItem(const __FlashStringHelper* key, float value);
        void addDblItem(const __FlashStringHelper* key, double value);
        void addIntItem(const __FlashStringHelper* key, int value);
        void addLongItem(const __FlashStringHelper* key, long value);
        void addLongTuple(const __FlashStringHelper* key, uint8_t num, ...);
        int len();
    private:
        char *output;
        int numberOfItems;
        void addKey(const __FlashStringHelper* key);
};
#endif
