# include <sys/types.h> 
 # include <unistd.h>
 # include <stdio.h> 
 #include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define PATH "/home/akane/Desktop/tubes/myFifo"
int main(int argc, char *argv[]){
	char filerecup[80];
	if(mkfifo(PATH, 0644) == -1){
		perror("problem mkfifo()\n");
		exit(EXIT_FAILURE);
	}
	FILE *tube = fopen(PATH, "r");
	if(tube){
		while(1)
		while(fgets(filerecup, 80, tube)){
			printf(">>>%s\n", filerecup);
			fclose(tube);
		}
	}
	else{
		perror("le tube l'exsite pas");
		exit(EXIT_FAILURE);
	}
	unlink(PATH);
	return EXIT_SUCCESS;
}
//client send an arth op;  op num1 num2 : using argv;
//server do the op

