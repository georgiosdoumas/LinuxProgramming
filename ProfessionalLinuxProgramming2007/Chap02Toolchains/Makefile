# Makefilefull to build Toolchains examples
# use it : make -F Makefilefull all 
#          make -F Makefilefull clean

CFLAGS := -Wall -pedantic-errors

all: hello goodbye goodbye_shared trig

clean:
        -rm -rf *.o *.so hello goodbye goodbye_shared trig

hello: hello.c


goodbye: main.o message.o
        $(CC) $(CFLAGS) -o goodbye main.o message.o


goodbye_shared: libmessage.so main.o
        $(CC) $(CFLAGS) -o goodbye_shared main.o libmessage.so

libmessage.so:
        gcc -fPIC -o message.o -c message.c
        gcc -shared -o libmessage.so message.o


trig:
        $(CC) $(CFLAGS) -lm -o trig trig.c
