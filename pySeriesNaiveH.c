#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define BLOCK_SIZE 16

int main(int argc, char* argv[]) {
    double factor = 1.0;
    double sum = 0.0;
    int k, n = 10e6;
    int thread_count = 4;
    double pi_approx;
    #pragma omp parallel for num_threads(thread_count) \
            reduction(+:sum) private(factor) schedule(static, BLOCK_SIZE)
    
    for (k = 0; k < n; k++) {
      if (k % 2 == 0)
        factor = 1.0;
      else
        factor = -1.0;
      sum  += factor/(2*k+1);
    }
    pi_approx = 4.0*sum;

    printf("pi_approx = %f", pi_approx);

  return 0;
}