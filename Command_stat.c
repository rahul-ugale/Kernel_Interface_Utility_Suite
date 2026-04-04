#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>


// ./stat   FileName
//  argv[0]   argv[1]   
//  argc = 2
/*
    accept file name from command line
    call access to ceck existence of file
    call stat system call to get files metadata
    display the metadata

*/

int main(int argc , char *argv[])
{
    if(argc != 2)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use command as : ./statx FILENAME\n");


        return -1;
    }

    if(access(argv[1] , F_OK)== 0)
    {
        struct stat sobj;
        int iRet =0;

        iRet = stat(argv[1] , &sobj);
        if(iRet == -1)
        {
            printf("unable to fetch statistical information\n");
            return -1;
        }
        printf("filename : %s\n",argv[1]);
        printf("FIle size : %ld\n",(long)sobj.st_size);
        printf("INode number : %ld",(long)sobj.st_ino);
    }
    else
    {
        printf("Error : file not found\n");
        return -1;
    }

        
        
    return 0;
}