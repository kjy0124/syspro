#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("my process num : [%d]\n", getpid());
	printf("my parent process num : [%d]\n", getppid());
}
