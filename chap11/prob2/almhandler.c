#include <stdio.h>
#include <signal.h>

void alarmHandler();

int main()
{
	signal(SIGALRM, alarmHandler);
	alarm(5);
	int no = 1 ;
	printf("infinite loop\n");
	while(1) {
		sleep(1);
		printf("%d second\n", no);
		 no++;
	}
	printf("err \n");
}
void alarmHandler(int signo){
	printf("wake up\n");
	exit(0);
}
