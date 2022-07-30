#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <setjmp.h>

jmp_buf env;

void hello(){

    printf("we setjmp here %s\n",__func__);
    if(setjmp(env)!=0){
	printf("we jmp back here %s\n",__func__);
    }
}


int
main(int argc, char *argv[])
{
    printf("start mian.....\n");
    hello();
    longjmp(env,1);
    printf("finish mian.....\n");
    exit(EXIT_SUCCESS);
}

