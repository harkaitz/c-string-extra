#ifndef STR_STR2KEY_H
#define STR_STR2KEY_H

#include <string.h>

static inline
int str2key(char const *_keys[], int _keysn, char const *_key) {
    int i;
    for (i=0; i<_keysn && strcmp(_key, _keys[i]); i++) {}
    return i;
}

#endif
