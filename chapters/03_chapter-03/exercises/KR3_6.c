#include <stdio.h>
#include <string.h>
#define MAX 1000

void itoa(int n, char s[], int width) {
    int i = 0, sign = n;
    unsigned int num;

    if (sign < 0)
        num = -n;
    else
        num = n;

    do {
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    while (i < width)
        s[i++] = ' ';

    s[i] = '\0';

    // Reverse the string
    int start = 0, end = i - 1;
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

int main(void) {
    char s[MAX];
    int n, width;

    printf("Enter an integer: ");
    scanf("%d", &n);
    printf("Enter minimum field width: ");
    scanf("%d", &width);

    itoa(n, s, width);
    printf("Converted with padding: '%s'\n", s);
    return 0;
}