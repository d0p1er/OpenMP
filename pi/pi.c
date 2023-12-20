//
// Created by d0p1er on 19/12/23.
//

#include "pi.h"

const int NUM_ITER = 1e9;

int pi(int argc, char *argv[])
{
    double pi = 0;

    omp_set_num_threads(1);
    if (argc == 3)
    {
        int N =  atoi(argv[2]);
        omp_set_num_threads(N);
    }

    double t_start = omp_get_wtime();

    #pragma omp parallel for reduction(+:pi) 
    for (size_t i = 0; i < NUM_ITER; i++) {
        if ((2 * i + 1) % 4 == 3) 
            pi -= 4.0 / (2 * i + 1); 
        else
            pi += 4.0 / (2 * i + 1); 
    }

    printf("pi: %.16g\n", pi);
    printf("time: %.4g s\n", omp_get_wtime() - t_start);
    return 0;
}
