#include <sys/utsname.h>
#include <stdio.h>
//from paragraph 6.2.3. Finding and Setting Basic System Information , 
//trying to use uname() function for simple outputs
int main(void)
{
    struct utsname uname_Buf;
    int status;
    status=uname(&uname_Buf);
    printf("%d is the return value of calling  uname()\n",status);
    printf("%s \n",uname_Buf.sysname);
    printf("%s \n",uname_Buf.release);
    printf("%s \n",uname_Buf.version);
    printf("%s \n",uname_Buf.machine);
    printf("%s \n",uname_Buf.nodename);
    //printf("%s \n",uname_Buf.domainname);  //compiler says that struct utsname has no member domainname
    //and checking the file /usr/include/linux/utsname.h,I see it is true. Only struct new_utsname has member domainname
    return 0;
}
