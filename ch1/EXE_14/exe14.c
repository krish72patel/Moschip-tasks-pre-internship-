#include<stdio.h>
#include<stdlib.h>
main(){
	int c,i,nwhite,nother,j;
	int ndigit[10];
	nwhite=nother=0;
	for(i=0;i<10;i++)
	{
		ndigit[i]=0;
	}
	while((c=getchar())!=EOF)
	{
		if(c>='0' && c<='9')
		{
			++ndigit[c-'0'];
		}
		else if ( c==' ' || c== '\n'  || c=='\t')
		{
			++nwhite;
		}
		else{
			++nother;
		}
	}
	printf("horizontal histogram\n");
	printf("digits\n");
	for(i=0;i<10;i++)
	{
		printf("%d------",i);
		for(j=0;j<ndigit[i];j++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("white--");
	for(i=0;i<nwhite;i++)
	{
		printf("*");
	}
	printf("\n");
	printf("other--");
	for(i=0;i<nother;i++)
	{
	printf("*");
	}
	printf("\n");
	printf("------------------------------------------------------");
	printf("\nvertical histogram\n");

	int fmax;
	fmax=0;
	for(i=0;i<10;i++)
	{
		if(ndigit[i]>fmax)
		{
			fmax=ndigit[i];
		}
	}
	if(nwhite>fmax)
	{
		fmax=nwhite;
	}
	if(nother>fmax)
	{
		fmax=nother;
	}
	++fmax;



	for (i=fmax;i>0;i--)
	{
		printf("|");
		for(j=0;j<10;j++)
		{
			if(ndigit[j]>=i)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\t");
		if(nwhite>=i)
		{
			printf("*");
		}
		else
		{
			printf(" ");
		}
		printf("\t");

		if(nother >=i)
		{
			printf("*");
		}
		else
		{
			printf(" ");
		}
		printf("\n");
	}

	printf("-----------------------------------------\n|");
	for(i=0;i<10;i++)
		printf("%d",i);
	printf("   white   other\n");



}
