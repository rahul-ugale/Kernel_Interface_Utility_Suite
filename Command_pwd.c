#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


// ./pwdx  print working directory 
//  argv[0]   
//  argc = 1
/*
    call the system call get cwd
    print the result of get cwd

 
*/

int main(int argc , char *argv[])
{
    char Buffer[1024] = {'\0'};
    getcwd(Buffer,sizeof(Buffer));

    printf("%s\n",Buffer);
        
        
    return 0;
}