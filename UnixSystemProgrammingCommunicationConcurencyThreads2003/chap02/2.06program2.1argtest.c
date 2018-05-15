/*A program that takes a single string as its command-line argument
and calls makeargv to create an argument array. */

#include <stdio.h>
#include <stdlib.h>
int makeargv(const char *s, const char *delimiters, char ***argvp);
void freemakeargv(char **argv);

int main(int argc, char *argv[])
{
   char delim[] = " _\t";
   int i;
   char **myargv;  /* memory will be allocated dynamicaly, and has to bee freed before exit */
   int numtokens;

   if (argc != 2) {
      fprintf(stderr, "Usage: \n%s \" string of several words  \"\n", argv[0]);
      return 1;
   }
   if ((numtokens = makeargv(argv[1], delim, &myargv)) == -1) /* nakeargv() allocates memory for myargv, it may fail */
   {
      fprintf(stderr, "Failed to construct an argument array for %s\n", argv[1]);
      return 1;
   }
   printf(" The argument array contains:\n");
   for (i = 0; i < numtokens; i++)
      printf("%d:%s\n", i, myargv[i]);
   freemakeargv(myargv);    /* do not forget to free the memory! */
   return 0;
 }
 /*
 /usr/bin/gcc -Wall -std=c99 -o 2.06Program2.1argtest 2.06program2.2makeargv.c 2.06example2.19freemakeargv.c 2.06program2.1argtest.c

 ./2.06Program2.1argtest 
 ./2.06Program2.1argtest "  hello    world of C"
 */
