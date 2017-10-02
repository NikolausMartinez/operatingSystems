#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char* argv[]) {

	// gets input file from user
	char const* const fileName = argv[1];
	char const* const foundpalin = "palin.out";
	char const* const nonpalin = "nopalin.out";
	FILE *file = fopen(fileName, "r");
	FILE *write;
	char line[256];	// read line
	char linec[256]; // copy line
	
	while (fgets(line, sizeof(line), file) != NULL) {
		
		write = fopen(nonpalin, "w");
		fputs(line, stdout);
		strcpy(linec, line);
		fprintf(write, linec);
	}
	fclose(write);
	fclose(file);
	return 0;
}
