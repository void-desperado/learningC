#include <stdio.h>
#define TABSTOP 8
#define MAXLINE 1000

int getline(char line[], int lim);

int main(void) {
    int len, i, col, nb, nt;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        col = 0;
        nb = 0;
        nt = 0;
        for (i = 0; i < len; ++i) {
            if (line[i] == ' ') {
                ++nb;
                if ((col + nb) % TABSTOP == 0) {
                    ++nt;
                    nb = 0;
                }
            } else {
                while (nt-- > 0) {
                    putchar('\t');
                }
                while (nb-- > 0) {
                    putchar(' ');
                }
                putchar(line[i]);
                if (line[i] == '\n')
                    col = 0;
                else
                    col += nb + nt, ++col;
                nb = nt = 0;
                continue;
            }
            if (line[i] == '\n')
                col = 0;
        }
        /* flush any remaining tabs or spaces at end of line */
        while (nt-- > 0)
            putchar('\t');
        while (nb-- > 0)
            putchar(' ');
    }
    return 0;
}

int getline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
