#include <stdlib.h>
#define PATH_DELIMITERS ":"
int makeargv(const char *s, const char *delimiters, char ***argvp); /* defined in 2.06program2.2makeargv.c */
char **getpaths(void) 
{
   char **myargv;
   char *path;
   path = getenv("PATH");
   if (makeargv(path, PATH_DELIMITERS, &myargv) == -1)
      return NULL;
   else
      return myargv;
}
