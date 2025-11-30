/*Modify getop so that it doesn't need to use ungetch. Hint: use an internal
static variable*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAXOP   100
#define MAXVAL  100
#define NUMBER  '0'
#define SINE    'S'
#define EXP     'E'
#define POW     'P'
#define VAR     'V'
int sp = 0;
double val[MAXVAL];
void push(double f) {
    if (sp < MAXVAL) val[sp++] = f;
    else printf("error: stack full\n");
}

double pop(void) {
    if (sp > 0) return val[--sp];
    else { printf("error: stack empty\n"); return 0; }
}
int getop(char s[])
{
    static int last_char = 0;     // replaces ungetch
    int c, i = 0;

    if (last_char != 0) { c = last_char; last_char = 0; }
    else c = getchar();

    while (c == ' ' || c == '\t') // skip spaces
        c = getchar();

    s[0] = c;
    s[1] = '\0';

    if (isalpha(c) && isupper(c)) return VAR;

    if (c == '-') {
        int next = getchar();
        if (isdigit(next) || next == '.') s[++i] = next;
        else { last_char = next; return '-'; }
        c = next;
    }

    if (!isdigit(c) && c != '.') return c;

    if (isdigit(c))
        while (isdigit(c = getchar())) s[++i] = c;

    if (c == '.')
        while (isdigit(c = getchar())) s[++i] = c;

    s[++i] = '\0';

    if (c != EOF) last_char = c;
    return NUMBER;
}

int main() {
    int type;
    double op2;
    char s[MAXOP];

    printf("RPN Calculator – No ungetch Version\n");

    while ((type = getop(s)) != EOF) {
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
                if (op2 != 0.0) push(pop() / op2);
                else printf("error: zero divisor\n");
                break;

            case '\n':
                printf("Result: %g\n", pop());
                break;

            default:
                printf("Unknown command: %s\n", s);
                break;
        }
    }
    return 0;
}
