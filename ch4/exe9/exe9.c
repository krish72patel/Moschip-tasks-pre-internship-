/*Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
what their properties ought to be if an EOF is pushed back, then implement your design. */

#include <stdio.h>
#include <stdlib.h>     // for atof
#include <math.h>       // for sin, exp, pow
#include <ctype.h>      // for isalpha, isupper, isdigit
#define MAXVAL  100     // stack depth
#define MAXOP   100     // max size of operand or operator
#define NUMBER  '0'     // signal returned by getop when a number is found
#define SINE    'S'     // code used for sin
#define EXP     'E'     // code used for exp
#define POW     'P'     // code used for pow
#define VAR     'V'     // code used for variables A–Z
int    sp = 0;              // next free position in stack
double val[MAXVAL];         // value stack
int pushed_char;
int p_flag = 0;             // 1 if a char is currently pushed back, else 0
void   push(double f);
double pop(void);
void   peek(void);
void   duplicate(void);
void   swap(void);
void   clear(void);
int    getop(char s[]);
int    getch(void);
void   ungetch(int c);


void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("\nStack has overflown, cannot push variable f: %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
        printf("\nError: Stack is Empty\n");

    return 0;
}

void peek(void)
{
    if (sp < MAXVAL && sp > 0)
        printf("\nThe Value at Top of Stack is : %g\n", val[sp - 1]);
    else
        printf("\nStack is Empty, No Value to Print\n");
}

void duplicate(void)
{
    if (sp < MAXVAL && sp > 0)
    {
        printf("\nPrinting now the top two values of stack Before Duplicating\n");

        for (int i = sp - 1, j = 0; j < 2 && i - j >= 0; j++)
            printf("\n sp: %d , value at sp: %g\n", i - j, val[i - j]);

        printf("\nDuplicating the Value at Top of stack\n");

        val[sp] = val[sp - 1];
        sp++;   // increment sp to point to next free value

        printf("\nPrinting now the top two values of stack after Duplicating\n");

        for (int i = sp - 1, j = 0; j < 2 && i - j >= 0; j++)
            printf("\n sp: %d , value at sp: %g\n", i - j, val[i - j]);
    }
    else
        printf("\nStack is Empty, no Value to Duplicate\n");
}

void swap(void)
{
    if (sp < MAXVAL && sp > 0)
    {
        printf("\nPrinting now the top two values of stack Before Swapping\n");

        for (int i = sp - 1, j = 0; j < 2 && i - j >= 0; j++)
            printf("\n sp: %d , value at sp: %g\n", i - j, val[i - j]);

        printf("\nSwapping the Value at Top of stack\n");

        double temp = val[sp - 1];   // put the top value in temp
        val[sp - 1] = val[sp - 2];   // swap top with one below
        val[sp - 2] = temp;

        printf("\nPrinting now the top two values of stack after Swapping\n");

        for (int i = sp - 1, j = 0; j < 2 && i - j >= 0; j++)
            printf("\n sp: %d , value at sp: %g\n", i - j, val[i - j]);
    }
    else
        printf("\nStack is Empty, no Value to Swap\n");
}

void clear(void)
{
    if (sp < MAXVAL && sp > 0)
    {
        printf("\nPrinting now the values of stack Before Clearing\n");

        for (int i = sp - 1, j = 0; j < sp && i - j >= 0; j++)
            printf("\n sp: %d , value at sp: %g\n", i - j, val[i - j]);

        printf("\nClearing the Value of stack\n");

        sp = 0;
        val[sp] = '\0';

        printf("\nPrinting now the values of stack after Clearing\n");

        peek();
    }
    else
        printf("\nStack is Empty, no Value to Clear\n");
}

int getch(void)
{
    if (p_flag == 1)
    {
        p_flag = 0;
        return pushed_char;
    }
    else
        return getchar();
}

void ungetch(int c)
{
    if (p_flag == 1)
        printf("Buffer for getchar and ungetchar is full...\n");
    else
    {
        pushed_char = c;   // may even be EOF
        p_flag = 1;
    }
}

int getop(char s[])
{
    int i, c;

    // skip blanks and tabs
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';
    i = 0;

    // check for variable: A-Z
    if (isalpha(c) && isupper(c) && !isdigit(c))
    {
        return VAR;    // s[0] already holds the variable letter
    }

    // check if negative number
    if (s[0] == '-')
    {
        c = getch();
        if (isdigit(c) || c == '.')
            s[++i] = c;   // part of a negative number
        else
        {
            ungetch(c);   // it's actually just '-'
            return '-';
        }
    }

    // check for sine: "sin"
    if (s[0] == 's')
    {
        c = getch();

        if (c == 'i')
        {
            c = getch();

            if (c == 'n')
                return SINE;
            else
                return c; // something like "sik"
        }
        else
        {
            // maybe 's' for swap
            ungetch(c);
            return 's';
        }
    }

    // check for exponent: "exp"
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

    // check for power: "pow"
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
            // maybe 'p' for peek
            ungetch(c);
            return 'p';
        }
    }

    // if not digit and not '.', return char as operator or other
    if (!isdigit(c) && c != '.')
        return c;

    // collect integer part
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;

    // collect fraction part
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';

    // NOTE (Exercise 4-9): always unget the first non-digit, INCLUDING EOF
    ungetch(c);

    return NUMBER;
}

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];
    double vars[26];   // A-Z variables
    double last = 0;   // last printed value

    for (int i = 0; i < 26; i++)
        vars[i] = 0;

      printf(" operators-> +   -   *   /   %%   sin   exp   pow\n");
    printf(" p -> peek top of stack\n");
    printf(" d -> duplicate top value\n");
    printf(" s -> swap top 2 values\n");
    printf(" c -> clear stack\n");
    printf(" v -> last printed value\n");
    printf(" A-Z -> variables, example: 5 A = \n");
    printf("v to print or use the most recently printed value\n");
    printf("\nEnter your commands here:\n");

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

            case VAR:
            {
                char name = s[0];  // variable letter 'A'..'Z'
                int ch;

                // Peek next non-space character
                do {
                    ch = getch();
                } while (ch != EOF && (ch == ' ' || ch == '\t'));

                if (ch == '=')
                {
                    double v = pop();
                    vars[name - 'A'] = v;
                    push(v);   // keep it on stack too
                }
                else
                {
                    // not an assignment: restore char & push variable value
                    ungetch(ch);
                    push(vars[name - 'A']);
                }
            }
            break;

            case 'v':
                push(last);
                printf("\nThe Value of Last Printed Variable is %g\n", last);
                break;

            case '\n':
            {
                double res = pop();
                last = res;
                printf("\nResult of Operation is: %g\n", res);
            }
            break;

            default:
                printf("\nError Occured Unknown Command: %s\n", s);
                break;
        }
    }

    printf("\nEOF Encountered, Terminating the Program Now...\n");

    return 0;
}

