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

	FILE *fp = fopen(fileName, "w");

	printf("File name: %s\n", fileName);
	printf("Slave Processes: %d\n", slaveProcess);
	printf("Kill time: %d\n", killTime);

	for (i = 1; i < slaveProcess; i++) { 
		fork();
		fprintf(fp, "i:%d process ID:%1d\n", i, (long)getpid());
	}

	for (i = 0; i< slaveProcess; i++) {
		kill(slaveProcess, 9);
		fprintf(fp,"Trying to delete slave process at %d\n",i);
                fprintf(fp,"..........\n");
               	fprintf(fp,"deleting slave process");
		fprintf(fp," at %d ", i);
		fprintf(fp,"is success\n");
	}				

}
