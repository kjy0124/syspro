#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main()
{
	printf("my real user's ID : %d(%s)\n",getuid(),getpwuid(getuid())->pw_name);
	printf("myactive user'sID : %d(%s)\n",geteuid(),getpwuid(geteuid())->pw_name);
	printf("my real group's ID : %d(%s)\n",getgid(),getgrgid(getgid())->gr_name);
	printf("myactivegroup'sID: %d(%s)\n",getegid(),getgrgid(getegid())->gr_name);
}
