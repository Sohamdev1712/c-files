#include <stdio.h>

int main() {
    double h1, h2, t1, t2, t3;
    printf("Memory hierarchy: Cache (L1) -> Main Memory (L2) -> Disk (L3)\n");
    printf("Enter hit ratio of Cache and Main Memory (0-1): "); scanf("%lf %lf", &h1, &h2);
    printf("Enter access times Cache, Main Memory, Disk (ns): "); scanf("%lf %lf %lf", &t1, &t2, &t3);
    double eat = h1 * t1 + (1 - h1) * (h2 * (t1 + t2) + (1 - h2) * (t1 + t2 + t3));
    printf("\nL1 hit : %.2f ns (prob %.2f)\n", t1, h1);
    printf("L2 hit : %.2f ns (prob %.2f)\n", t1 + t2, (1 - h1) * h2);
    printf("L3 hit : %.2f ns (prob %.2f)\n", t1 + t2 + t3, (1 - h1) * (1 - h2));
    printf("Effective (average) access time = %.3f ns\n", eat);
    printf("Speedup over Main Memory only   = %.3f\n", (t1 + t2 + (1-h2)*t3) / eat);
    return 0;
}
