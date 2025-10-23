#include<stdio.h>
main()
{
	int wlen[9];// max 10 words
	int i,c,j,no;
	for(i=0;i<10;i++)
	{
		wlen[i]=0;
	}
	i=0;

	while((c=getchar())!=EOF)
	{
		if(c==' ' || c=='\t' || c== '\n')
		{
			++no;
		}
		else if(c>='0' && c<='9')
		{
		}
		else 
		{
			++wlen[no];
		}
	}
	printf("horizontal histogram\n");
	printf("digits\n");
	for(i=0;i<10;i++)
	{
		printf("word%d------",i+1);
		for(j=0;j<wlen[i];j++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	printf("------------------------------------------------------");
	printf("\nvertical histogram\n");

	int fmax;
	fmax=0;
	for(i=0;i<10;i++)
	{
		if(wlen[i]>fmax)
		{
			fmax=wlen[i];
		}
	}
	++fmax;

	for (i=fmax;i>0;i--)
	{
		printf("|");
		for(j=0;j<10;j++)
		{
			if(wlen[j]>=i)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	printf("-----------------------------------------\n|");
	for(i=0;i<10;i++)
		printf("%d",i);

}
