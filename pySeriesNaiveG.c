#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>


int main(int argc, char* argv[]) {
    double factor = 1.0;
    double sum = 0.0;
    int k, n = 10e7;
    int thread_count = 6;
    double pi_approx;

    double start, end,delta;

    start = omp_get_wtime();
    #pragma omp parallel for num_threads(thread_count) \
            reduction(+:sum) private(factor)
    for (k = 0; k < n; k++) {
      if (k % 2 == 0)
        factor = 1.0;
      else
        factor = -1.0;
      sum  += factor/(2*k+1);
    }
    pi_approx = 4.0*sum;
    
    end = omp_get_wtime();
    delta = end - start;
    
    printf("threads = %d", thread_count);
    printf("\n");
    printf("n = %d", n);
    printf("\n");
    printf("pi_approx = %f", pi_approx);
    printf("\n");
    printf("Time: %f seconds \n", delta);
    printf("\n");

  return 0;
}