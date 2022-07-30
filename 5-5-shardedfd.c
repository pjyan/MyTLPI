#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    int fd;
    int new_fd;
    int flag =  O_RDWR | O_CREAT ;
    if (argc < 1 || strcmp(argv[1], "--help") == 0){
        printf("%s filename \n", argv[0]);
	return 1;
    }
    


    fd = open(argv[1], flag);
    if(fd==-1){
        perror("open");
        return -1;
    }   
    
    new_fd = dup(fd);

    printf("fd offset is %d,newfd offset is %d\n",lseek(fd,0,SEEK_CUR),lseek(new_fd,0,SEEK_CUR));
    write(fd,"test",4);
    printf("fd offset is %d,newfd offset is %d\n",lseek(fd,0,SEEK_CUR),lseek(new_fd,0,SEEK_CUR));
    lseek(new_fd,2,SEEK_SET);
    printf("fd offset is %d,newfd offset is %d\n",lseek(fd,0,SEEK_CUR),lseek(new_fd,0,SEEK_CUR));


    exit(EXIT_SUCCESS);
}
