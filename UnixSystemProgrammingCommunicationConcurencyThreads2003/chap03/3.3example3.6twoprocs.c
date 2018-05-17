#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void)
{
   int x = 0;
   pid_t childpid;
   childpid = fork();
   if (childpid == -1)
   {
      perror("Failed to fork");
      return 1;
   }
   if (childpid == 0) {  /* child code increases x from 0 to 1 */
     ++x;
     printf("I am child %ld my parent is %ld, my x variable is %d at memory location %p\n",(long)getpid(),(long)getppid(),x,&x);
   }

   else  { /* parent code decreases x  from 0 to -1 */
     --x;
     printf("I am parent %ld my parent is %ld, my x variable is %d at memory location %p\n",(long)getpid(),(long)getppid(),x,&x);
   }
   printf(" here we have x = %d\n",x);
   return 0;
}
/*
gcc -Wall -std=c11 -o 3.3example3.6twoprocs 3.3example3.6twoprocs.c

./3.3example3.6twoprocs 
I am parent 10023 my parent is 3662, my x variable is -1 at memory location 0x7ffcd6159b28
 here we have x = -1
I am child 10024 my parent is 10023, my x variable is 1 at memory location 0x7ffcd6159b28
 here we have x = 1

*/

