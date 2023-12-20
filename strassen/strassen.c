//
// Created by d0p1er on 19/12/23.
//

#include "strassen.h"

const size_t MATRIX_SIZE = 128;


int** strassen_multiply(int** matrix_1, int** matrix_2, size_t size)
{
    int** result = (int**) calloc(size * size, sizeof(int*));
    for (size_t i = 0; i < size; i++)
        result[i] = (int*) calloc(size, sizeof(int));

    if (size == 1)
    {
        result[0][0] = matrix_1[0][0] * matrix_2[0][0];
        return result;
    }

    int size_new = size / 2;

    int** A11 = (int**) calloc(size_new * size_new, sizeof(int*));
    int** A12 = (int**) calloc(size_new * size_new, sizeof(int*));
    int** A21 = (int**) calloc(size_new * size_new, sizeof(int*));
    int** A22 = (int**) calloc(size_new * size_new, sizeof(int*));
    int** B11 = (int**) calloc(size_new * size_new, sizeof(int*));
    int** B12 = (int**) calloc(size_new * size_new, sizeof(int*));
    int** B21 = (int**) calloc(size_new * size_new, sizeof(int*));
    int** B22 = (int**) calloc(size_new * size_new, sizeof(int*));


    #pragma omp parallel for
    for (size_t i = 0; i < size_new; i++)
    {
        A11[i] = (int*)calloc(size_new, sizeof(int));
        A12[i] = (int*)calloc(size_new, sizeof(int));
        A21[i] = (int*)calloc(size_new, sizeof(int));
        A22[i] = (int*)calloc(size_new, sizeof(int));

        B11[i] = (int*)calloc(size_new, sizeof(int));
        B12[i] = (int*)calloc(size_new, sizeof(int));
        B21[i] = (int*)calloc(size_new, sizeof(int));
        B22[i] = (int*)calloc(size_new, sizeof(int));
        for (size_t j = 0; j < size_new; j++)
        {
            A11[i][j] = matrix_1[i][j] ;
            A12[i][j] = matrix_1[i][j + size_new];
            A21[i][j] = matrix_1[i + size_new][j];
            A22[i][j] = matrix_1[i + size_new][j + size_new];

            B11[i][j] = matrix_2[i][j];
            B12[i][j] = matrix_2[i][j + size_new];
            B21[i][j] = matrix_2[i + size_new][j];
            B22[i][j] = matrix_2[i + size_new][j + size_new];
        }
    }

    int** P_1 = strassen_multiply(A11, matrix_sub(B12, B22, size_new), size_new);
    int** P_2 = strassen_multiply(matrix_add(A11, A12, size_new), B22, size_new);
    int** P_3 = strassen_multiply(matrix_add(A21, A22, size_new), B11, size_new);
    int** P_4 = strassen_multiply(A22, matrix_sub(B21, B11, size_new), size_new);
    int** P_5 = strassen_multiply(matrix_add(A11, A22, size_new), matrix_add(B11, B22, size_new), size_new);
    int** P_6 = strassen_multiply(matrix_sub(A12, A22, size_new), matrix_add(B21, B22, size_new), size_new);
    int** P_7 = strassen_multiply(matrix_sub(A11, A21, size_new), matrix_add(B11, B12, size_new), size_new);

    int** C11 = matrix_sub(matrix_add(matrix_add(P_5, P_4, size_new), P_6, size_new), P_2, size_new);
    int** C12 = matrix_add(P_1, P_2, size_new);
    int** C21 = matrix_add(P_3, P_4, size_new);
    int** C22 = matrix_sub(matrix_sub(matrix_add(P_5, P_1, size_new), P_3, size_new), P_7, size_new);

    #pragma omp parallel for
    for (size_t i = 0; i < size_new; i++)
    {
        for (size_t j = 0; j < size_new; j++)
        {
            result[i][j] = C11[i][j];
            result[i][j + size_new] = C12[i][j];
            result[i + size_new][j] = C21[i][j];
            result[i + size_new][j + size_new] = C22[i][j];
        }
    }

    matrix_free(A11, size_new);
    matrix_free(A12, size_new);
    matrix_free(A21, size_new);
    matrix_free(A22, size_new);
    matrix_free(B11, size_new);
    matrix_free(B12, size_new);
    matrix_free(B21, size_new);
    matrix_free(B22, size_new);

    matrix_free(P_1, size_new);
    matrix_free(P_2, size_new);
    matrix_free(P_3, size_new);
    matrix_free(P_4, size_new);
    matrix_free(P_5, size_new);
    matrix_free(P_6, size_new);
    matrix_free(P_7, size_new);

    matrix_free(C11, size_new);
    matrix_free(C12, size_new);
    matrix_free(C21, size_new);
    matrix_free(C22, size_new);

    // #pragma omp parallel
    // printf("time: %d\n", omp_get_thread_num());

    // matrix_pretty_print(result, size);

    return result;
}


int strassen(int argc, char *argv[])
{

    int** matrix_1 = matrix_create_rand(MATRIX_SIZE);
    int** matrix_2 = matrix_create_rand(MATRIX_SIZE);
    omp_set_dynamic(0);
    omp_set_num_threads(1);
    if (argc == 3)
    {
        int N =  atoi(argv[2]);
        omp_set_num_threads(N);
    }

    double t_start = omp_get_wtime();

    int** matrix = strassen_multiply(matrix_1, matrix_2, MATRIX_SIZE);

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
