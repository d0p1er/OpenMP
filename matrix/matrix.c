//
// Created by d0p1er on 20/12/23.
//

#include "matrix.h"

int** matrix_create_rand(size_t size)
{
    int** matrix = (int**) calloc(size, sizeof(int*));

    srand(time(NULL));
    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = (int*) calloc(size, sizeof(int));
        for (size_t j = 0; j < size; j++)
            matrix[i][j] = rand() % 128;
    }

    return matrix;
}

double* matrix_create_rand_double(size_t size)
{
    double* matrix = (double*) calloc(size * size, sizeof(double));

    srand(time(NULL));
    for (size_t i = 0; i < size * size; i++)
        matrix[i] = (rand() % 128) * 1.0;

    return matrix;
}

int** matrix_sub(int** matrix_1, int** matrix_2, size_t size)
{
    int** matrix = (int**) calloc(size, sizeof(int*));

    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = (int*) calloc(size, sizeof(int));
        for (size_t j = 0; j < size; j++)
            matrix[i][j] = matrix_1[i][j] - matrix_2[i][j];
    }

    return matrix;
}

int** matrix_add(int** matrix_1, int** matrix_2, size_t size)
{
    int** matrix = (int**) calloc(size, sizeof(int*));

    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = (int*) calloc(size, sizeof(int));
        for (size_t j = 0; j < size; j++)
            matrix[i][j] = matrix_1[i][j] + matrix_2[i][j];
    }

    return matrix;
}

void matrix_free(int** matrix, size_t size)
{
    for (size_t i = 0; i < size; i++)
        free(matrix[i]);
    
    free(matrix);
}


void matrix_pretty_print(int** matrix, size_t size)
{
    // for (int i = 0; i < size; i++) {
    //     for (int j = 0; j < size; j++)
    //         printf("%d\t", matrix[i][j]);

    //     printf("\n");
    // }

    printf("%d\t", matrix[0][0]);
    printf("%d\t", matrix[0][1]);
    printf("%d\t", matrix[0][2]);
    printf("...\t");
    printf("%d\t", matrix[0][size - 3]);
    printf("%d\t", matrix[0][size - 2]);
    printf("%d\n", matrix[0][size - 1]);

    printf("%d\t", matrix[1][0]);
    printf("%d\t", matrix[1][1]);
    printf("%d\t", matrix[1][2]);
    printf("...\t");
    printf("%d\t", matrix[1][size - 3]);
    printf("%d\t", matrix[1][size - 2]);
    printf("%d\n", matrix[1][size - 1]);

    printf("%d\t", matrix[2][0]);
    printf("%d\t", matrix[2][1]);
    printf("%d\t", matrix[2][2]);
    printf("...\t");
    printf("%d\t", matrix[2][size - 3]);
    printf("%d\t", matrix[2][size - 2]);
    printf("%d\n", matrix[2][size - 1]);

    printf("...\n");

    printf("%d\t", matrix[size - 3][0]);
    printf("%d\t", matrix[size - 3][1]);
    printf("%d\t", matrix[size - 3][2]);
    printf("...\t");
    printf("%d\t", matrix[size - 3][size - 3]);
    printf("%d\t", matrix[size - 3][size - 2]);
    printf("%d\n", matrix[size - 3][size - 1]);

    printf("%d\t", matrix[size - 2][0]);
    printf("%d\t", matrix[size - 2][1]);
    printf("%d\t", matrix[size - 2][2]);
    printf("...\t");
    printf("%d\t", matrix[size - 2][size - 3]);
    printf("%d\t", matrix[size - 2][size - 2]);
    printf("%d\n", matrix[size - 2][size - 1]);


    printf("%d\t", matrix[size - 1][0]);
    printf("%d\t", matrix[size - 1][1]);
    printf("%d\t", matrix[size - 1][2]);
    printf("...\t");
    printf("%d\t", matrix[size - 1][size - 3]);
    printf("%d\t", matrix[size - 1][size - 2]);
    printf("%d\n", matrix[size - 1][size - 1]);
}

void matrix_pretty_print_double(double* matrix, size_t size)
{
    // for (int i = 0; i < size; i++) {
    //     for (int j = 0; j < size; j++)
    //         printf("%d\t", matrix[i][j]);

    //     printf("\n");
    // }

    printf("%lf\t", matrix[0]);
    printf("%lf\t", matrix[1]);
    printf("%lf\t", matrix[2]);
    printf("...\t");
    printf("%lf\t", matrix[size - 3]);
    printf("%lf\t", matrix[size - 2]);
    printf("%lf\n", matrix[size - 1]);

    printf("%lf\t", matrix[size]);
    printf("%lf\t", matrix[size + 1]);
    printf("%lf\t", matrix[size + 2]);
    printf("...\t");
    printf("%lf\t", matrix[2 * size - 3]);
    printf("%lf\t", matrix[2 * size - 2]);
    printf("%lf\n", matrix[2 * size - 1]);

    printf("%lf\t", matrix[2 * size]);
    printf("%lf\t", matrix[2 * size + 1]);
    printf("%lf\t", matrix[2 * size + 2]);
    printf("...\t");
    printf("%lf\t", matrix[3 * size - 3]);
    printf("%lf\t", matrix[3 * size - 2]);
    printf("%lf\n", matrix[3 * size - 1]);

    printf("...\n");

    printf("%lf\t", matrix[(size - 3) * size]);
    printf("%lf\t", matrix[(size - 3) * size + 1]);
    printf("%lf\t", matrix[(size - 3) * size + 2]);
    printf("...\t");
    printf("%lf\t", matrix[(size - 2) * size - 3]);
    printf("%lf\t", matrix[(size - 2) * size  - 2]);
    printf("%lf\n", matrix[(size - 2) * size  - 1]);

    printf("%lf\t", matrix[(size - 2) * size]);
    printf("%lf\t", matrix[(size - 2) * size + 1]);
    printf("%lf\t", matrix[(size - 2) * size + 2]);
    printf("...\t");
    printf("%lf\t", matrix[(size - 1) * size - 3]);
    printf("%lf\t", matrix[(size - 1) * size  - 2]);
    printf("%lf\n", matrix[(size - 1) * size - 1]);


    printf("%lf\t", matrix[(size - 1) * size]);
    printf("%lf\t", matrix[(size - 1) * size + 1]);
    printf("%lf\t", matrix[(size - 1) * size + 2]);
    printf("...\t");
    printf("%lf\t", matrix[size * size  - 3]);
    printf("%lf\t", matrix[size * size - 2]);
    printf("%lf\n", matrix[size * size - 1]);
}
