CC=gcc
CFLAGS=-Wall -pedantic

numconverter: main.c
	$(CC) -o numconverter main.c $(CFLAGS)
clean:
	rm -f numconverter