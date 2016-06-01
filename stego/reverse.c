#include <stdio.h>

char buffer[2048];

int main(int argc, char ** argv) {

	char ch;
	int i = 0;



	FILE * f = fopen ("que", "rb");

	fread (buffer, 1, 1849, f);

	for(i = 1848; i >= 0; i--)
		printf("%c", buffer[i]);


}
