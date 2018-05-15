#include <stdlib.h>
/* The following function frees all the memory associated with an argument array that was allocated by makeargv. */
void freemakeargv(char **argv)
{
   if (argv == NULL)
      return;
   if (*argv != NULL)
      free(*argv);
   free(argv);
}
