#include <stdio.h>

int main(int argc, char ** argv) {
	int i = 0;
	int j = 0;
	char * a = "abcdefghijkhlmnoqrstuvwxyz";
	int ch1;
	int ch2;
	for(i = 0; i < 250; i++) {
		for(j = 0; j < 250; j++) {
			ch1 = i;
			ch2 = j;

			ch1 ^= (ch2 ^ 100);

	
			//printf("%d\n", ch1);
			if (!ch1) printf("%x %x\n", i, j);	

		}

	}
}
