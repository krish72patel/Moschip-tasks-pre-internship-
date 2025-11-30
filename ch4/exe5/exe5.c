/*Add access to library functions like sin, exp, and pow. */

#include <stdio.h>
#include <stdlib.h>   // for atof
#include <math.h>     // for sin, exp, pow
#include <ctype.h>    // for isdigit
#define MAXOP   100    // max size of operand or operator
#define MAXVAL  100    // max depth of value stack
#define BUFSIZE 100    // buffer size for getch / ungetch
#define NUMBER '0'     // signal that a number was found
#define SINE   'S'     // code for sin()
#define EXP    'E'     // code for exp()
#define POW    'P'     // code for pow()

int sp = 0;               // next free stack position
double val[MAXVAL];       // value stack
char buffer[BUFSIZE];
int bufp = 0;             // next free position in buffer
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
    double op2;        // second operand for - and /
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

            case SINE:
                push(sin(pop()));
                break;

            case EXP:
                push(exp(pop()));
                break;

            case POW:
                op2 = pop();
                push(pow(pop(), op2));
                break;

            case '\n':
                printf("\nResult of Operation is: %g\n", pop());
                break;

            default:
                printf("\nError Occured Unknown Command: %s\n", s);
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
        printf("\nStack has overflown cannot push variable f: %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
        printf("\nError Stack is Empty\n");

    return 0;
}

void peek(void)
{
    if (sp < MAXVAL && sp > 0)
        printf("\nThe Value at Top of Stack is : %g\n", val[sp - 1]);
    else
        printf("\nStack is Empty No Value to Print\n");
}

void duplicate(void)
{
	int i,j;
    if (sp < MAXVAL && sp > 0)
    {
        printf("\nPrinting now the top two values of stack Before Duplicating\n");

        for (i = sp - 1, j = 0; j < 2 && i - j >= 0; j++)
            printf("\n sp: %d , value at sp: %g\n", i - j, val[i - j]);

        printf("\nDuplicating the Value at Top of stack\n");

        val[sp] = val[sp - 1];
        sp++;  // increment sp to point to next free value

        printf("\nPrinting now the top two values of stack after Duplicating\n");

        for (i = sp - 1, j = 0; j < 2 && i - j >= 0; j++)
            printf("\n sp: %d , value at sp: %g\n", i - j, val[i - j]);
    }
    else
        printf("\nStack is Empty no Value to Duplicate\n");
}

void swap(void)
{
	int i,j;
    if (sp < MAXVAL && sp > 1)
    {
        printf("\nPrinting now the top two values of stack Before Swapping\n");

        for (i = sp - 1, j = 0; j < 2; j++)
            printf("\n sp: %d , value at sp: %g\n", i - j, val[i - j]);

        printf("\nSwapping the Value at Top of stack\n");

        double temp = val[sp - 1];   // top value
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;

        printf("\nPrinting now the top two values of stack after Swapping\n");

        for (i = sp - 1, j = 0; j < 2; j++)
            printf("\n sp: %d , value at sp: %g\n", i - j, val[i - j]);
    }
    else
        printf("\nStack is Empty or has only one value, no Value to Swap\n");
}

void clear(void)
{
	int i,j;
    if (sp < MAXVAL && sp > 0)
    {
        printf("\nPrinting now the values of stack Before Clearing\n");

        for (i = sp - 1, j = 0; j < sp; j++)
            printf("\n sp: %d , value at sp: %g\n", i - j, val[i - j]);

        printf("\nClearing the Value of stack\n");

        sp = 0;
        val[sp] = '\0';

        printf("\nPrinting now the values of stack after Clearing\n");

        peek();
    }
    else
        printf("\nStack is Empty no Value to Clear\n");
}

int getch(void)
{
    return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("Buffer for getchar and ungetchar is full...\n");
    else
        buffer[bufp++] = c;
}

int getop(char s[])
{
    int i, c;

    // skip whitespace and tabs
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;

    // check for negative number
    if (s[0] == '-')
    {
        c = getch();
        if (isdigit(c) || c == '.')
            s[++i] = c;
        else
        {
            ungetch(c);
            return '-'; 
        }
    }

    if (s[0] == 's')
    {
        c = getch();
        if (c == 'i')
        {
            c = getch();
            if (c == 'n')
                return SINE;
            else
                return c; // invalid sequence
        }
        else
        {
            // might be 's' for swap
            ungetch(c);
            return 's';
        }
    }

    // check for exponent operator "exp"
    if (s[0] == 'e')
    {
        c = getch();
        if (c == 'x')
        {
            c = getch();
            if (c == 'p')
                return EXP;
            else
                return c;
        }
        return c;
    }

    // check for power operator "pow"
    if (s[0] == 'p')
    {
        c = getch();
        if (c == 'o')
        {
            c = getch();
            if (c == 'w')
                return POW;
            else
                return c;
        }
        else
        {
            // might be 'p' for peek
            ungetch(c);
            return 'p';
        }
    }

    // if not digit and not '.', return it directly
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
