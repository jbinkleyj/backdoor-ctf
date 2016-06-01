#include <stdio.h>
#include <fcntl.h>

void secure_function(char* secret,char* input, char* key){
	int i;
	int secret_key=100;
	for (i = 0; i < 10; i++) {
		input[i]^=(key[i]^secret_key);
	}
	
	if ( !strncmp(input,secret,10) ){
		system("/bin/cat flag");
	}
	else{
		printf("Told you it's secure as :P\n");
	}
}

int main(int argc, char* argv[]){
	int fd,len;
	if (fd=open("password",O_RDONLY,0400) < 0) {
		printf("can't open password\n");
		return 0;
	}
	printf("Complex encryptions always take time...\n");

	char secret[11];
	if(!(len=read(fd,secret,10) > 0)){
		printf("read error\n");
		close(fd);
		return 0;		
	}

	char password[11];
	printf("Password : \n");
	scanf("%10s", password);

	char key[11];
	printf("Key : \n");
	scanf("%10s", key);
	
	//secure hash function
	secure_function(secret,password,key);

	close(fd);
	return 0;
}
