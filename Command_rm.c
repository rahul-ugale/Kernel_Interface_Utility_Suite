#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/utsname.h>

// ./rmx        filename
//  argv[0]      argv[1]
//  argc = 2
/*
    call the system call uname
    print the information from utsname struture

 
*/
int main(int argc , char *argv[])
{
    if(argc != 2)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use command as : ./rmxFILENAME\n");


        return -1;
    }

    
    if(access(argv[1] , F_OK)== 0)
    {
        unlink(argv[1]);
        return 0;
    }
    else
    {
       printf("Unable to delete file as no such file exists");
    }

   
    
    return 0;
}