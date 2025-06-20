#include <stdio.h>
#define MAXLINE 1000
#define THRESHOLD 80

int getline(char s[], int lim);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > THRESHOLD) {
            printf("%s", line);
        }
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
