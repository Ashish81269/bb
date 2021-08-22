#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<errno.h>
int exflag=0;
int main()
{
	char c;
	if(!fork())
	{
		printf("press a key\n");
		dified code:
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
			//file inherited to both process, read and write from pipe file file descriptors
			//int main()
			//{
			//int fd[2];
			//pipe(fd);
			//char c;
			//int exflag=0;
			//if(!fork())
			//{
			//close(fd[0]);
			//printf("press a key: ");
			//scanf("%c",&c);
			//exflag=1;
			//write(fd[1], &exflag, sizeof(int));
			//close(fd[1]);
			//exit(0);
			//}
			//else
			//{
			//close(fd[1]);
			//int y;
			//read(fd[0], &y, sizeof(int));
			//close(fd[0]);
			//while(!y);
			//printf("i got the character\n");
			//
		scanf("%c",&c);
		exflag=1;
		exit(0);
	}
	else
	{
		while(!exflag);
		printf("i got the character");
		exit(0);
	}
}
