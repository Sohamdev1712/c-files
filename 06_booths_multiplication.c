#include <stdio.h>

void bin(unsigned x, int n) { for (int i = n - 1; i >= 0; i--) printf("%u", (x >> i) & 1); }

int main() {
    int n = 8, M, mult, A = 0, qm1 = 0;
    printf("Enter multiplicand and multiplier (-128 to 127): ");
    scanf("%d %d", &M, &mult);
    unsigned mask = (1u << n) - 1, Q = (unsigned)mult & mask;
    printf("\nStep      A          Q       Q-1  Action\n");
    for (int i = 1; i <= n; i++) {
        int q0 = Q & 1; const char *act = "no op";
        if (q0 == 1 && qm1 == 0) { A -= M; act = "A = A - M"; }
        else if (q0 == 0 && qm1 == 1) { A += M; act = "A = A + M"; }
        qm1 = Q & 1;                              /* arithmetic shift right of A,Q,Q-1 */
        Q = (Q >> 1) | (((unsigned)A & 1) << (n - 1));
        A >>= 1;
        printf("%d    ", i); bin((unsigned)A & mask, n); printf("  "); bin(Q, n);
        printf("   %d   %s + ASR\n", qm1, act);
    }
    long result = ((long)A << n) | Q;
    printf("\nProduct = %ld (expected %d)\n", result, M * mult);
    return 0;
}
