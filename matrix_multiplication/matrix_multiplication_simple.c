//
// Created by d0p1er on 20/12/23.
//

#include "matrix_multiplication.h"

int** matrix_multiply(int** matrix_1, int** matrix_2, size_t size)
{
    int** matrix = (int**) calloc(size, sizeof(int*));

    #pragma omp parallel for
    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = (int*) calloc(size, sizeof(int));
        for (size_t j = 0; j < size; j++)
        	for (size_t k = 0; k < size; k++)
            	matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
    }

    return matrix;
}

int matrix_multiplication_simple(int argc, char *argv[])
{
	if (argc < 3)
    {
        printf("[ERROR], no arguments to multiplication\n");
    	return 0;
    }

    int MATRIX_SIZE =  atoi(argv[2]);

	omp_set_dynamic(0);
    omp_set_num_threads(1);
    if (argc == 4)
    {
        int N =  atoi(argv[3]);
        omp_set_num_threads(N);
    }


	int** matrix_1 = matrix_create_rand(MATRIX_SIZE);
    int** matrix_2 = matrix_create_rand(MATRIX_SIZE);
    

    double t_start = omp_get_wtime();

    int** matrix = matrix_multiply(matrix_1, matrix_2, MATRIX_SIZE);

    printf("time: %.4g s\n", omp_get_wtime() - t_start);

    matrix_pretty_print(matrix_1, MATRIX_SIZE);
    printf("\nmultiplied by\n");
    matrix_pretty_print(matrix_2, MATRIX_SIZE);
    printf("\ngot\n");
    matrix_pretty_print(matrix, MATRIX_SIZE);

    matrix_free(matrix_1, MATRIX_SIZE);
    matrix_free(matrix_2, MATRIX_SIZE);
    matrix_free(matrix, MATRIX_SIZE);
    
    return 0;
}

