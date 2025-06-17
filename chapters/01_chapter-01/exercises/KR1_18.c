#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        int end = len - 1;
        /* trim trailing blanks and tabs (and remove the newline for trimming) */
        if (line[end] == '\n') {
            --end;
        }
        while (end >= 0 && (line[end] == ' ' || line[end] == '\t'))
            --end;
        /* if anything remains, re‑append a newline and print */
        if (end >= 0) {
            line[end + 1] = '\n';
            line[end + 2] = '\0';
            printf("%s", line);
        }
        /* otherwise it's a blank line—skip printing */
    }

    return 0;
}

int getline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
