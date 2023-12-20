//
// Created by d0p1er on 20/12/23.
//

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma once

int** matrix_create_rand(size_t size);
double* matrix_create_rand_double(size_t size);
int** matrix_multiply(int** matrix_1, int** matrix_2, size_t size);
int** matrix_sub(int** matrix_1, int** matrix_2, size_t size);
int** matrix_add(int** matrix_1, int** matrix_2, size_t size);
void matrix_free(int** matrix, size_t size);
void matrix_pretty_print(int** matrix, size_t size);
void matrix_pretty_print_double(double* matrix, size_t size);
