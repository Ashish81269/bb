#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int i=0,j=0,pid;
	pid=fork();

	if(pid==0)
	{
		for(i=0;i<100;i++)
			printf("%d\t",i);
	}
	else
	{
		if(pid>0)
		{
			wait(0);
			for(j=0;j<100;j++)
				printf("%d\t",j);
		}
	}
	return 0;
}

