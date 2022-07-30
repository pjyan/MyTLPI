#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <setjmp.h>

extern char **environ;

int
main(int argc, char *argv[])
{
    
   char **p = environ;
   char *a = "vm=dell-vm";


   printf("current env:\n");
   for(p ; *p!=NULL ; p++){

	puts(*p);
    }
    printf("===============================\n");
    printf("SHEEL use %s\n",getenv("SHELL"));


   putenv(a);
   printf("vm use %s\n",getenv("vm"));


   p = environ;
   for(p ; *p!=NULL ; p++){

	puts(*p);
    }

    printf("===============================\n");
    printf("remove vm");

    unsetenv("vm");

   p = environ;
   for(p ; *p!=NULL ; p++){

	puts(*p);
    }
    exit(EXIT_SUCCESS);

}

