#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

int array[] = {168,232,100,162,135,179,112,100,173,206,106,123,106,195,179,157,123,173};
//int array[18] = {29,213,6,18,2,229,29,33,25,245,10,237,213,29,225,221,233,213};
char buffer[19];

int main(int argc, char ** argv) {

	int key, i;

	for(key = 101*10; key <= 'z'*101; key++) {
		char found = 1;
		for(i = 0; i < 18 && found; i++) {
			found = 0;
			int encrypt = array[i];

			int j = 0;
			
			for(j = 0; j*255 <= 8000 && !found; j++) {
				int enc = encrypt + (255*j);

				float am, gm;

				for(am = enc; am >= 0; am-=0.5) {
					float x1 = -key+2*am;	

					if (((x1 >= 'a' && x1 <= 'z') || (x1 >= 'A' && x1 <= 'Z') || (x1 >='0' && x1<='9'))) {

						gm = sqrt(key*x1);
						am = (key+x1)/2;

						if ((int)floor(am+gm)%255 == encrypt) {
							found = 1;
							buffer[i] = (char)x1;
						}
					}	
				}
			}
		}
		if (found)
			printf("%s - %d\n", buffer, key);	
		else 
			bzero((void*)buffer, 18);
	}
	
}
