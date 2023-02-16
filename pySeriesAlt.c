#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define BLOCK_SIZE 16

int main(int argc, char* argv[]) {
    double sum = 0.0;
    double sub = 0.0;

    int k, n = 10e6;
    int thread_count = 4;
    double pi_approx;

    #pragma omp parallel for num_threads(thread_count) \
            reduction(+:sum) schedule(static, BLOCK_SIZE)
    for (k = 0; k < n; k += 2) {
      sum += 1.0/(2*k+1);
    }

    #pragma omp parallel for num_threads(thread_count) \
            reduction(+:sub) schedule(static, BLOCK_SIZE)
    for (k = 1; k < n; k += 2) {
      sub += 1.0/(2*k+1);
    }

    pi_approx = 4.0*(sum-sub);

    printf("sum = %f\n", sum);
    printf("sub = %f\n", sub);
    printf("pi_approx = %f\n", pi_approx);

  return 0;
}