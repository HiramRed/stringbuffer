# stringbuffer
An expandable stringbuffer implemented by C language

## example:
``` c
    stringbuf *strb = stringbuf_new(10);        // default capacity
    stringbuf_append(strb, "Hello");            // append "Hello" into buffer
    char * str = stringbuf_array(strb);         // return a copy of buffer

    stringbuf *strb0 = string_from("Hello", 100);   // initial capacity
```
