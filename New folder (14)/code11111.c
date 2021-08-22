#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#define msgsz 16
int main()
{
	char *msg1 = "hello one";
	char *msg2 = "hello two";
	char *msg3 = "hello three";
	char inbuf[msgsz];
	int p[2],j;
	pipe(p);
	if(!fork())
	{
		write(p[1],msg1,msgsz);
		write(p[1],msg2,msgsz);
		write(p[1],msg3,msgsz);
	}
	else
	{
		for(j=0;j<3;j++)
		{
			read(p[0],inbuf,msgsz);
			printf("%s\n",inbuf);
		}
		exit(0);
	}
}
