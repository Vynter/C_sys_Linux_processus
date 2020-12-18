#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>
#include <sys/wait.h>

int verif(int *d, int *f){
int a=*d;int b=*f ;
	 for(int i=a;i<=b;i++){
       		if(i%2==0){
                	printf("%d est paire\n",i);
                        }else{
                        	printf("%d est impaire\n",i);
                        	}
                sleep(1);
                }
	
return 0;
}

int total(int *d, int *f,int *t){
int a=*d;int b=*f;int somme=0 ; 
	for(int i=a;i<=b;i++){
        	somme=somme+i;
		
      	}
*t=somme;
return 0;
}

 
int main(int argc, char *argv[]){

	int a,b,status;
	int somme=0;

	
	printf("Veuillez saisir le debut de l'interval\n");
	scanf("%d",&a);
	printf("Veuillez saisir la fin de l'interval\n");
	scanf("%d",&b);
	pid_t fils=fork();

	if(fils ==-1){
		perror("Erreur fork \n");
		exit(errno);
	}
	if(fils ==0){
		verif(&a,&b);
		exit(0);	
	}else{
		total(&a,&b,&somme);
		wait(&status);
		if(WIFEXITED(status))
			printf("la somme total est de %d\n",somme);
		if(WIFSIGNALED(status))
			printf("un signal a arrêté le fils");
		sleep(1);
	}




	return 0;

}
