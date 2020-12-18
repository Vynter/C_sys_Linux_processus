#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>
#include <sys/wait.h>

#define LINESIZE 25

int lecture(FILE * file){
	char line[255];
        fgets(line,LINESIZE,file);
        printf("%s\n",line);
        fclose(file);
	return 0;
}
 
int main(int argc, char *argv[]){

 int status;
 char line1[255],line2[255];
 FILE *file1;
 FILE *file2;

 if(argc!=3){
	printf("Erreur! Veuillez saisir 3 arguments\n");
	}else{
	 file1=fopen(argv[1],"r");
	 file2=fopen(argv[2],"r");
	 if(file1!=NULL && file2!=NULL){
	 pid_t fils=fork();

	 if(fils ==-1){
		perror("Erreur fork \n");
		exit(errno);
	 }
	 if(fils ==0){
		lecture(file2);
		exit(0);
	 }else{
		wait(&status);
		if(WIFEXITED(status)){
			lecture(file1);
		}

		if(WIFSIGNALED(status)){
			printf("un signal a arrêté le fils");
		}
		sleep(1);
	 }

	 }else{
		printf("impossible d'ouvrir le fichier");
		}
	 }

 return 0;

}
