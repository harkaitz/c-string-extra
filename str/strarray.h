#ifndef STRARRAY_H
#define STRARRAY_H

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef int (*strcmp_f) (const char *s1, const char *s2);

static inline
void streq2map(char *_i[], int _o_sz, char const *_o[_o_sz]) {
    int f,t; char *v1,*v2;
    for (f=0, t=0; _i[f] && t<(_o_sz-3); f++) {
        v1 = _i[f];
        if ((v2 = strchr(v1, '='))) *(v2++) = '\0';
        _o[t++] = v1;
        _o[t++] = v2;
    }
    _o[t] = NULL;
}

static inline
char const *strmap_get_val(char const *_a[], const char _key[], strcmp_f _cmp, char const *_def) {
    if (_key) {
        for (char const **k = _a; *k; k+=2) {
            if (*(k+1) && !_cmp(_key,*k)) {
                return *(k+1);
            }
        }
    }
    return _def;
}

static inline
char const *strmap_get_key(char const *_a[], const char _val[], strcmp_f _cmp, char const *_def) {
    if (_val) {
        for (char const **k = _a; *k; k+=2) {
            if (*(k+1) && !_cmp(_val,*(k+1))) {
                return *k;
            }
        }
    }
    return _def;
}



#endif
