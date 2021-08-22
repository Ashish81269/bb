#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int i,d;
	char c;
	if(!fork())
	{
		for(c='a';c<='z';c++)
		{
			printf("%c\t",c);
			fflush(stdout);
			for(d=0;d<30000;d++);
		}
		exit(0);
	}
	else
	{
		for(i=0;i<=10;i++)
		{
			printf("%i\n",i);
			fflush(stdout);
			for(d=0;d<=50;d++);
		}
		exit(0);
	}
	return 0;
}
