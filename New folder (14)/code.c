#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		printf("hello!!! i'm from child\n");
		printf("CHILD ID %d\n",getpid());
		printf("PARENT ID %d\n",getppid());

	}
	else
	{
		printf("hi!!! i'm from parent\n");
		printf("PROCESS ID %d\n",getpid());
		printf("PARENT ID %d\n",getppid());
	}
	return 0;
}
