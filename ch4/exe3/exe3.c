/*Given the basic framework, it's straightforward to extend the calculator. Add the
modulus (%) operator and provisions for negative numbers. */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include<ctype.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define maxval 100
#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int sp=0;
double stac[maxval];
int getop(char []);
void push(double);
double pop();

int main()
{
  int type;
  double op2;
  char s[MAXOP];
  while ((type = getop(s)) != EOF) 
  {
	switch (type) 
	{
		case NUMBER: push(atof(s));
			     break;
		case '+': push(pop() + pop());
			  break;
		case '*': push(pop() * pop());
			  break;
		
		case '-':op2 = pop();
			 push(pop() - op2);
			 break;
	        case '/':op2 = pop();
			if (op2 != 0.0)
		  		push(pop() / op2);
			else
		  		printf("error: zero divisor\n");
		        break;
	        case '\n':printf("\t%.8g\n", pop());
			  break;
	      default:printf("error: unknown command %s\n", s);
	      break;
       }
 }
return 0;
}

void push (double f)
{
	if(sp<maxval)
	{
		stac[sp++]=f;
	}
	else
	{
		printf("stack full");
	}

} 	
double pop()
{
	if (sp>0)
	{
		return stac[--sp];
	}
	else
	{
		printf("stack empty");
		return 0;
	}
}
int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
	  return c; /* not a number */
	i = 0;
	if (isdigit(c)) /* collect integer part */
	while (isdigit(s[++i] = c = getch()));
	if (c == '.') /* collect fraction part */
	while (isdigit(s[++i] = c = getch()));
	s[i] = '\0';
	if (c != EOF)
	 ungetch(c);
return NUMBER;
}

int getch(void) /* get a (possibly pushed-back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
  if (bufp >= BUFSIZE)
   printf("ungetch: too many characters\n");
  else
   buf[bufp++] = c;
}
