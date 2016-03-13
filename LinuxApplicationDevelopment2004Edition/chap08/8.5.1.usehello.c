/* 8.5.1.usehello.c */
#include "8.5.1.libhello.h"
int main (void) 
{
    print_hello("libhello.so.0.0");
    return 0;
}

/*
*********
Suppose that all the 3 files 8.5.1.* are in the some directory chap08, and you are in this directory.
Then with the following commands you can build a shared library :
chap08>$ gcc -fPIC -Wall -g -c -o libhello.o 8.5.1.libhello.c
chap08>$ gcc -g -shared -Wl,-soname,libhello.so.0 -o libhello.so.0.0 libhello.o -lc
chap08>$ ln -sf libhello.so.0.0 libhello.so.0
chap08>$ ln -sf libhello.so.0 libhello.so
chap08>$ gcc -Wall -g -c 8.5.1.usehello.c -o 8.5.1.usehello.o
chap08>$ gcc -g -o 8.5.1.usehello 8.5.1.usehello.o -L. -lhello
and run the program that uses the library like this :
chap08>$ LD_LIBRARY_PATH=$(pwd) ./8.5.1.usehello 
********
*/
