#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc, char* argv[]) {
    double factor = 1.0;
    double sum = 0.0;
    int k, n = 10e6;
    int thread_count = 4;
    double pi_approx;

    //measure time
    double start = omp_get_wtime();
    #pragma omp parallel for num_threads(thread_count) \
            reduction(+:sum)
    for (k = 0; k < n; k++) {
      sum  += factor/(2*k+1);
      factor = -(factor);
    }
    pi_approx = 4.0*sum;

    double end = omp_get_wtime();
    double delta = end - start;

    printf("Time: %f seconds\n", delta);
    printf("pi_approx: %f\n", pi_approx);

    return 0;
}