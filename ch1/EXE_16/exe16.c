 #include <stdio.h>
 #define MAXLINE 1000
int getline2(char s[], int lim);
void copy(char to[], char from[]);
main()
{
	int len; 
	int max;
	char line[MAXLINE];
	char longest[MAXLINE]; 
	max = 0;
	while ((len = getline2(line, MAXLINE)) > 0)
	{ if (len > max) {
			 max = len;
			 copy(longest, line);
			 }
	}
	if (max >0)
		 printf("%s", longest);
	return 0;
}
int getline2(char s[],int lim)
{

	int c, i;
	for (i=0;(c=getchar())!=EOF && c!='\n'; ++i)
	{
		if (i<lim -1)
		{
			s[i]=c;
		}
	}
	if (c == '\n') 
	{
	    	s[i] = c;
	     	++i;
	}
	if (i >= lim)// solved segmentation fault
	{
		s[lim - 1] = '\0';
	}
	else
	{
		s[i] = '\0';
	}
	return i;
	
}

void copy(char to[], char from[])
{

	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
	{	++i;}
}
