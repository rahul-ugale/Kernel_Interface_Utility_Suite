#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


// ./touchX   FileName
//  argv[0]   argv[1]   
//  argc = 2
/*
    accept file name from command line
    check whether file is existing ir not 
    if existing print on console
    if not  then :
    display no such file or dorectory
 
*/

#define MAX_BUFFER_SIZE  1024
int main(int argc , char *argv[])
{
    if(argc != 2)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use command as : ./catx FILENAME\n");


        return -1;
    }

    if(access(argv[1] , F_OK) != 0)
    {
        printf("cat: %s: No such file or directory\n",argv[1]);
        return -1;
    }
    else
    {
        int fd = 0;
        fd = open(argv[1], O_RDONLY);

        if(fd < 0)
        {
            printf("Error: unable to open file \n");
            return -1;
        }

        char Buffer[MAX_BUFFER_SIZE] = {'\0'};
        int iRet = 0;

        while((iRet = read(fd , Buffer , sizeof(Buffer)))!= 0)
        {
            write(1,Buffer,iRet);
        }
        printf("\n");
        close(fd);
    }

        
        
    return 0;
}