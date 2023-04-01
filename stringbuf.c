#include "stringbuf.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static
uint_16
memcpy0(register char * dst, register char *src, uint_16 n)
{
    uint_16 l = 0;
    while (*src && l < n) {
        *dst++ = *src++;
        l++;
    }
    return l;
}

stringbuf *
stringbuf_new(uint_16 cap)
{
    stringbuf *strb = malloc(sizeof(stringbuf));
    if (strb != NULL) {
        strb->buf = (char *)malloc(sizeof(char) * cap);
        strb->_len = 0;
        strb->_size = strb->buf ? cap : 0;
    }
    return strb;
}

stringbuf *
stringbuf_from(char * str, uint_16 size)
{
    uint_16 len = strlen(str);
    int cap = len < size ? size : cap;
    stringbuf *strb = stringbuf_new(cap);
    stringbuf_append(strb, str, len);
    return strb;
}

inline
static
void grow(stringbuf * strb, uint_16 new_size)
{
    if (new_size <= 0) return;
    char * old = strb->buf;
    char * new_buf = (char *)malloc(sizeof(char) * new_size);
    strb->buf = new_buf;
    memcpy(new_buf, old, strb->_len);
    strb->_size = new_size;
    free(old);
}

inline
static
uint_16 calc_capacity(uint_16 size, uint_16 inc, uint_16 expect)
{
    inc = inc > expect ? inc : expect;
    inc = (inc <= UINT_MAX - size) ? inc : UINT_MAX - size;
    return size + inc;
}

inline
static
void ensure_capacity(stringbuf * strb, uint_16 inc, uint_16 expect)
{
    uint_16 rest = strb->_size - strb->_len;
    if (rest >= expect) return;
    int new_size = calc_capacity(strb->_size, inc, expect);
    grow(strb, new_size);
}

void
stringbuf_append(stringbuf * strb, char * str, uint_16 n)
{
    if (strb == NULL || str == NULL) return;
    int len = strlen(str), expl = len < n ? len : n;
    ensure_capacity(strb, (strb->_size >> 1), expl);
    memcpy(strb->buf + strb->_len, str, expl);

    strb->_len += expl;
}

char *
stringbuf_array(stringbuf * strb)
{
    if (strb == NULL) return NULL;
    char *src = strb->buf, *dst;
    int n = strb->_len;
    dst = (char *)malloc(sizeof(n + 1));
    memcpy(dst, src, strb->_len);
    dst[n] = 0;
    return dst;
}

uint_16
stringbuf_len(stringbuf * strb)
{
    return strb ? strb->_len : 0;
}

void
stringbuf_free(stringbuf * strb)
{
    if (strb == NULL) return;
    free(strb->buf);
    strb->buf = NULL;
    free(strb);
}
