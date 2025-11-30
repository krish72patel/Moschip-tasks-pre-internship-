/*Suppose that there will never be more than one character of pushback. Modify
getch and ungetch accordingly. */


#include <stdio.h>
#include <stdlib.h>     // for atof()
#include <math.h>       // for sin(), exp(), pow()
#include <ctype.h>      // for isalpha(), isdigit(), isupper()
#define MAXVAL   100    // stack size
#define MAXOP    100    // max input length
#define NUMBER   '0'    // number found
#define SINE     'S'    // sin()
#define EXP      'E'    // exp()
#define POW      'P'    // pow()
#define VAR      'V'    // A-Z variable

int sp = 0;                   // stack pointer
double val[MAXVAL];           // value stack
char pushed_char;
int p_flag = 0;
double vars[26];              // variables 'A' to 'Z'
double last = 0;
int getop(char s[]);
int getch(void);
void ungetch(int);
void push(double);
double pop(void);
void peek(void);
void duplicate(void);
void swap(void);
void clear(void);

int main()
{
    for(int i=0 ; i<26 ; i++)
        vars[i] = 0;       // initialize A-Z to 0
    printf(" operators-> +   -   *   /   %%   sin   exp   pow\n");
    printf(" p -> peek top of stack\n");
    printf(" d -> duplicate top value\n");
    printf(" s -> swap top 2 values\n");
    printf(" c -> clear stack\n");
    printf(" v -> last printed value\n");
    printf(" A-Z -> variables, example: 5 A = \n");
    printf("\nENTER YOUR EXPRESSION BELOW:\n\n");

    int type;
    double op2;
    char s[MAXOP];

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
                push((int)pop() % (int)op2);
                break;

            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("ERROR: ZERO DIVISOR\n");
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
                char name = s[0];  // A-Z
                int ch;

                // Skip spaces
                do { ch = getch(); }
                while (ch == ' ' || ch == '\t');

                if (ch == '=') {
                    double v = pop();
                    vars[name - 'A'] = v;
                    push(v);
                } else {
                    ungetch(ch);      // return extra character
                    push(vars[name - 'A']);
                }
            }
            break;

            case 'v':
                push(last);
                printf("Last printed value = %g\n", last);
                break;

            case '\n':
                {
                    double ans = pop();
                    last = ans;        // store as "most recent"
                    printf("RESULT = %g\n", ans);
                }
                break;

            default:
                printf("ERROR: UNKNOWN COMMAND %s\n", s);
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
        printf("ERROR: STACK FULL - can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
        printf("ERROR: STACK EMPTY\n");
    return 0;
}

void peek(void)
{
    if (sp > 0)
        printf("TOP OF STACK = %g\n", val[sp - 1]);
    else 
        printf("STACK EMPTY\n");
}

void duplicate(void)
{
    if (sp > 0 && sp < MAXVAL)
        val[sp] = val[sp - 1], sp++;
    else
        printf("CANNOT DUPLICATE (Stack empty or full)\n");
}

void swap(void)
{
    if (sp > 1)
    {
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    }
    else
        printf("CANNOT SWAP (Need 2 values)\n");
}

void clear(void)
{
    sp = 0;
    printf("STACK CLEARED\n");
}

int getch(void)
{
    if(p_flag == 1)
    {
        p_flag = 0;
        return pushed_char;
    }
    return getchar();
}

void ungetch(int c)
{
    if(p_flag == 1)
        printf("ERROR: ONLY 1 CHAR CAN BE PUSHED BACK\n");
    else
    {
        pushed_char = c;
        p_flag = 1;
    }
}

int getop(char s[])
{
    int i, c;

    // Skip whitespace
    while ((s[0] = c = getch()) == ' ' || c == '\t');

    s[1] = '\0';
    i = 0;

    // ======== Variable case: A-Z ========
    if (isalpha(c) && isupper(c))
        return VAR;

    // ======== Negative Number Handling ========
    if (c == '-')
    {
        int d = getch();
        if (isdigit(d) || d == '.')
            s[++i] = d;
        else {
            ungetch(d);
            return '-';
        }
    }

    // ======== sin =========
    if (c == 's') {
        if ((c = getch()) == 'i' && (c = getch()) == 'n')
            return SINE;
        else
            return 's';
    }

    // ======== exp =========
    if (c == 'e') {
        if ((c = getch()) == 'x' && (c = getch()) == 'p')
            return EXP;
        else
            return 'e';
    }

    // ======== pow =========
    if (c == 'p') {
        if ((c = getch()) == 'o' && (c = getch()) == 'w')
            return POW;
        else
            return 'p';
    }

    // ======== Not a number =========
    if (!isdigit(s[0]) && s[0] != '.')
        return s[0];

    /* ======== NUMBER Parsing ======== */
    while (isdigit(s[++i] = c = getch()));

    if (c == '.')
        while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';
    if (c != EOF) ungetch(c);

    return NUMBER;
}

