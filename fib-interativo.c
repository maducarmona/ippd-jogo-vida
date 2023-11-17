#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int fiboPar( int n ) {
 int i;
 int f[n];
 f[0] = f[1] = 1;
 #pragma omp parallel for
 for (i = 2; i < n; i++)
 f[i] = f[i-1] + f[i-2];
 return f[n-1];
}

int main(int argc, char **argv) {
 int n = atoi(argv[1]);
 double start, end;
 start = omp_get_wtime();
 printf("FiboPar(%d) = %d\n",n,fiboPar(n));
 end = omp_get_wtime();
 printf("Tempo: %4.2f segundos\n", end-start);
 return 0;
}