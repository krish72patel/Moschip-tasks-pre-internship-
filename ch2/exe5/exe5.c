/*Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the
location.)*/


#include <stdio.h>
#define MAX 100

int any(char s1[], char s2[]);

int main() {
        int i;
        char c;
        char s1[MAX];
        char s2[MAX];
        printf("enter string1\n");
        for (i=0;(c=getchar())!='\n'&& i<MAX;i++)
        {
                s1[i]=c;
        }
        s1[++i]='\0';
        printf("enter string2\n");
        for(i=0;(c=getchar())!='\n'&&i<MAX;i++)
        {
                s2[i]=c;
        }
        s2[++i]='\0';
        i=any(s1,s2);
        printf("first match index is %d",i);
    return 0;
}

int any(char s1[], char s2[]) {
    int i, j;
    for (i = 0; s1[i] != '\0'; i++) 
    {
        for (j = 0; s2[j] != '\0'; j++) 
	{
            if (s1[i] == s2[j]) 
	    {
                return i;
            }
        }
    }
return -1;
}
