#if 0 /*
hcc -lcrypto "$0" "$@"
*/
#endif

#ifndef _STR_BASE64_H_
#define _STR_BASE64_H_

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <stdbool.h>
#include <string.h>

/* (In OpenSSL: -lcrypto) */
extern int EVP_EncodeBlock(unsigned char *t, const unsigned char *f, int n);
extern int EVP_DecodeBlock(unsigned char *t, const unsigned char *f, int n);

static inline char *
encode_base64(const void *_i, int _opt_isz) {
    int isz = (_opt_isz>=0)?_opt_isz:(int)strlen(_i);
    int pl,ol; char *o;
    pl = 4*((isz+2)/3);
    o = malloc(pl+1);
    if (o == NULL) {
        syslog(LOG_ERR, "encode_base64: Can't allocate memory.");
        return NULL;
    }
    ol = EVP_EncodeBlock((unsigned char *)o, _i, isz);
    if (ol != pl) {
        syslog(LOG_ERR, "encode_base64: Predicted size %d but we got %d.", pl, ol);
        free(o);
    }
    return o;
}

static inline bool
decode_base64(const char *_i, int _opt_isz, char **_o, size_t *_opt_osz) {
    int isz = (_opt_isz>=0)?_opt_isz:(int)strlen(_i);
    int pl,ol; char *o;
    pl = 3*isz/4;
    o = malloc(pl+1);
    if (o == NULL) {
        syslog(LOG_ERR, "decode_base64: Can't allocate memory.");
        return NULL;
    }
    ol = EVP_DecodeBlock((unsigned char*)o, (unsigned char *)_i, isz);
    if (pl != ol) {
        syslog(LOG_ERR, "base64: Decode predicted %d but we got %d.", pl, ol);
        free(o);
        return false;
    }
    *_o   = o;
    if (_opt_osz) {
        *_opt_osz = ol;
    }
    return true;
}


#endif

#if defined(FLYCHECK) || defined(_HCC_)
int main (void) {
    char *encoded, *decoded;
    openlog("BASE64-TEST", LOG_PERROR, LOG_USER);
    const char *message = "Hello World!!!!";
    printf("Message: %s\n", message);
    encoded = encode_base64(message, -1);;
    printf("Encoded: %s\n", encoded);
    decode_base64(encoded, -1, &decoded, NULL);
    printf("Decoded: %s\n", decoded);
    if (!strcmp(message, decoded)) {
        printf("Test base64.h OK\n");
        return 0;
    } else {
        printf("Test base64.h FAIL\n");
        return 1;
    }
}
#endif
/**l*
 * MIT License
 * 
 * Copyright (c) 2023 Harkaitz Agirre, harkaitz.aguirre@gmail.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **l*/
