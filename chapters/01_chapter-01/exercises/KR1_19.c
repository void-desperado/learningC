#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim);
void reverse(char s[]);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
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

void reverse(char s[]) {
    int i, j;
    char tmp;
    int len = 0;

    /* find length, excluding the newline if present */
    while (s[len] != '\0')
        ++len;
    if (len > 0 && s[len-1] == '\n')
        --len;

    /* swap characters in place */
    for (i = 0, j = len - 1; i < j; ++i, --j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
    /* append newline if it was there */
    if (s[len] == '\n' || (len < MAXLINE-1 && s[len] == '\0' && s[len+1] == '\0')) {
        /* already has newline at s[len] or we preserved the terminator */
    } else {
        s[len] = '\n';
        s[len+1] = '\0';
    }
}
