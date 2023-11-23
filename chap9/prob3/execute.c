#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("Parental process start\n");
	if (fork==0){
		execl("/bin/echo", "echo", "hello", NULL);
		fprintf(stderr,"err");
		exit(1);
	}
	printf("parental process end\n");
}
