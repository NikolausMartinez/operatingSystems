#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
	// declare variables 
	pid_t childpid = 0;
	int i, n, opt;
	
	// Use getopt to get command line arguement
	while ((opt = getopt(argc, argv, "aio")) != -1) {
                switch (opt) {
		case 'a':
			perror("my_prog: Erorr No (dot) files needed. Please only enter a positive number");
			exit(EXIT_FAILURE);
			break;
		case 'i': 
			perror("my_prog: Error No input file needed. Please only enter a positive number");
			exit(EXIT_FAILURE);
			break;
		case 'o':
			perror("my_prog: Error No output file needed. Please only eneter a positive number");
			exit(EXIT_FAILURE);
			break;		
                default:
                    perror("my_prog: Error please only enter a positive number");
		    exit(EXIT_FAILURE);
                }
		return 0;
	}
	// Create all the process chain
	if (argc != -1) {
		n = atoi(argv[1]);
		for (i = 1; i < n; i++)   
            	if((childpid = fork()) <=0)
			break;
		// wait(2)
            	while(wait(NULL) > 2);    
            	fprintf(stderr, "i:%d process ID:%1d parent ID:%1d child ID:%1d\n", i, (long)getpid(), (long)getppid(), (long)childpid);
            	return 0;
	}
}
