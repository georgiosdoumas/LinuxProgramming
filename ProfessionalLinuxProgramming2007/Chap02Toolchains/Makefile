# Makefilefull to build Toolchains examples
# use it : make -F Makefilefull all 
#          make -F Makefilefull clean
# the trig is build with -g option for debugging symbols
# We could do that to any of the other target files 

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
        $(CC) $(CFLAGS) -g -lm -o trig trig.c
