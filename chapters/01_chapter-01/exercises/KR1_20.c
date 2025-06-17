#include <stdio.h>
#define TABSTOP 8

int main(void) {
    int c;
    int col = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = TABSTOP - (col % TABSTOP);
            while (spaces-- > 0) {
                putchar(' ');
                col++;
            }
        } else {
            putchar(c);
            col++;
            if (c == '\n')
                col = 0;
        }
    }

    return 0;
}
