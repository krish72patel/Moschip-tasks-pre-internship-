/* Write a function escape(s,t) that converts characters like newline and tab into
visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
function for the other direction as well, converting escape sequences into the real characters.*/

#include<stdio.h>
#define max 100
void escape(char s[],char t[]);
void unescape(char s[],char t[]);

int main()
{
	char t[max],s[max];
	int lim=max;
	int i,flag;
	char c;
	printf("enter a string\n");
	for(i=0;i<lim && (c=getchar())!=EOF && c !='\n' ;i++)//string input
	{
		t[i]=c;
	}
	t[i++]='\0';//end of string
	printf("enter 1 to escape and 0 to unescape\n");
	scanf ("%d",&flag);
	if (flag==1)
	{
		escape(s,t);
	}
	else if(flag==0)
	{
		unescape(s,t);
	}
	else
	{
		printf("invalid number");
		return 0;
	}
	printf("%s",s);
}

void escape(char s[],char t[])
{
	int i,j;
	i=j=0;
	while(t[i]!='\0')
	{
		switch (t[i])//replace \t and \n with visible char
		{
			case '\t':
				s[j++]='\\';
				s[j++]='t';
			    break;
			case '\n':
				s[j++]='\\';
				s[j++]='n';
				break;
			default :
				s[j++]=t[i];
				break;
		}
		i++;
	}
	s[j]='\0';
	
}
void unescape(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (t[i] != '\0') 
	{
        if (t[i] == '\\')//check if any'\' there 
		{
            i++;
            switch (t[i]) // check if n or t present after '\'
			{
                case 'n':
                    s[j++] = '\n'; 
                    break;
                case 't':
                    s[j++] = '\t'; 
                    break;
                case '\\':
                    s[j++] = '\\';
                    break;
                default:
                    s[j++] = '\\';
                    s[j++] = t[i];
                    break;
            }
        } 
		else 
		{
            s[j++] = t[i];
        }
        
        i++;
    }
    s[j] = '\0'; 
}
