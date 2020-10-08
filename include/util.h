#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <unistd.h> 
#include <sys/time.h>
#include <omp.h>

/* File I/O, utility functions: util.c */
float rand_in_range(float min, float max);
bool compare_int_arr(int *x, int *y, int n);
bool compare_float_arr(float *x, float *y, int n);

int read_2d_mat(char *fname, float *mat, int m, int n);
int read_labels(char* fname, int* mat, int n);
int encode_one_hot(int one_hot_mat[][3], int* labels, int n);
int write_2d_mat(char* fname, float* mat, int m, int n);