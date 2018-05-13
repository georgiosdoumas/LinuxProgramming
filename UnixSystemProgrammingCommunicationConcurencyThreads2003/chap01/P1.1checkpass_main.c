#include <stdio.h>

int checkpass(char* inp);

int main(int argc, char** argv)
{
   int checkrslt;
   checkrslt = checkpass(argv[1]);
   fprintf(stderr, "checkrslt = %d\n", checkrslt);
   if (checkrslt)
      fprintf(stderr, "Password %s is correct!\n",argv[1]);
   else
      fprintf(stderr, "Password %s is not correct!\n", argv[1]);
   return 0;
}

// /usr/bin/gcc -Wall -o P1.1checkpass_main P1.1checkpass.c P1.1checkpass_main.c
