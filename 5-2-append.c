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
    
    if (argc != 3 || strcmp(argv[1], "--help") == 0){
        printf("%s pathname StringToWrite\n", argv[0]);
	return 1;
    }
    fd = open(argv[1], O_RDWR | O_APPEND);
    if (fd == -1)
        perror("open");
    
   if (lseek(fd, 0, SEEK_SET) == -1)
        perror("lseek");
   
    if (write(fd, argv[2], strlen(argv[2])) == -1)
        perror("write");
    exit(EXIT_SUCCESS);
}
