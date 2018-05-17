/* Expanded version of Example 3.6 twoprocs.c of the book, 
incorporating the idea of changing the x variable from Example 3.5 simplefork.c */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void)
{
   int x = 0;
   pid_t childpid;
   printf("Before calling fork(), x is %d and its memory location is %p \n",x, &x);
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
  Execution gives : 
./3.3example3.6twoprocs 
Before calling fork(), x is 0 and its memory location is 0x7ffeb1922ff8 
I am parent 11681 my parent is 3662, my x variable is -1 at memory location 0x7ffeb1922ff8
 here we have x = -1
I am child 11682  my parent is 11681, my x variable is 1 at memory location 0x7ffeb1922ff8
 here we have x = 1

So how is it possible to see the same memory address 0x7ffeb1922ff8 ? I do not understand it.
I thought that child process would have a separate address space
*/

