# include <sys/types.h> 
# include <unistd.h>
# include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define PATH "/home/akane/Desktop/tubes/myFifo"
int main(int argc,char *argv[]){
FILE *fic;
int i;
fic=fopen(PATH,"w");
if(fic<0)
{
perror("probleme fopen()\n");
exit(1);
}
for(i=1;i<argc;i++){
fputs(argv[i],fic);
}
return EXIT_SUCCESS;
}
