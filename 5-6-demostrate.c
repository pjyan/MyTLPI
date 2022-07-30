#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    int fd1, fd2, fd3;
    int new_fd;
    int flag =  O_RDWR | O_CREAT ;
    if (argc < 1 || strcmp(argv[1], "--help") == 0){
        printf("%s filename \n", argv[0]);
	return 1;
    }
    
    fd1 = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    fd2 = dup(fd1);
    fd3 = open(argv[1], O_RDWR);
    write(fd1, "Hello,", 6);
    // "Hello,". When file is opened, its offset is 0.
    write(fd2, "world", 6);
    // "Hello,world\0". fd2 is a duplicate of fd1, so they share the same offset.
    lseek(fd2, 0, SEEK_SET);
    write(fd1, "HELLO,", 6);
    // "HELLO,world\0". fd2 is a duplicate of fd1, so they share the same offset.
    write(fd3, "Gidday", 6);
    // "Giddayworld\0". fd3 refers to a different open file description.

    exit(EXIT_SUCCESS);
}
