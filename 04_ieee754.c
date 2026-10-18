#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {
    float f; uint32_t bits;
    printf("Enter a decimal number: ");
    scanf("%f", &f);
    memcpy(&bits, &f, sizeof(bits));
    printf("\nIEEE 754 single precision representation of %f\n", f);
    printf("Sign (1 bit)      : %u\n", bits >> 31);
    printf("Exponent (8 bits) : ");
    for (int i = 30; i >= 23; i--) printf("%u", (bits >> i) & 1);
    printf("  (biased = %u, actual = %d)\n", (bits >> 23) & 0xFF, (int)((bits >> 23) & 0xFF) - 127);
    printf("Mantissa (23 bits): ");
    for (int i = 22; i >= 0; i--) printf("%u", (bits >> i) & 1);
    printf("\nFull 32-bit       : ");
    for (int i = 31; i >= 0; i--) { printf("%u", (bits >> i) & 1); if (i == 31 || i == 23) printf(" "); }
    printf("\nHex               : 0x%08X\n", bits);
    return 0;
}
