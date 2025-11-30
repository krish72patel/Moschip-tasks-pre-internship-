/*Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the stack. */


#include <stdio.h>
#include <stdlib.h>   // for atof
#include <ctype.h>    // for isdigit
#define MAXOP  100    // max size of operand or operator string
#define NUMBER '0'    // signal that a number was found
#define MAXVAL 100    // max depth of stack
#define BUFSIZE 100   // buffer size for getch / ungetch

int sp = 0;              // stack pointer
double val[MAXVAL];      // stack
char buffer[BUFSIZE];//for getch and ungetch
int bufp = 0;            // buffer pointer
int    getop(char s[]);
void   push(double f);
double pop(void);
void   peek(void);
void   duplicate(void);
void   swap(void);
void   clear(void);
int  getch(void);
void ungetch(int c);




int main(void)
{
    int type;
    double op2;    
    char s[MAXOP];

    printf("\naddition \nsubtraction \nmultiplication \ndivision \n");
    printf("duplicate (d)  : duplicate the top element of stack\n");
	printf("peek (p)       : print top element of stack without popping\n");
    printf("clear (c)      : clear the current stack\n");
	printf("swap (s)       : swap the two top elements of stack\n");
    printf("Sine (sin)\nExponent (exp)\nPower (pow)\n");

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s)); 
                break;

            case '+':
                push(pop() + pop());
                break;

            case '-':
                op2 = pop();
                push(pop() - op2);
                break;

            case '*':
                push(pop() * pop());
                break;

            case '%':
                op2 = pop();
                push(((int)pop()) % ((int)op2));
                break;

            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("\nError: zero divisor\n");
                break;

            case 'p':
                peek();
                break;

            case 'd':
                duplicate();
                break;

            case 's':
                swap();
                break;

            case 'c':
                clear();
                break;

            case '\n':
                printf("\nResult of Operation is: %g\n", pop());
                break;

            default:
                printf("\nError: Unknown Command %s\n", s);
                break;
        }
    }

    return 0;
}

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("\nStack overflow: cannot push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("\nError: stack empty\n");
        return 0.0;
    }
}

void peek(void)
{
    if (sp > 0 && sp <= MAXVAL)
        printf("\nTop of stack: %g\n", val[sp - 1]);
    else
        printf("\nStack is empty, nothing to peek\n");
}

void duplicate(void)
{
    if (sp > 0 && sp < MAXVAL)
    {
        printf("\nTop two values before duplicating:\n");
        int i, j;
        for (i = sp - 1, j = 0; j < 2 && i - j >= 0; j++)
            printf(" sp: %d , value: %g\n", i - j, val[i - j]);

        printf("\nDuplicating top of stack...\n");

        val[sp] = val[sp - 1];
        sp++;

        printf("\nTop two values after duplicating:\n");
        for (i = sp - 1, j = 0; j < 2 && i - j >= 0; j++)
            printf(" sp: %d , value: %g\n", i - j, val[i - j]);
    }
    else
        printf("\nStack is empty, nothing to duplicate\n");
}

void swap(void)
{
    if (sp > 1)
    {
        printf("\nTop two values before swapping:\n");
        int i, j;
        for (i = sp - 1, j = 0; j < 2; j++)
            printf(" sp: %d , value: %g\n", i - j, val[i - j]);

        printf("\nSwapping top two values...\n");

        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;

        printf("\nTop two values after swapping:\n");
        for (i = sp - 1, j = 0; j < 2; j++)
            printf(" sp: %d , value: %g\n", i - j, val[i - j]);
    }
    else
        printf("\nNeed at least two values to swap\n");
}

void clear(void)
{
    if (sp > 0)
    {
        printf("\nStack before clearing:\n");
        int i, j;
        for (i = sp - 1, j = 0; j < sp; j++)
            printf(" sp: %d , value: %g\n", i - j, val[i - j]);

        printf("\nClearing stack...\n");

        sp = 0;
        val[sp] = 0.0;   // optional, just sets first position to 0

        printf("\nStack after clearing:\n");
        peek();
    }
    else
        printf("\nStack is already empty\n");
}


int getch(void)
{
    return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buffer[bufp++] = c;
}


int getop(char s[])
{
    int i, c;

    // skip spaces and tabs
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    i = 0;

    // handle negative number vs minus operator
    if (s[0] == '-')
    {
        int next = getch();
        if (isdigit(next) || next == '.')
        {
            s[++i] = next;  // part of a negative number
            c = next;
        }
        else
        {
            ungetch(next);  // it's not a number, so treat '-' as operator
            return '-';
        }
    }

    // if not digit and not '.', return as operator
    if (!isdigit(c) && c != '.')
        return c;

    // collect integer part
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;

    // collect fractional part
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}
