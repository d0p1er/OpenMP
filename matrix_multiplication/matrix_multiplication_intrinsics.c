//
// Created by d0p1er on 20/12/23.
//

#include "matrix_multiplication.h"

double* matrix_multiply_AVX(double* matrix_1, double* matrix_2, size_t size)
{
    int block_width = 256;
    if (size >= 256)
    	block_width = 512;

    int block_height = 32;
    if (size >= 256)
	{
    	if (size >= 512)
    		block_width = 8;
    	else
    		block_width = 16;
	}

	double* matrix = (double*) calloc(size * size, sizeof(double));

    for (size_t row = 0; row < size; row += block_height)
    {
        for (size_t col = 0; col < size; col += block_width)
        {
            for (size_t i = 0; i < size; i++)
            {
                for (size_t j = col; j < col + block_width && j < size; j += 4)
                {

                    __m256d sum = _mm256_loadu_pd(&matrix[i * size + j]);
                    for (size_t k = row; k < row + block_height && k < size; k++)
                    {
                        __m256d a = _mm256_set1_pd(matrix_1[i * size + k]);
                        __m256d b = _mm256_loadu_pd(&matrix_2[k * size + j]);
                        sum = _mm256_fmadd_pd(a, b, sum);
                    }
                    _mm256_storeu_pd(&matrix[i * size + j], sum);
                }
            }
        }
    }

    return matrix;
}

double* matrix_multiply_SSE(double* matrix_1, double* matrix_2, size_t size)
{
	double* matrix = (double*) calloc(size * size, sizeof(double));

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j += 2)
		{
			__m128d sum = _mm_load_pd(&matrix[i * size + j]);
			for (size_t k = 0; k < size; k++)
				sum = _mm_add_pd(_mm_mul_pd(_mm_set_pd1(matrix_1[i * size + k]), _mm_load_pd(&matrix_2[k * size + j])), sum);

			_mm_store_pd(&matrix[i * size + j], sum);
		}
	}

    return matrix;
}


int matrix_multiplication_AVX(int argc, char *argv[])
{
	if (argc < 3)
    {
        printf("[ERROR], no arguments to multiplication\n");
    	return 0;
    }

    int MATRIX_SIZE =  atoi(argv[2]);

    clock_t t_start = clock();

    double* matrix_1 = matrix_create_rand_double(MATRIX_SIZE);
    double* matrix_2 = matrix_create_rand_double(MATRIX_SIZE);
    
    double* matrix = matrix_multiply_AVX(matrix_1, matrix_2, MATRIX_SIZE);
    printf("time: %.4f s\n", (clock() - t_start) * 1.0 / CLOCKS_PER_SEC);

    matrix_pretty_print_double(matrix_1, MATRIX_SIZE);
    printf("\nmultiplied by\n");
    matrix_pretty_print_double(matrix_2, MATRIX_SIZE);
    printf("\ngot\n");
    matrix_pretty_print_double(matrix, MATRIX_SIZE);

    return 0;
}

int matrix_multiplication_SSE(int argc, char *argv[])
{
	if (argc < 3)
    {
        printf("[ERROR], no arguments to multiplication\n");
    	return 0;
    }

    int MATRIX_SIZE =  atoi(argv[2]);

    clock_t t_start = clock();

    double* matrix_1 = matrix_create_rand_double(MATRIX_SIZE);
    double* matrix_2 = matrix_create_rand_double(MATRIX_SIZE);
    
    double* matrix = matrix_multiply_SSE(matrix_1, matrix_2, MATRIX_SIZE);
    printf("time: %.4f s\n", (clock() - t_start) * 1.0 / CLOCKS_PER_SEC);

    matrix_pretty_print_double(matrix_1, MATRIX_SIZE);
    printf("\nmultiplied by\n");
    matrix_pretty_print_double(matrix_2, MATRIX_SIZE);
    printf("\ngot\n");
    matrix_pretty_print_double(matrix, MATRIX_SIZE);
    
    return 0;
}
