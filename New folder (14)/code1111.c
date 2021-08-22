#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
int main()
{
	int pfd[2];
	if(pipe(pfd)<0)
		printf("error");
	if(!fork())
	{
		char data;
		printf("i am a child\n");
		printf("press any key to exit : \n");
		scanf("%c",&data);
		write(pfd[1], &data, 1);
		printf("child exiting\n");
	}
	else
	{
		char data;
		read(pfd[0], &data, 1);
		printf("I'm parent\n");
		printf("received %c from child\n",data);
		printf("Parent exiting......\n");
		exit(0);
	}
}

