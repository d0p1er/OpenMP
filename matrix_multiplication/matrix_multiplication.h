//
// Created by d0p1er on 20/12/23.
//

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <immintrin.h>
#include "../matrix/matrix.h"

#pragma once

int** matrix_multiply(int** matrix_1, int** matrix_2, size_t size);
int matrix_multiplication_simple(int argc, char *argv[]);
int matrix_multiplication_AVX(int argc, char *argv[]);
int matrix_multiplication_SSE(int argc, char *argv[]);
