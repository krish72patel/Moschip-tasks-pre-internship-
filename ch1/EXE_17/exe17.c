#include <stdio.h>
#include <string.h>

#define MAXLINE 1000 
#define MAXLINES 1000  
#define THRESHOLD 80  

int get_line(char line[], int maxline);

int main() 
{
	char lines[MAXLINES][MAXLINE];
	char line[MAXLINE];
	int len, count = 0;
	while ((len = get_line(line, MAXLINE)) > 0 && count < MAXLINES) 
	{
		if (len > THRESHOLD) 
		{
	        strcpy(lines[count], line);
	        count++;
		}
	}
			    
	for (int i = 0; i < count; i++) 
	{
		printf("%s", lines[i]);
	}
			        
return 0;
}
int get_line(char s[], int lim) 
{
	int c, i;
	       
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
	{
		s[i] = c;
	}
		    
	if (c == '\n'&& i<lim-1) 
	{
		s[i] = c;
		++i;
	}
	if(i<lim-1)
	{
		s[i] = '\0';
	}
	else
	{
		s[lim-1]='\0';
	}
return i;
}
