#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <omp.h>
#include <math.h>
#include <assert.h>
#define RANGE 10000

void printUsage(void){
	printf("pi <n> <number of threads>\n");
}

//function determines if dart landed in circle
// true if x^2 + y^2 < 0.5^2

int isInCircle(double x, double y){
	x -= 0.5;
    y -= 0.5;
	printf("(%f*%f) + (%f*%f) < 0.25 ? ", x,x,y,y);
	if ((pow(x, 2) + pow(y, 2)) < pow(0.5, 2)){
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]){

    long long int n;
    int i;
    int count = 0;
    if(argc<2) {
		printf("Usage: loop {number of iterations} [number of threads]\n");
		exit(1);
	}
	
	n = atoll(argv[1]);
	printf("Debug: number of iterations = %lld (%d)\n", n, sizeof(long long int));

	int p=1;
	if(argc==3) {
		p = atoi(argv[2]);
		assert(p>=1);
		printf("Debug: number of requested threads = %d\n",p);
	}

	omp_set_num_threads(p);

	// set timer
	double time = omp_get_wtime();
    
	#pragma omp parallel for private(i) reduction(+:count)
	for (int i = 0; i < n; i++){
		int rank = omp_get_thread_num();
		// generate random x and y between 0 and 1
		double x = (double)(rand() %RANGE)/RANGE;
		double y = (double)(rand() %RANGE)/RANGE;
		if (isInCircle(x, y)){
			count++;
		}
	} //end of pragma

	double pi = ((double)count/(double)n) * 4.0;

	time = omp_get_wtime() - time;
	printf("π = %f, p: %d, n: %lld, time: %f seconds\n", pi, p, n, time);
	
	return 0;
}