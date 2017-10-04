typedef enum { idle, want_in, in_cs } state;

typedef struct memory 
{
	int turn;
	int flag[19];
	char text[256];
}memory;
