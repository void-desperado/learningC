#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void) {
    int len;
    int total;
    int max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        total = len;

        if (len == MAXLINE-1 && line[len-1] != '\n') {
            int c;
            while ((c = getchar()) != EOF && c != '\n')
                ++total;
            if (c == '\n')
                ++total;
        }

        if (total > max) {
            max = total;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("Longest line length: %d\n", max);
        printf("Contents (up to %d chars):\n%s", MAXLINE-1, longest);
    }
    return 0;
}

int getline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
