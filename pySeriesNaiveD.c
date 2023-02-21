#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc, char* argv[]) {
    double factor = 1.0;
    double sum = 0.0;
    int k, n = 10e7;
    int thread_count = 3;
    double pi_approx;
    //measuring time
    double start, end,delta;

    start = omp_get_wtime();
    #pragma omp parallel for \
        num_threads(thread_count) reduction(+:sum)
    for (k = 0; k < n; k++) {
      if (k % 2 == 0)
        factor = 1.0;
      else
        factor = -1.0;
      sum  += factor/(2*k+1);
    }
    pi_approx = 4.0*sum;
    printf("pi_approx = %f\n", pi_approx);

    end = omp_get_wtime();
    delta = end - start;
    printf("Time: %f seconds \n", delta);


  return 0;
}