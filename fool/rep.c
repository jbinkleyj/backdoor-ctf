#include <stdio.h>

int checkpassword(char * buffer) {
	return buffer[0] == 'A';
}

int main(int argc, char ** argv) {

	char buffer[1023];

	puts("Enter password for authentication:");
	fflush(stdout);
	
	fgets(buffer, 1023, stdin);
	sleep(2);
	
	if (checkpassword(buffer)) {
		puts("Congrats! You have entered correct password:");
		fflush(stdout);
	} else {
		puts("Sorry authentication failure : Incorrect password :");
		fflush(stdout);
		printf(buffer);
		puts("Please try again!");
	}

	return 0;
}
