#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <time.h>
#include <errno.h>
#include "accessmemory.h"

// Define the static variable
#define SM_SIZE 1024
#define KEY 90

// Declare function prototypes 
void INThandler(int);

// Delcare global variables
pid_t pid[19];
int shmid;

// Signal function to kill processes if (^C) is received
void INThandler(int sig) { 
	fprintf(stderr,"Control C have been detect\n");
		int i;
		// Loop through all the child processes
		for (i = 0; i <20; i++) {

			// Kill child due to signal
			kill(pid[i],9);
			fprintf(stderr,"Trying to delete slave process at %d\n",i);
                	fprintf(stderr,"..........\n");
			sleep(1);
                	fprintf(stderr,"deleting slave process");
			fprintf(stderr," at %d ", i);
			fprintf(stderr,"is success\n");
	}
}

// The main process sets a timer at the start of computation to 60 seconds
void INTalarm(int alarm)
{
	fprintf(stderr,"60 sec is up\n");

	// Loop trough all the child processes
	int i;
	for (i = 0; i < 20; i++) {
		// Kill child due to time
		kill(pid[i],9);
		fprintf(stderr,"Trying to delete slave process at %d\n",i);
                fprintf(stderr,"..........\n");
                fprintf(stderr,"deleting slave process");
                fprintf(stderr," at %d ", i);
                fprintf(stderr,"is success\n");
	}
}

int main (int argc, char *argv[]) {

	// Calling signal function
	signal(SIGALRM,INTalarm);
	signal(SIGINT, INThandler);

	// Name struct
	struct memory *data;
	

	// Declare local variables
	int status;
	int i;
	char line;
	

	// Creating share memory
	if ((shmid = shmget(KEY, SM_SIZE, IPC_CREAT | 0775)) == -1) {
		perror("Check Shared Memory");
		exit (1); 
	}
	
	// Attach the share memory to our data
	data = (memory*) shmat(shmid, NULL, 0);
	
	// If it fails to create share memory
	if (data == (memory*)-1) {
		perror ("Couldnt assgin memory");
		exit (1); 
	}
	
	// Point the share memory data to a pointer
		
	
	// Get input file from the user
	char const* const fileName = argv[1];

	// Read file from user
	FILE *file = fopen(fileName, "r");

	while (!feof(file)) {
		fgets(line, 256, file);
	}
	
	line = data->text;
	
	// Create a time of 60 Seconds
        alarm (60);

	// Create child processes
	for (i = 0; i < 20; i++) {
		
		// Creating a fork
		if ((pid[i] = fork()) < 0 ) {
			perror("Could not fork at all");
			exit(1);
		}
		else if((pid[i] = fork()) == 0) {
				
			// Passing the information to palin.c for the process to handle	
			execl("./palin", "palin", NULL);
		}
	}

	// Wait for all the child processes to end
	while (wait(&status) > 0)

	// Detach and delete the share memory
	shmdt(data);
	shmctl(shmid, IPC_RMID, NULL);

	return 0;				
}
