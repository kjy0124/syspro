#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int pid, child, status;
	printf("[%d] parental process start\n", getpid());
	pid=fork();
	if (pid == 0) {
		printf("[%d] child process start\n", getpid());
		exit(1);
	}
	child = wait(&status);
	printf("[%d] child process %d end\n", getpid(),child);
	printf("\tend code %d\n", status>>8);
}
