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
    int flag =  O_RDWR | O_CREAT ;
    if (argc < 3 || strcmp(argv[1], "--help") == 0){
        printf("%s filename num-bytes [x]\n", argv[0]);
	return 1;
    }
    

    int num = atoi(argv[2]);
    if(argc==3){
	
	flag = flag | O_APPEND;
        fd = open(argv[1], flag);
        if (fd == -1)
            perror("open");
    
        while(num>0){
            if (write(fd, "a", 1) == -1)
                perror("write");
            num--;
        }
    }else{

        fd = open(argv[1], flag);
        while(num>0){
            lseek(fd, 0, SEEK_END);
            if (write(fd, "a", 1) == -1)
                perror("write");
            num--;
        }
        


    }
    exit(EXIT_SUCCESS);
}
