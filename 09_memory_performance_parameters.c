#include <stdio.h>

int main() {
    long hits, misses; double tc, tm;
    printf("Enter number of cache hits and misses: "); scanf("%ld %ld", &hits, &misses);
    printf("Enter cache access time and miss penalty (ns): "); scanf("%lf %lf", &tc, &tm);
    long total = hits + misses;
    double hr = (double)hits / total, mr = 1 - hr;
    double amat = tc + mr * tm;
    printf("\nTotal accesses    : %ld\n", total);
    printf("Hit ratio         : %.4f\n", hr);
    printf("Miss ratio        : %.4f\n", mr);
    printf("AMAT (tc + mr*tm) : %.3f ns\n", amat);
    printf("Speedup vs no cache (%.1f ns): %.3f\n", tc + tm, (tc + tm) / amat);
    return 0;
}
