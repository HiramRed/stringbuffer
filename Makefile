test::test.c stringbuf.c
	cc -o test test.c stringbuf.c

clean:
	\rm -rf test
