#include <stdio.h>

void bin(unsigned x, int n) { for (int i = n - 1; i >= 0; i--) printf("%u", (x >> i) & 1); }

int main() {
    int n = 4; unsigned Q, M; int A = 0;
    printf("Enter dividend and divisor (unsigned, < 16): ");
    scanf("%u %u", &Q, &M);
    if (M == 0) { printf("Divide by zero!\n"); return 1; }
    unsigned mask = (1u << n) - 1;
    printf("\nStep   A      Q     Action\n");
    for (int i = 1; i <= n; i++) {
        int neg = (A < 0);
        A = (A << 1) | ((Q >> (n - 1)) & 1);
        Q = (Q << 1) & mask;
        A = neg ? A + (int)M : A - (int)M;
        if (A >= 0) Q |= 1;
        printf("%d    ", i); bin((unsigned)A & ((1u << (n + 1)) - 1), n + 1); printf("  ");
        bin(Q, n); printf("  %s, Q0=%d\n", neg ? "A=A+M" : "A=A-M", A >= 0);
    }
    if (A < 0) { A += M; printf("Final correction: A = A + M\n"); }
    printf("\nQuotient = %u, Remainder = %d\n", Q, A);
    return 0;
}
