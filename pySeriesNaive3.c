#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[]) {
    double factor = 1.0;
    double sum = 0.0;
    double sub = 0.0;
    int k, n = 10e6;
    int thread_count = 10;
    double pi_approx;

    #pragma omp parallel for num_threads(thread_count) \
            reduction(+:sum)
    
    for (k = 0; k < n; k+=2) {
      sum  += 1.0/(2*k+1);
    }

    #pragma omp parallel for num_threads(thread_count) \
        reduction(+:sub)
    
    for (k = 1; k < n; k+=2) {
      sub  += 1.0/(2*k+1);
    }
    pi_approx = 4.0*(sum-sub);
    printf("threads = %d", thread_count);
    printf("\n");
    printf("N = %d", n);
    printf("\n");
    printf("pi_approx = %.*lf", 20, pi_approx);
    printf("\n");

  return 0;
}