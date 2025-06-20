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

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void ungets(char[]);
void clearStack(void);

double vars[26];
int sp = 0;
double val[MAXVAL];
int buf = 0;         /* single-character pushback buffer */
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

int getch(void)
{
    int c;
    if (buf != 0) {
        c = buf;
        buf = 0;
        return c;
    }
    return getchar();
}

void ungetch(int c)
{
    if (buf == 0)
        buf = c;
    else
        printf("ungetch: buffer full\n");
}

void ungets(char s[])
{
    int len = strlen(s);
    while (len > 0)
        ungetch(s[--len]);
}