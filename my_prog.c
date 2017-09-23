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

	if (argc != 2) {
		fprintf(stderr, "Usage: %s processes\n", argv[0]);
		return 1;
	}
	n = atoi(argv[1]);
	while ((opt = getopt(argc, argv, "a")) != -1) {
		switch (opt) {
		case 'a':
		    fprintf(stderr, "Child failed uh oh");
		    break;
		default:
		    perror("Please enter a positive number");
		    break;
		} 
		for (i = 1; i < n; i++)
			if(childpid = fork())
				break;
		fprintf(stderr, "i:%d process ID:%1d parent ID:%1d child ID:%1d\n", i, (long)getpid(), (long)getppid(), (long)childpid);
		return 0;
	}
}
