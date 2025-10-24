/*Write a loop equivalent to the for loop above without using && or ||.*/

#include<stdio.h>
#define maxline 100
int main()
{
	int i,c,lim=maxline;
	char str[maxline];
	for(i=0;(c=getchar())!=EOF&&c!='\n';i++)
	{
		str[i]=c;
	}
	if(i>(lim-1))
	{
		str[lim-1]='\0';
	}
	else
	{
		str[i]='\0';
	}
	printf("printing using loop: %s \n",str);
	i=0;
	while(i<(lim-1))
	{
		if((c=getchar())!='\n')
		{
			if(c!= EOF)
			{
				str[i]=c;
			}
			++i;
		}
		if(c=='\n' || c==EOF)
		{
			str[i]='\0';
		}

	}
	printf("print with if-else: %s \n",str);
}
