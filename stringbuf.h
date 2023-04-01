#ifndef __STRINGBUF_H__
#define __STRINGBUF_H__

typedef unsigned int uint_16;

typedef struct _stringbuf
{
    char * buf;
    uint_16 _len;
    uint_16 _size;
} stringbuf;

stringbuf *
stringbuf_new(uint_16 cap);

stringbuf *
stringbuf_from(char * str, uint_16 size);

void
stringbuf_append(stringbuf * strb, char * str, uint_16 n);

char *
stringbuf_array(stringbuf * strb);

uint_16
stringbuf_len(stringbuf * strb);

void
stringbuf_free(stringbuf * strb);

#endif
