#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {

	int i, n, opt;

	int slaveProcess = 5;
	char fileName[] = "log.txt";

	int killTime = 20;

	while ((opt = getopt(argc, argv, "hs:l:t:")) != -1) {
                switch (opt) {
		case 'h':
			perror("The command line argue ments for this progarm are -s x, l, t,\n");
			perror("-s x, where x is the maximum number of slave processes spawened (default 5)\n");
			perror("-l filename, where filename is the log file used\n");
			perror("-t z, where z is the time in seconds when the master will terminate itsealf and all childeren (default 20)\n");
			exit(EXIT_FAILURE);
			break;
		case 'l':
			strcpy(fileName, optarg);
			break;
		case 's':
			slaveProcess = atoi(optarg);
			break;			
		case 't':
			killTime = atoi(optarg);
			break;
		case '?':
			perror("oss: -s -l -l options require inputs after. Type option -h for more details\n");
			exit(EXIT_FAILURE);		
                default:
                    perror("oss: Error Default");
		    exit(EXIT_FAILURE);
                }
	}

	FILE *file = fopen(fileName, "w");
	char line[] = "test";
	fprintf(file, line);

	printf("File name: %s\n", fileName);
	printf("Slave Processes: %d\n", slaveProcess);
	printf("Kill time: %d\n", killTime);

}
