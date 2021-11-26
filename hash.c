#include <string.h>

unsigned int naive_hash(char* buf) {
    unsigned int value = 0;

    for(int i = 0; i < strlen(buf); i++) {
        value += (int) buf[i];
    }

    return value;
}