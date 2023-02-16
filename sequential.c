#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    double factor = 1.0;
    double sum = 0.0;
    int k, n;
    double pi_approx;

    for (k = 0; k < n; k++) {
    sum  += factor/(2*k+1);
    factor = -(factor);
    }
    pi_approx = 4.0*sum;

     printf("pi_approx = %f", pi_approx);

  return 0;
}