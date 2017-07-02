# Makefile to build Toolchains examples

CFLAGS := -Wall -pedantic-errors

all: hello goodbye goodbye_shared trig

clean:
	-rm -rf *.o *.so *.s hello goodbye goodbye_shared trig

hello: 

goodbye: message.o main.o
	$(CC) $(CFLAGS) -o goodbye main.o message.o
    
libmessage.so:
	gcc -fPIC -o message.o -c message.c
	gcc -shared -o libmessage.so message.o

goodbye_shared: libmessage.so main.o
	$(CC) $(CFLAGS) -o goodbye_shared main.o libmessage.so

trig:
	$(CC) $(CFLAGS)  -g -o trig trig.c -lm
