//
// Created by d0p1er on 19/12/23.
//

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../matrix/matrix.h"

#pragma once

extern const size_t MATRIX_SIZE;

int** strassen_multiply(int** matrix_1, int** matrix_2, size_t size);
int strassen(int argc, char *argv[]);
