#ifndef DICTPRINTER_H
#define DICTPRINTER_H
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
        void addEmptyItem(char *key);
        void addCharItem(char *key, char value);
        void addStrItem(char *key, char *value);
        void addFltItem(char *key, float value);
        void addDblItem(char *key, double value);
        void addIntItem(char *key, int value);
        void addLongItem(char *key, long value);
        void addLongTuple(char *key, uint8_t num, ...);
        int len();
    private:
        char *output;
        int numberOfItems;
        void addKey(char *key);
};
#endif
