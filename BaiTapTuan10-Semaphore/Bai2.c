#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <assert.h>

#define NUM_THREAD 4
//#define PI 3.1415926535897

pthread_t thdIDs[NUM_THREAD] = {0}; // Thread IDs
uint64_t  counts[NUM_THREAD] = {0}; // Points count
uint64_t  sumPoint = 0, range;      // Shared data

void* calPI(void *arg) {
    // Initialize the pseudo number
    // Monte Carlo technique
    uint64_t* pcount = (uint64_t*)arg;
    unsigned int seed = rand()%30000;

    uint64_t i;
    for(i = 0; i < range; ++i) {
        // Create point
        double x = (double)rand_r(&seed)/(double)RAND_MAX;
        double y = (double)rand_r(&seed)/(double)RAND_MAX;
        // Calculator radius
	double temp = x*x + y*y;
        double r = x*x + y*y;
        // Is it in a circle
        if(r <= 1) *pcount = *pcount + 1;
    }

    // End thread
    pthread_exit(EXIT_SUCCESS);
}

int main(int argc, char const *argv[])
{
    assert(argc == 2   &&  "TheNumberOfArgumentsIsWrong");
    assert(atoll(argv[1]) > 0 && "Argument must be >= 0");

    // Set test range
    range = atoll(argv[1])/NUM_THREAD;


    int8_t i;
    for(i = 0; i < NUM_THREAD; ++i)
        pthread_create(&thdIDs[i], NULL, calPI, &counts[i]);

    for(i = 0; i < NUM_THREAD; ++i) {
        pthread_join(thdIDs[i], NULL);
        sumPoint += counts[i]; ; // The number of points in the circle
    }


    double pi = 4.0*(double)sumPoint/(double)range/(double)NUM_THREAD;
    printf("%.5lf\n", pi);          // Print PI Number

    pthread_exit(EXIT_SUCCESS);
}


