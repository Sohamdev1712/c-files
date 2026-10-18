#include <stdio.h>

int main() {
    int k, n; double tp;
    printf("Enter number of pipeline stages (k), number of instructions (n), stage time (ns): ");
    scanf("%d %d %lf", &k, &n, &tp);
    double t_pipe = (k + n - 1) * tp;
    double t_non = (double)n * k * tp;
    printf("\nNon-pipelined time : %.2f ns\n", t_non);
    printf("Pipelined time     : %.2f ns  ((k+n-1)*tp)\n", t_pipe);
    printf("Speedup            : %.3f\n", t_non / t_pipe);
    printf("Efficiency         : %.3f\n", t_non / t_pipe / k);
    printf("Throughput         : %.4f instructions/ns\n", n / t_pipe);
    return 0;
}
