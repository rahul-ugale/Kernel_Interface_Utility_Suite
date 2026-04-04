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
    if existing just return 2
    if not  then :
    create that file
 
*/

int main(int argc , char *argv[])
{
    if(argc != 2)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use command as : ./touchX FILENAME\n");


        return -1;
    }

    if(access(argv[1] , F_OK)== 0)
    {
        return 0;
    }
    else
    {
        creat(argv[1],0777);
    }

        
        
    return 0;
}