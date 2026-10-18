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
        A = (A << 1) | ((Q >> (n - 1)) & 1);
        Q = (Q << 1) & mask;
        A = A - (int)M;
        if (A < 0) { A += M; printf("%d    ", i); bin(A, n + 1); printf("  "); bin(Q, n); printf("  restore, Q0=0\n"); }
        else { Q |= 1; printf("%d    ", i); bin(A, n + 1); printf("  "); bin(Q, n); printf("  Q0=1\n"); }
    }
    printf("\nQuotient = %u, Remainder = %d\n", Q, A);
    return 0;
}
