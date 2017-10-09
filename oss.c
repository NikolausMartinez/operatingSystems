#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {

	int i, n, opt;

	while ((opt = getopt(argc, argv, "hslt")) != -1) {
                switch (opt) {
		case 'h':
			perror("oss: Erorr h");
			exit(EXIT_FAILURE);
			break;
		case 'l': 
			perror("oss: Error l");
			exit(EXIT_FAILURE);
			break;
		case 's':
			perror("oss: Error s");
			exit(EXIT_FAILURE);
			break;
		case 't':
			perror("oss: Error t");
			exit(EXIT_FAILURE);
			break;		
                default:
                    perror("oss: Error Default");
		    exit(EXIT_FAILURE);
                }
		return 0;
	}
}
