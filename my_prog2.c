#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <time.h>

// Global variables
pid_t pid [19];
int shmid;

int isPalindrome(char str[]) {

	int i, length;
	char reverse_string[50] = {'\0'};
	length = strlen(str);

	for (i = length - 1; i >= 0; i --) {
		reverse_string[length - i - 1] = str[i];
	}
	for (i = 0; i < length; i++) {

		if (reverse_string[i] != str[i])
		return 0;
	}
	return 1;

}

int critical_section() {




}

int remainder_section() {

}

enum state { idle, want_in, in_cs };
extern int turn, n;
extern state flag[n];/*Flag corresponding to each process in shared memory */

void process(const int i ) {
	do {
		do {
			flag[i] = want_in; // Raise my flag
			j = turn; // Set local variable
			// wait until its my turn
			while ( j != i )
				j = ( flag[j] != idle ) ? turn : ( j + 1 ) % n;
 			// Declare intention to enter critical section
 			flag[i] - in_cs;

			// Check that no one else is in the critical section
			for ( j = 0; j < n; j++ )
				if ( ( j != i ) && ( flag[j] == in_cs ) )
					break;
		} while ( ( j < n ) || ( turn != i && flag[turn] != idle ) );

	// Assign turn to self and enter critical section
	turn = i;
	critical_section();
	
	// Exit section
	j = (turn + 1) % n;
	while (flag[j] == idle)
		j = (j + 1) % n;

	// Assign turn to next waiting process; change own flag to idle 
	turn = j; flag[i] = idle;
 	remainder_section();
 	} while ( 1 );
}


int main (int argc, char* argv[]) {

	// gets input file from user
	char const* const fileName = argv[1];
	static const char foundpalin[] = "palin.out";
	static const char nonpalin[] = "nopalin.out";
	FILE *file = fopen(fileName, "r");
	FILE *writePalin = fopen(foundpalin, "w");
	FILE *writeNoPalin = fopen(nonpalin, "w");
	char line[50];	// read line
	char linec[50]; // copy line

	while (!feof(file)){

		fgets(line, sizeof(line), file);
		
		// creat child processes to handle each line in the file

		if (isPalindrome(line)){
			strcpy(linec, line);
                	fprintf(writePalin, linec);
		} else {
		
			strcpy(linec, line);
			fprintf(writeNoPalin, linec);
		}
	}	
	fclose(writePalin);
	fclose(file);
	return 0;
}
