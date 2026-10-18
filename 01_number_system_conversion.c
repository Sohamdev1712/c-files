#include <stdio.h>
#include <string.h>
#include <math.h>

void dec_to_base(long n, int base) {
    char digits[] = "0123456789ABCDEF", res[65];
    int i = 0;
    if (n == 0) { printf("0\n"); return; }
    while (n > 0) { res[i++] = digits[n % base]; n /= base; }
    while (i--) putchar(res[i]);
    putchar('\n');
}

long base_to_dec(char *s, int base) {
    long v = 0;
    for (int i = 0; s[i]; i++) {
        int d = (s[i] >= 'A') ? s[i] - 'A' + 10 : s[i] - '0';
        v = v * base + d;
    }
    return v;
}

int main() {
    int ch, base; long n; char s[65];
    printf("1. Decimal to Binary/Octal/Hex\n2. Binary/Octal/Hex to Decimal\nChoice: ");
    scanf("%d", &ch);
    if (ch == 1) {
        printf("Enter decimal number: "); scanf("%ld", &n);
        printf("Binary : "); dec_to_base(n, 2);
        printf("Octal  : "); dec_to_base(n, 8);
        printf("Hex    : "); dec_to_base(n, 16);
    } else {
        printf("Enter base (2/8/16): "); scanf("%d", &base);
        printf("Enter number (uppercase for hex): "); scanf("%s", s);
        printf("Decimal: %ld\n", base_to_dec(s, base));
    }
    return 0;
}
