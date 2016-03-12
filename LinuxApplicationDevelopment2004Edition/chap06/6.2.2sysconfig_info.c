#include <unistd.h>
#include <stdio.h>
//from paragraph 6.2.2. Discovering Run-Time Capabilities ,
//trying to use sysconf() in a simple way,and get familiar with it
int main(void)
{
    printf("%ld are the (visible to programms) kernel internal clockticks/sec\n",sysconf(_SC_CLK_TCK));
    printf("%ld are the max number of Cstandard I/O streams a process can have open at once\n",sysconf(_SC_STREAM_MAX));
    printf("%ld (bytes) is the max length of cmd-args and env vars used by any of the exec() functs\n",sysconf(_SC_ARG_MAX));
    printf("%ld are the max number of files a process can have open at once\n",sysconf(_SC_OPEN_MAX));
    printf("%ld (bytes) is the size of a single page in memory (allocated after a user request)\n",sysconf(_SC_PAGESIZE));
    printf("%ld (bytes) is the length of maximum line required to be handled by text apps\n",sysconf(_SC_LINE_MAX));
    return 0;
}
