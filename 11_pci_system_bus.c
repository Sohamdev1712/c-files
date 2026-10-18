#include <stdio.h>

int main() {
    int width; double freq, data_mb; int cycles_overhead = 2;
    printf("PCI bus analysis\nEnter bus width in bits (32/64): "); scanf("%d", &width);
    printf("Enter bus clock in MHz (33/66): "); scanf("%lf", &freq);
    printf("Enter data to transfer (bytes): "); scanf("%lf", &data_mb);
    double bw = (width / 8.0) * freq;                 /* MB/s */
    double words = data_mb / (width / 8.0);
    double cycles = words + cycles_overhead;          /* 1 address phase + data phases (burst) */
    double time_us = cycles / freq;
    printf("\nPeak bandwidth      : %.1f MB/s\n", bw);
    printf("Clock cycles needed : %.0f (incl. %d overhead)\n", cycles, cycles_overhead);
    printf("Transfer time       : %.3f us\n", time_us);
    printf("Effective bandwidth : %.2f MB/s\n", data_mb / time_us);
    return 0;
}
