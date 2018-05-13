/* implementing again the programs of 1.6.1, but keeping seperate file for the function, and seperate file for the main */

#include <stdio.h>
#include <string.h>

int checkpass(char* inputpasswd)
{
  int result = 0;
  char passwd[9];
  fprintf(stderr, "passwd buffer-chararray at\n memory location %p\n result at  %p \n",(void*)passwd,(void*)&result );
  /*printf("Enter a short word: ");
  scanf("%s",passwd); */
  sscanf(inputpasswd, "%s",passwd);  /* can cause bad passwords to be accepted */
  // sscanf(inputpasswd, "%9s",passwd);  // that is a better way , to avoid buffer overflows 
  if (strcmp(passwd, "my_passW") == 0)  result = 1;
  return result;
}
