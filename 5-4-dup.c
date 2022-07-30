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
    if (argc < 2 || strcmp(argv[1], "--help") == 0){
        printf("%s filename [new_fd]\n", argv[0]);
	return 1;
    }
    


    fd = open(argv[1], flag);
    if(fd==-1){
        perror("open");
        return -1;
    }   
    if(argc==2){

	new_fd = fcntl(fd,F_DUPFD,0);
	if(new_fd==-1){
	    perror("dup:");
	    return -1;
	}
	printf("fcntl -> dup\nold fd is:%d\nnew fd is:%d\n",fd,new_fd);
    }else{

	if(fd == atoi(argv[2])){
		
	    printf("new_fd:%d is same as fd:%d",atoi(argv[2]),fd);
	    return -1;
	}
	if(fcntl(atoi(argv[2]),F_GETFD)!=-1){
		perror("dup2 close exisit fd");
		close(atoi(argv[2]));
	}
	new_fd = fcntl(fd,F_DUPFD,atoi(argv[2]));
	if(new_fd==-1){
            perror("dup2:");
            return -1;
        }
        printf("fcntl -> dup2\nold fd is:%d\nnew fd is:%d\n",fd,new_fd);
    }

    exit(EXIT_SUCCESS);
}
