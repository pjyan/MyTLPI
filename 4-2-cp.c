#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h>

int
main(int argc ,char *argv[]){


    int ch = 0;
    int ret = 0;
    char buf[1024];
    int fd1,fd2;
    int read_num = 0;
    const char* help = "Usage: cp  [FILE1] [FILE2]\n";

    if(argc != 3){
        printf("%s",help);
        return 1;       
    }
    /* parse and process options */
    while ((ch = getopt(argc, argv, "h")) != -1)
    {
        switch (ch)
        {
            case 'h':
            default:
                printf("%s", help);
                return 0;
        }
    }
    

    fd1  = open(argv[1],O_RDONLY);
    if(fd1==-1){ 
	perror("open file1 error");
	return 0;
     }
    
    fd2  = open(argv[2],O_WRONLY | O_TRUNC);
    if(fd2==-1){ 
	perror("open file2 error");
	return 0;
     }
		
     while((read_num = read(fd1,buf,1024))>0){

	write(fd2,buf,read_num);
	    
    }
   

return 0;
}
