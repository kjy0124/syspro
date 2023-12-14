#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	int chd = 0;
	printf("type num of childs : ");
	scanf("%d", &chd);
	
	for(int i = 0; i < chd; i++){
		int pid[chd];
		pid[i] = fork();
		if(pid[i] == 0) {
			printf("[Child %d] : Started! pid=%d, sleep = %d\n", i, getpid(), i);
			exit(0);
		}
	}
	for (int i = 0; i < chd; i++){
		int pid[chd];
		pid[i] = fork();
		if(pid[i] == 0) {
			printf("[Child %d] : killed! pid=%d, sleep = %d\n",i,  getpid(), i);
			exit(0);
		}
	}
	printf("parent killed - last child id = %d\n", getpid());
}
