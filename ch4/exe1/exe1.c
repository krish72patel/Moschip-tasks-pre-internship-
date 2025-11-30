/*Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.*/


#include<stdio.h>
#define max 100
int strind(char [],char []);

int main()
{
	char s[max],t[max];
	int i,lim=max;
	int index;
	char c;
	printf("enter string to find in\n");
	for (i=0;i<lim && (c=getchar())!=EOF && c!='\n';i++)
	{
		s[i]=c;
	}
	s[i]='\0';
	printf("enter string to find in above string\n");
	for (i=0;i<lim && (c=getchar())!=EOF && c!='\n';i++)
	{
		t[i]=c;
	}
	t[i]='\0';
	index=strind(s,t);
	if(index== -1)
	{
		printf("2nd string not present in first one\n");
	}
	else
	{
		printf("rignt most index of string:%d\n",index);
	}

}
int strind(char s[],char t[])
{	
	int i,j,k,ind;
	i=j=k=0;
	ind =-1;
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] != '\0' && s[j] == t[k]; j++, k++)
		{
		}

	 	if (t[k] == '\0') 
	 	{
	 		ind= j-1;
	 	}
	 }
	
	return ind;
}
