#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

int main()
{
	int chd = 8;
	for(int i = 0; i < 8; i++){
		int pid[chd];
		pid[i] = fork();
		if(pid[i]==0){
			printf("Hello\n");
			exit(0);
		}
	}
	return 0;
}
