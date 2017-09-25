#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
	pid_t childpid = 0;
	int i, n, opt;	
	int time = 2;	
	
	while ((n = getopt(argc, argv, "")) != -1) {
                switch (opt) {
                default:
                    perror("my_prog: Error ");
		    exit(EXIT_FAILURE);
                    break;
                }
	}
        
	if (argc != 2) {
		fprintf(stderr, "Usage: %s processes\n", argv[0]);
		return 1;
	}

	n = atoi(argv[1]);
	for (i = 1; i < n; i++)   
            if((childpid = fork()) <=0)
		break;
            while(wait(NULL) > 2);    
            fprintf(stderr, "i:%d process ID:%1d parent ID:%1d child ID:%1d\n", i, (long)getpid(), (long)getppid(), (long)childpid);
            return 0;
}
