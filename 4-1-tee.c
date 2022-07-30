#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h>

int
main(int argc ,char *argv[]){


    int ch = 0;
    int has_file = 0;
    int append = 0;
    int ret = 0;
    char buf[1024];
    int read_num = 0;
    const char* help = "Usage: tee [OPTION]... [FILE]...\n"
                       "\ta: append to the given FILEs, do not overwrite\n"
                       "\th: display this help and exit\n";

    
    /* parse and process options */
    while ((ch = getopt(argc, argv, "ah")) != -1)
    {
        switch (ch)
        {
            case 'a':
		append = 1;
                break;

            case 'h':
            default:
                printf("%s", help);
                return 0;
        }
    }
    

    if(append && argc > 2){
        ret = open(argv[argc-1],O_RDWR | O_APPEND);
        has_file = 1;       
    }
    else if(argc>1){
        ret = open(argv[argc-1],O_RDWR);
 	has_file = 1;       
    }
    if(has_file && ret==-1){ 
	perror("open error");
	return 0;
     }
    
    while(1){
		
   	while((read_num = read(STDIN_FILENO,buf,1024))>0){

	    write(STDOUT_FILENO,buf,read_num);
	    
	    if(has_file){

		write(ret,buf,read_num);

	    }	    
            
	}
    }
   

return 0;
}
