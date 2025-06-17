#include <stdio.h>
#define MAX 1000

void itob(int n, char s[], int b) {
    int i = 0, sign = n;
    unsigned int num;

    if (sign < 0)
        num = -n;
    else
        num = n;

    do {
        int digit = num % b;
        s[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'A';
    } while ((num /= b) > 0);

    if (sign < 0)
        s[i++] = '-';

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
    int n, base;

    printf("Enter an integer: ");
    scanf("%d", &n);
    printf("Enter base (2-36): ");
    scanf("%d", &base);

    if (base < 2 || base > 36) {
        printf("Invalid base.\n");
        return 1;
    }

    itob(n, s, base);
    printf("Converted: %s\n", s);
    return 0;
}