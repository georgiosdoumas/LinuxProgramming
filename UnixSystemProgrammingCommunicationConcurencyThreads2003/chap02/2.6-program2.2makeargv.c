#include <errno.h>
#include <stdlib.h>
#include <string.h>
int makeargv(const char *s, const char *delimiters, char ***argvp) 
{
   int error;  int i;
   int numtokens;
   const char *snew;
   char *t;
   if ((s == NULL) || (delimiters == NULL) || (argvp == NULL)) 
	{ errno = EINVAL; return -1; }
   *argvp = NULL; /* so that a failed call to malloc,will leave it NULL */
	  /* now we consume any initial delimiters characters of input s and move our pointer after them */
   snew = s + strspn(s, delimiters);       /* snew points to the real start of string skipping any initial delimiters */
   if ((t = malloc(strlen(snew) + 1)) == NULL)
      return -1;  /* if allocation of memory for the temporary string failed, terminate program */
   strcpy(t, snew);
   numtokens = 0;
   if (strtok(t, delimiters) != NULL)     /* then count the number of tokens in s */
      for (numtokens = 1; strtok(NULL, delimiters) != NULL; numtokens++) ;
      /* next,create argument array for ptrs to the tokens */
   if ((*argvp = malloc((numtokens + 1)*sizeof(char *))) == NULL) 
    {
      error = errno;
      free(t);
      errno = error;
      return -1;
    }
      /* now insert pointers-to-tokens into the argument array */
   if (numtokens == 0)  free(t);
    else 
    {
      strcpy(t, snew);
      **argvp = strtok(t, delimiters);
      for (i = 1; i < numtokens; i++)
          *((*argvp) + i) = strtok(NULL, delimiters);  
    }
    *((*argvp) + numtokens) = NULL;             /* append final NULL pointer in the array of pointers-to-tokens */
    return numtokens;
}
