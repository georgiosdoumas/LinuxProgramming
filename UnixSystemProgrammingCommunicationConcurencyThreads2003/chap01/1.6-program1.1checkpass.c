#include <stdio.h>
#include <string.h>
int checkpass(void)
{
   int x;
   char a[6];  /* since the password is the string : mypass , only 6 characters are needed */
   x = 0;   /* default value for failure */
   fprintf(stderr,"a at %p and\nx at %p\n", (void *)a, (void *)&x);
   printf("Enter a short word: ");
   scanf("%s", a);   /* problematic */
   /* scanf("%6s",a);   that is a good method to avoid buffer overflow */
   if (strcmp(a, "mypass") == 0)
      x = 1;
   return x;
}
int main(void)
{
  int control;
  fprintf(stderr , " control mem address at %p \n", &control);
  control=checkpass();
  if(control==1)
    printf("Match , you are accepted\n");
  else printf("No match,function returned %d \n",control);
  return 0;
}
