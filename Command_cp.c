#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


// ./cpX     Source.txt   Dest.txt
//  argv[0]   argv[1]     argv[3]
//  argc = 3
/*
    open source file
    create destination file
    read data from source
    write into dest
    close file
*/

#define MAX_BUFFER_SIZE 1024
int main(int argc , char *argv[])
{
    if(argc != 3)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use command as : ./cpx SOURCEFILEname DESTFILEname\n");


        return -1;
    }

        int fdSrc = 0 , fdDest = 0 , iRet = 0;
        char Buffer[MAX_BUFFER_SIZE];

        memset(Buffer, '\0' , sizeof(Buffer));



        fdSrc = open(argv[1] ,O_RDONLY);

        if(fdSrc < 0)
        {
            printf("Error : Unable to open sourcefile : %s\n" ,argv[1]);
            return -1;
        }

        fdDest = creat(argv[2], 0777);
        if(fdDest < 0)
        {
            printf("Error : Unable to open destinationfile : %s\n" ,argv[2]);
            close(fdSrc);
            return -1;
        }

        while(iRet = read(fdSrc,Buffer,sizeof(Buffer) != 0))
        {
            write(fdDest,Buffer,iRet);
            memset(Buffer, '\0' , sizeof(Buffer));
        }

        printf("file copy succesfully done");
        
    return 0;
}