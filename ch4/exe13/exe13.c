/*Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the
string s in place.*/

#include<stdio.h>
#include<string.h>

#define MAXLINE 100

void getLine(char line[], int max);

void reverse(char []);

char s[MAXLINE];
int i=0,j;

int main()
{
    printf("Enter a String:\n");
    getLine(s,MAXLINE);

    printf("Entered String is: %s\n",s);
    
    j=strlen(s)-1;

    reverse(s);

    printf("The String after calling reverse() is:\n%s\n",s);

    return 0;
}

void reverse(char s[])
{
    int i_cp=i,j_cp=j;//again local variables are initilized to store index values associated with that call

    if(i<j)
    {
        i++,j--;
        reverse(s);
    }

    int temp=s[j_cp];
    s[j_cp]=s[i_cp];
    s[i_cp]=temp;

}

//simple function to get a line

void getLine(char s[], int lim)
{
    int c, i;
    
    i = 0;
    
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;

    s[i] = '\0';
    
}
