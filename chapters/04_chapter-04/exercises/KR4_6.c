#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP   100
#define NUMBER  '0'
#define NAME    'n'
#define VARIABLE 'v'
#define ASSIGN  '='
#define MAXVAL  100
#define BUFSIZE 100

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void clearStack(void);

double vars[26];
int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;
int lastVar = -1;

int main(void)
{
    int type;
    double op2, result;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            if (strcmp(s, "sin") == 0)
                push(sin(pop()));
            else if (strcmp(s, "exp") == 0)
                push(exp(pop()));
            else if (strcmp(s, "pow") == 0) {
                op2 = pop();
                push(pow(pop(), op2));
            } else
                printf("error: unknown function %s\n", s);
            break;
        case VARIABLE:
            push(vars[s[0] - 'a']);
            lastVar = s[0] - 'a';
            break;
        case ASSIGN:
            if (lastVar >= 0) {
                vars[lastVar] = pop();
                push(vars[lastVar]);
            } else
                printf("error: no variable to assign to\n");
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
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor for modulus\n");
            break;
        case '?':
            if (sp > 0)
                printf("top: %.8g\n", val[sp-1]);
            else
                printf("error: stack empty\n");
            break;
        case 'd':
            if (sp > 0)
                push(val[sp-1]);
            else
                printf("error: stack empty\n");
            break;
        case 's':
            if (sp > 1) {
                op2 = val[sp-1];
                val[sp-1] = val[sp-2];
                val[sp-2] = op2;
            } else
                printf("error: not enough elements to swap\n");
            break;
        case 'c':
            clearStack();
            break;
        case '\n':
            result = pop();
            printf("\t%.8g\n", result);
            vars['v' - 'a'] = result;
            break;
        default:
            printf("error: unknown command %s\n", s);
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
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    printf("error: stack empty\n");
    return 0.0;
}

void clearStack(void)
{
    sp = 0;
}

int getop(char s[])
{
    int i = 0, c, next;
    while ((c = getch()) == ' ' || c == '\t')
        ;
    s[i++] = c;
    s[i] = '\0';
    if (isalpha(c)) {
        while (isalpha(s[i++] = c = getch()))
            ;
        s[i-1] = '\0';
        if (c != EOF)
            ungetch(c);
        if (strlen(s) == 1)
            return VARIABLE;
        else
            return NAME;
    }
    if (c == '=')
        return ASSIGN;
    if (c == '-') {
        next = getch();
        if (isdigit(next) || next == '.') {
            s[i++] = next;
            c = next;
        } else {
            ungetch(next);
            return '-';
        }
    } else if (!isdigit(c) && c != '.') {
        return c;
    }
    if (isdigit(c)) {
        while (isdigit(s[i++] = c = getch()))
            ;
    }
    if (c == '.') {
        while (isdigit(s[i++] = c = getch()))
            ;
    }
    s[i-1] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp < BUFSIZE)
        buf[bufp++] = c;
    else
        printf("ungetch: too many characters\n");
}
