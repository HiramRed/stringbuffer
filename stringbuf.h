#ifndef __STRINGBUF_H__
#define __STRINGBUF_H__

typedef unsigned int uint_16;

typedef struct _stringbuf
{
    char * buf;         // buffer
    uint_16 _len;       // content length
    uint_16 _size;      // buffer memory capacity
} stringbuf;

// return a new stringbuf pointer, cap is the initial capacity of buffer
stringbuf *
stringbuf_new(uint_16 cap);

// return a new stringbuf pointer, buf append default value, and initial capacity
stringbuf *
stringbuf_from(char * str, uint_16 size);

// append string to buffer
void
stringbuf_append(stringbuf * strb, char * str, uint_16 n);

// return a copy array of buffer
char *
stringbuf_array(stringbuf * strb);

// return the length of the buffer
uint_16
stringbuf_len(stringbuf * strb);

// free the memery resource
void
stringbuf_free(stringbuf * strb);

#endif
