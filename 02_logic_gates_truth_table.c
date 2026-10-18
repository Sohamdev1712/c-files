#include <stdio.h>

int main() {
    printf("A B | AND OR NAND NOR XOR XNOR\n");
    printf("------------------------------\n");
    for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
            printf("%d %d |  %d   %d   %d    %d   %d    %d\n", a, b,
                   a & b, a | b, !(a & b), !(a | b), a ^ b, !(a ^ b));
    printf("\nNOT gate:\nA | NOT A\n");
    for (int a = 0; a <= 1; a++) printf("%d |   %d\n", a, !a);
    return 0;
}
