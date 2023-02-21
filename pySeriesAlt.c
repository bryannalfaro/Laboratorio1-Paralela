#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[]) {
    double sum = 0.0;
    double sub = 0.0;

    int k, n = 10e7;
    int thread_count = 5;
    double pi_approx;

    double start, end,delta;
    start = omp_get_wtime();
    #pragma omp parallel for num_threads(thread_count) \
            reduction(+:sum) schedule(guided, 16)
    for (k = 0; k < n; k += 2) {
      sum += 1.0/(2*k+1);
    }

    #pragma omp parallel for num_threads(thread_count) \
            reduction(+:sub) schedule(static, 16)
    for (k = 1; k < n; k += 2) {
      sub += 1.0/(2*k+1);
    }

    pi_approx = 4.0*(sum-sub);
    end = omp_get_wtime();
    delta = end - start;

    printf("sum = %f\n", sum);
    printf("sub = %f\n", sub);
    printf("pi_approx = %f\n", pi_approx);
    printf("Time: %f seconds\n", delta);

  return 0;
}