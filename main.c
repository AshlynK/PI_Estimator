#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <omp.h>
#include <math.h>
#include <assert.h>
#define RNG_MOD 0x80000000
int seed;
int main(int argc, char *argv[]){

    long long int n;
    int i;
    int count = 0;
    double x;
    double y;
    if(argc<2) {
        exit(1);
    }
    
    n = atoll(argv[1]);


    int p=1;
    if(argc==3) {
        p = atoi(argv[2]);
        assert(p>=1);
    }

    omp_set_num_threads(p); // set number of threads
    double time = omp_get_wtime();
    #pragma omp parallel private(x,y,seed) reduction(+:count) 
    {
        //different seed for every thread
        seed = 25234 + 17 * omp_get_thread_num();
        #pragma omp for
        for (i = 0; i <= n; i++) {
            x = (double)(rand_r(&seed) %RNG_MOD)/RNG_MOD;
            y = (double)(rand_r(&seed) %RNG_MOD)/RNG_MOD;
            if (x*x + y*y <= 1) count++;
        }
    }

    double pi = ((double)count/(double)n) * 4.0;

    time = omp_get_wtime() - time;
    printf("π = %f, p: %d, n: %lld, time: %f seconds\n", pi, p, n, time);
    
    return 0;
}
