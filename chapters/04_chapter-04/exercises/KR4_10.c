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

int getop(char s[]);
void push(double f);
double pop(void);
void clearStack(void);

static double vars[26];
static int sp = 0;
static double val[MAXVAL];

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
            break;
        case ASSIGN:
            if (isalpha(s[0])) {
                vars[s[0] - 'a'] = pop();
                push(vars[s[0] - 'a']);
            } else
                printf("error: invalid variable name %s\n", s);
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
                double tmp = val[sp-1];
                val[sp-1] = val[sp-2];
                val[sp-2] = tmp;
            } else
                printf("error: not enough elements to swap\n");
            break;
        case 'c':
            clearStack();
            break;
        case '\n':
            result = pop();
            printf("\t%.8g\n", result);
            vars['v'-'a'] = result;
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

/* getop using getline */
int getop(char s[])
{
    static char line[MAXOP];
    static int li = 0;
    int i = 0;
    char c;

    if (li == 0) {
        if (fgets(line, MAXOP, stdin) == NULL)
            return EOF;
    }
    while ((c = line[li++]) == ' ' || c == '\t')
        ;
    if (c == '\0' || c == '\n') {
        li = 0;
        return c;
    }
    s[i++] = c;
    s[i] = '\0';
    if (isalpha(c)) {
        while (isalpha(c = line[li++]))
            s[i++] = c;
        s[i] = '\0';
        li--;
        if (strlen(s) == 1)
            return VARIABLE;
        else
            return NAME;
    }
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    if (c == '-') {
        char next = line[li];
        if (!isdigit(next) && next != '.')
            return c;
    }
    if (isdigit(c) || c == '-')
        while (isdigit(s[i++] = c = line[li++]))
            ;
    if (c == '.')
        while (isdigit(s[i++] = c = line[li++]))
            ;
    s[--i] = '\0';
    li--;
    return NUMBER;
}