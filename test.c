#include <assert.h>
#include <stdio.h>
#include "stringbuf.h"

#define SUCCESS(s) \
    do { \
        printf("[1;32m%s[0m\n", s); \
    } while (0)

int main()
{   
    stringbuf *strb = stringbuf_from("Hello", 10);
    assert(strb->_len == 5);
    assert(strb->_size == 10);

    stringbuf_append(strb, "H", 100);
    assert(strb->_len == 6);
    assert(strb->_size == 10);

    stringbuf_append(strb, "Hello", 2);
    assert(strb->_len == 8);
    assert(strb->_size == 10);

    stringbuf_append(strb, "Hello", 100);
    assert(strb->_len == 13);
    assert(strb->_size == 15);

    stringbuf_append(strb, "1234567890", 100);
    assert(strb->_len == 23);
    assert(strb->_size == 25);

    printf("final len: %d\n", strb->_len);
    printf("final size: %d\n", strb->_size);


    stringbuf_free(strb);
    strb = NULL;

    SUCCESS("Test passed!!!");
    return 0;
}
