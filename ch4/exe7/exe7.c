/*
Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp, or should it just use ungetch?
*/


#include<stdio.h>
#include<string.h>
#define BUFSIZE 100 //define the size of shared buffer where ungetch can put non-digit and non-EOF chars
#define MAXLINE 100
char buffer[BUFSIZE];
int bufp = 0; //set buffer pointer to 0 initial value this pointer indicates to the next free val in buff
char getch(void);
void ungetch(int);
void ungets(char s[]);
void getLine(char line[], int max);

int main()
{
    char s[MAXLINE];
    printf("Enter a String:\n");
    getLine(s,MAXLINE);
    printf("\nThe Entered String is: %s\n",s);
    printf("\nNow Calling ungets() with argument as i/p string\n");
    ungets(s);
    printf("\nNow Printing the Entered String using getch() which was pushed to buffer via ungets()\n");
    for(int i=0 ; i<strlen(s) ; i++)
        putchar(getch());
    return 0;
}
void ungets(char s[])
{
    int len=strlen(s);
    
    //unget each character of entered string in reverse order
    for(int i=len-1 ; i>-1 ; i--)
        ungetch(s[i]);
}

//define the getch function which getop will use in getop.c file
char getch(void)
{
    return ((bufp>0)?buffer[--bufp]:getchar());
}

//define the ungetch fuction which too will be used by getop in getop.c file
void ungetch(int c)
{
    if(bufp>=BUFSIZE)
        printf("Buffer for getchar and ungetchar is full...\n");
    else
        buffer[bufp++]=c;
}

/* getline: get line into s, return length */
void getLine(char s[], int lim)
{
    int c, i;
    
    i = 0;
    
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;
    
    s[i] = '\0';
    
}
