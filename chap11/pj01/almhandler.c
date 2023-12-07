#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

struct sigaction newact;
void alarmHandler(int signo);
int main()
{
	newact.sa_handler = alarmHandler;
	sigfillset(&newact.sa_mask);
	signal(SIGALRM, alarmHandler);
	alarm(5);
	int a = 0;
	while(1){
		sleep(1);
		a++;
		printf("%d second\n", a);
	}
	printf("end\n");
}
void alarmHandler(int signo)
{
	printf("Wake up\n");
	exit(0);
}
