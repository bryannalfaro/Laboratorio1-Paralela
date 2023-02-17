#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc, char* argv[]) {
    double factor = 1.0;
    double sum = 0.0;
    int k, n = 10e3;
    int thread_count =3;
    double pi_approx;
    double seq_time = 2.8734;

    //measure time
    double start = omp_get_wtime();
    #pragma omp parallel for num_threads(thread_count) reduction(+:sum)
    for (k = 0; k < n; k++) {
      sum  += factor/(2*k+1);
      factor = -(factor);
    }
    pi_approx = 4.0*sum;
    double end = omp_get_wtime();
    double delta = end - start;
    printf("Time: %f seconds\n", delta);
    printf("Speedup: %f\n", seq_time/delta);
    //Efficiency
    printf("Efficiency: %f\n", (seq_time/delta)/thread_count);

     printf("pi_approx = %f", pi_approx);

  return 0;
}