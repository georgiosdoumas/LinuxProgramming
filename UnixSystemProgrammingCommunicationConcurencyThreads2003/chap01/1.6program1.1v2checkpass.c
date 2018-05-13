#include <stdio.h>
#include <string.h>
/* This programm will be called by the script 1.6program1.1v2checkpass.sh, for automatic results */
int checkpass(char * input2check)
{
   int x;
   char a[9];
   x = 0;   /* default value for failure */
   fprintf(stderr,"a at %p and\nx at %p\n", (void *)a, (void *)&x);
   sscanf(input2check, "%s", a);   /* danger of characters from a[] to get in memory places of x*/
   /* sscanf(input2check, "%9s",a);   that is a good method to avoid buffer overflow */
   printf("    Received string %s for checking\n",a); /* debugging message */
   if (strcmp(a, "mypass") == 0)
      x = 1;
   return x;  /* So now we can naively suppose that x can only have a 0 or a 1 value? WRONG! */
}
int main(int argc , char ** argv)
{
  int control;
  control=checkpass(argv[1]);
  if(control != 0) /* we naively expect that 0 is failure,so we think !=0 is 1 , meaning success */
    printf("Match ,%d ,  you are accepted\n",control);
  else printf("No match,function returned %d \n",control);  /* we can get the whole ASCII set here! */
  return 0;
}
