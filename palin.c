#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <sys/shm.h>
#include <errno.h>
#include "accessmemory.h"
#define MAX_WRITE 5


// Declare function prototypes
void INThandler(int);

// Declare global variables
int shmid;

// Signal function
void INThandler(int sig) {

	// Kill child
	kill(getpid(),9):
}

int main (int argc, char *argv[]) {

	// Calling the signal function
	signal(SIGINT, INThandler);   

	// Name the struct
	memory *data;

	// Create share memory
	if ((shmid = shmget(90,sizeof(memory),0)) == -1) {
                perror("Check Shared Memory");
                exit (1);
        }
        data = (memory *) shmat(shmid, NULL, 0);

	// Declare local variables
	int i = atoi(argv[1]); 
	FILE *fp;
	int k, j;
	const int n = 19;
	static const char foundpalin[] = "palin.out";
	static const char nonpalin[] = "nopalin.out";

	// Create random time between 0-2 for process to wait to before it can write and leave critiacal section
	srand(time(NULL));
	int in =(1+ rand()%2);
	srand(time(NULL));
	int out=(1+ rand()%2);

	// Time for when processes enter and exit critical section
	time_t currenttime;
	time(&currenttime);

	// This loop is for critcal section
	// It allows only a max of 5 requests into the critical section
	
	for (k=0; k < MAX_WRITE; k++) {		       
		do {
			// Raise my flag
			data->flag[i] = want_in;

			// Set local variable
			j = data->turn;

			// Wait until its my turn
			while (j != i)
 				j = (data->flag[j] != idle) ? data->turn : (j + 1) % n;
			
			// Declare intention to enter critical section
			data->flag[i] = in_cs;
			fprintf(stderr,"The process number %d",i);
                	fprintf(stderr," is trying to enter the critical section");
                	fprintf(stderr, " at %s\n", ctime(&currenttime));

			// Check to see no other child process is int he critical section
			for (j = 0; j < n; j++)
 				if (( j != i) && (data->flag[j] == in_cs))
 					break;
	
 		} while (( j < n) || (data->turn != i && data->flag[data->turn] != idle));

		// Assign turn to self and enter the critical_section
		date->turn = i;
		
		/*	*	*	*    * *
		 * INSIDE THE CRITICAL_SECTION *
 		 * 	*	*	*    * */

		// When the process is entering the critical_section
		fprintf(stderr,"The process number %d",i);
		fprintf(stderr," is entering critical section");
		fprintf(stderr, " at %s\n", ctime(&currenttime));
		sleep (in);


		// Check to see if the line string is a palindrome 
		int i, length;
		FILE *writePalin = fopen(foundpalin, "w");
		FILE *writeNoPalin = fopen(nonpalin, "w");
		char reverse_string[256] = {'\0'}
		length = strlen(line);
		
		for (i = length - 1; i >= 0; i--) {
			reverse_string[length - i - 1] = line[i];
		
		}
		for (i = 0; i < length; i++) {
			if (reverse_string[i] != str[i]) {

				// String is not a palindrome send it to nonpalin.out  file
				fprintf(writeNoPalin, line);

			} else {

				// String is a palindrome send it to palin.out file
				fprinff(writePalin, line);
			}
		}
		
		

		// When the process is exiting the critical_section
		sleep(out);
		fprintf(stderr, "The process number %d",i);
                fprintf(stderr, " is exiting critical section");
		fprintf(stderr, " at %s\n", ctime(&currenttime));

		// Exit section
		j = (data->turn + 1) %n;
			while (data->flag[j] == idle)
 				j = (j + 1) % n;

		// Assign turn to next waiting process. Change own flag to idle
		data->turn = j;
		data->flag[i] = idle;
	}
	shmdt(data);
	
	return 0;
}
