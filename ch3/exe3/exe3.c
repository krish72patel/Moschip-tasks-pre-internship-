/*Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case
and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a
leading or trailing - is taken literally.*/

#include <stdio.h>
#define max 100
int is_valid(char c1, char c2) {
    
    if (c1 >= '0' && c1 <= '9' && c2 >= '0' && c2 <= '9' && c1 <= c2)
    {
		return 1;
	}
    if (c1 >= 'a' && c1 <= 'z' && c2 >= 'a' && c2 <= 'z' && c1 <= c2)
    {
    	return 1;
	}
    if (c1 >= 'A' && c1 <= 'Z' && c2 >= 'A' && c2 <= 'Z' && c1 <= c2)
    {
		return 1;
	}
    return 0;
}

void expand(char s1[], char s2[]) 
{
    int i, j;  
    char c1, c2; 
    char c;
    i = 0;
    j = 0;
    while ((c1 = s1[i++]) != '\0') {
        if (c1 == '-' && i > 1 && s1[i] != '\0')//i>1 bcz i incremented once in above line 
		{
            c2 = s1[i];
            if (is_valid(s1[i-2], c2)) 
			{
                j--;//j was pointing at '-' so j-- start expanding at index of starting range char
                for (c = s1[i-2]; c <= c2; c++)//s1[i-2]->starting char c2->ending char
				{
                    s2[j++] = c;
                }
                
                i++;//increment after expanding 
            } 
			else 
			{
                s2[j++] = c1;//copy char if invalid range 
            }
        } 
		else 
		{
            s2[j++] = c1;// copy if no '-' found
        }
    }
    s2[j] = '\0';
}

int main() 
{
    char s[max];
    char out[max];
    int i,lim=max;
    char c;
    for (i=0;i<lim&&(c=getchar())!=EOF&&c!='\n';i++)
    {
    	s[i]=c;
	}
	s[i]='\0';
    expand(s,out);
    printf("%s",out);
    return 0;
}
