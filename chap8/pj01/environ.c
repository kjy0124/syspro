#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'e'){
		if(argc > 2) {
			char *env_var = getenv(argv[2]);
			if (env_var != NULL) {
				printf("%s=%s\n", argv[2],env_var);
			} else {
				printf("err '%s'\n", argv[2]);
			}
		} else {
			extern char **environ;
			for (char **env = environ; *env != NULL;env++){
				printf("%s\n", *env);
			}
		}
	}
	if(argc > 1 && argv[1][0] == '-'){
		if (argv[1][1] == 'u') {
			printf("My Realistic User ID : %d(ppos2eun)\n", getuid());
			printf("My Vaild User ID : %d(ppos2eun)\n", geteuid());
		}
		else if(argv[1][1] == 'g'){
			printf("My Realistic Group ID : %d(ppos2eun)\n", getgid());
			printf("My Vaild Group ID : %d(ppos2eun)\n", getegid());
		}
	}

	if(argc > 1 && argv[1][0]=='-' && argv[1][1]=='i'){
		printf("my process number : [%d]\n", getpid());
	}
	if(argc > 1 && argv[1][0] == '-' && argv[1][1] == 'p'){
		printf("my parent's process number : [%d]\n", getppid());
	}

	return 0;
}
