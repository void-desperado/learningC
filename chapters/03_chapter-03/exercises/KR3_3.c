#include <stdio.h>
#include <ctype.h>
#define MAX 1000

void expand(const char s1[], char s2[]) {
    int i = 0, j = 0;
    char c;

    while ((c = s1[i++]) != '\0') {
        if (s1[i] == '-' && s1[i+1] != '\0'
            && isalnum((unsigned char)c) && isalnum((unsigned char)s1[i+1])
            && ((islower((unsigned char)c) && islower((unsigned char)s1[i+1]))
             || (isupper((unsigned char)c) && isupper((unsigned char)s1[i+1]))
             || (isdigit((unsigned char)c) && isdigit((unsigned char)s1[i+1])))
            && c < s1[i+1]) {
            char start = c;
            char end   = s1[i+1];
            for (char ch = start; ch <= end; ++ch)
                s2[j++] = ch;
            i += 2;
        } else {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}

int main(void) {
    char s1[MAX], s2[MAX * 10];

    if (fgets(s1, MAX, stdin) != NULL) {
        expand(s1, s2);
        printf("%s", s2);
    }
    return 0;
}
