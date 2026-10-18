#include <stdio.h>

int main() {
    int ok1 = 1, ok2 = 1;
    printf("A B | !(A.B) !A+!B | !(A+B) !A.!B\n");
    for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++) {
            int l1 = !(a && b), r1 = (!a) || (!b);
            int l2 = !(a || b), r2 = (!a) && (!b);
            printf("%d %d |   %d       %d   |   %d       %d\n", a, b, l1, r1, l2, r2);
            if (l1 != r1) ok1 = 0;
            if (l2 != r2) ok2 = 0;
        }
    printf("\nTheorem 1: (A.B)' = A' + B'  -> %s\n", ok1 ? "PROVED" : "FAILED");
    printf("Theorem 2: (A+B)' = A'.B'    -> %s\n", ok2 ? "PROVED" : "FAILED");
    return 0;
}
