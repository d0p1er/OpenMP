//
// Created by d0p1er on 19/12/23.
//

#include "main.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
        printf("[ERROR], no arguments to start");

    if (strcmp(argv[1], "info") == 0)
    {
        printf("There are such commands:\n");
        printf("FIRST TASK - PI:\n");
        printf("1.1.1) Single-threaded calculation of pi: pi\n");
        printf("1.1.2) Multi-threaded calculation of pi: pi [amount of threads]\n");
        printf("1.2.1) Single-threaded matrix multiplication using strassen: strassen\n");
        printf("1.2.2) Multi-threaded matrix multiplication using strassen: strassen [amount of threads]\n\n");
        printf("SECOND - MATRIX MULTIPLICATION:\n");
        printf("2.1) Simple matrix multiplication: multiply [matrix size] [amount of threads]\n");
        printf("2.2) Matrix multiplication using AVX: multiply_avx [matrix size]\n");
        printf("2.3) Matrix multiplication using AVX: multiply_sse [matrix size]\n");
    }

    if (strcmp(argv[1], "pi") == 0)
        pi(argc, argv);
    if (strcmp(argv[1], "strassen") == 0)
        strassen(argc, argv);
    if (strcmp(argv[1], "multiply") == 0)
        matrix_multiplication_simple(argc, argv);
    if (strcmp(argv[1], "multiply_avx") == 0)
        matrix_multiplication_AVX(argc, argv);
    if (strcmp(argv[1], "multiply_sse") == 0)
        matrix_multiplication_SSE(argc, argv);

    return 0;
}
