#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
void reverse(char s[]);
int getline2(char s[], int lim);

int main() 
{
	char line[MAXLINE];
	int len;   
	while ((len = getline2(line, MAXLINE)) > 0) 
	{
		if (line[len - 1] == '\n') 
		{
			line[len - 1] = '\0';
			reverse(line);
			printf("%s\n", line);
		}
	       	else 
		{
			reverse(line);
			printf("%s", line);
	        }
	}		        
return 0;
}
int getline2(char s[], int lim) 
{
	int c, i;     
	i=0;
	while(i<lim-1)
	{
		if((c=getchar())==EOF || c=='\n')
		{
			break;
		}
		else
		{
			s[i] = c;
			++i;
		}
	}
	if (c == '\n') 
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
return i;
}
void reverse(char s[]) 
{
	int i, j;
	char temp;
		    
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) 
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
