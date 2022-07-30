#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


void read_v(int rfd){

    char buf1[3][1024];
    
    int buf_index=0;
    int r;
    while(buf_index<3&&((r=read(rfd,buf1[buf_index],1024))!=0)){

	if(r=1024)
	    buf_index++;
    }

    return;

}

void write_v(int wfd){

    char buf1[3][1024];

    int buf_index=0;
    int r;
    while(buf_index<3&&((r=write(wfd,buf1[buf_index],1024))==1024)){
            
        buf_index++;
    
    }

    return;

}



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
    read_v(fd);
    write_v(fd);
    exit(EXIT_SUCCESS);
}

