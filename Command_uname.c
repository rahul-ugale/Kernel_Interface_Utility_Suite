#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/utsname.h>

// ./unamex  print working directory 
//  argv[0]   
//  argc = 1
/*
    call the system call uname
    print the information from utsname struture

 
*/
int main(int argc , char *argv[])
{
    struct utsname obj;

    int iRet = 0;

    iRet = uname(&obj);

    if(iRet == -1)
    {
        printf("Error : Unable to fetch system information\n");
        return -1;
    }

    printf("Operating system name : %s\n",obj.sysname);
    printf("Node name : %s\n",obj.nodename);
    printf("Release : %s\n",obj.release);
    

    return 0;
}