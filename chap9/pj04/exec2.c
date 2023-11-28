#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("parental process start\n");
	if (fork()==0){
		execl("/bin/echo", "echo","hello",NULL);
		fprintf(stderr,"first err");
		exit(1);
	}
	if(fork()==0){
		execl("/bin/date","date",NULL);
		fprintf(stderr,"second err");
		exit(2);
	}
	if(fork()==0){
		execl("/bin/ls","ls","-l",NULL);
		fprintf(stderr,"third err");
		exit(3);
	}
	printf("parental process end\n");
}
