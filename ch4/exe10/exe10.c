/*An alternate organization uses getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach.*/

#include <stdio.h>
#include <stdlib.h>   // for atof
#include <ctype.h>    // for isdigit
#define MAXOP   100    // max size of operand or operator
#define MAXVAL  100    // max depth of value stack
#define MAXLINE 1000   // max length of input line
#define NUMBER '0'     // signal that a number was found
int sp = 0;               // next free stack position
double val[MAXVAL];       // value stack
char line[MAXLINE];       // current input line
int  line_pos = 0;        // current position in line[]
int    getop(char s[]);
void   push(double f);
double pop(void);
int    my_getline(char s[], int lim);
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    printf("RPN Calculator\n");
    printf("Supported: +  -  *  /  %%\n");
    printf("Enter expressions in Reverse Polish Notation.\n\n");
    while (my_getline(line, MAXLINE) > 0) {
        line_pos = 0;     // start at beginning of this line

        while ((type = getop(s)) != '\n') { // process tokens in this line
            switch (type) {

            case NUMBER:
                push(atof(s));
                break;

            case '+':
                push(pop() + pop());
                break;

            case '*':
                push(pop() * pop());
                break;

            case '-':
                op2 = pop();
                push(pop() - op2);
                break;

            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;

            case '%':
                op2 = pop();
                if ((int)op2 != 0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor in %%\n");
                break;

            case ' ':  // ignore stray spaces
            case '\t':
                break;

            default:
                printf("error: unknown command %s\n", s);
                break;
            }
        }

        // end of line ? show result if anything on stack
        if (sp > 0)
            printf("Result: %.8g\n", pop());
    }

    return 0;
}
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int my_getline(char s[], int lim)
{
    int c, i = 0;

    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

int getop(char s[])
{
    int i = 0;
    int c;

    /* Skip spaces and tabs inside the line buffer */
    while ((c = line[line_pos]) == ' ' || c == '\t')
        line_pos++;

    /* End of string or end of line */
    if (c == '\0')
        return '\n';       // treat end of line as newline
    if (c == '\n') {
        line_pos++;
        return '\n';
    }

    s[i++] = c;
    s[i] = '\0';
    line_pos++;

    /* If not digit, dot, or minus, return it directly (operator) */
    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    /* Handle negative number vs minus operator */
    if (c == '-') {
        int next = line[line_pos];
        if (!isdigit(next) && next != '.')
            return '-';     // it's just minus operator
        // else: it's a negative number, continue collecting
        c = next;
        s[i++] = c;
        line_pos++;
    }

    /* Collect integer part */
    if (isdigit(c)) {
        while (isdigit(line[line_pos])) {
            s[i++] = line[line_pos++];
        }
    }

    /* Collect fraction part */
    if (line[line_pos] == '.') {
        s[i++] = line[line_pos++];   // copy dot
        while (isdigit(line[line_pos])) {
            s[i++] = line[line_pos++];
        }
    }

    s[i] = '\0';
    return NUMBER;
}
