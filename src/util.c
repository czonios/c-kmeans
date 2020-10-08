/**
 * Utility functions
 * -------------------
 * 
 * Author:  Christos Zonios
 */
#include <k-means.h>
#define _mat(i,j) (mat[(i)*n + (j)])

/**
 * Function: rand_in_range
 * -----------------------
 * Generates a random number in the given range
 *
 * min: (float) start of range
 * max: (float) end of range
 *
 * returns: (float) random number in range
 */
float rand_in_range(float min, float max)
{
	return (rand()/(float)(RAND_MAX)) * abs(min - max) + min;
}

/**
 * Function: read_2d_mat
 * ----------------
 * Reads a 2D matrix from a file
 */
int read_2d_mat(char* fname, float* mat, int m, int n)
{
	FILE *fp;
	int  i, j;

	if ((fp = fopen(fname, "r")) == NULL)
		return (-1);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (fscanf(fp, "%f", &_mat(i,j)) == EOF) {
				fclose(fp);
				return (-1);
			}
		}
	}
	fclose(fp);
	return (0);

}

/**
 * Function: write_2d_mat
 * ----------------
 * Writes a 2D matrix to a file
 */
int write_2d_mat(char* fname, float* mat, int m, int n)
{
	FILE *fp;
	int  i, j;

	if ((fp = fopen(fname, "w")) == NULL)
		return -1;
	for (i = 0; i < m; i++, fprintf(fp, "\n")) {
		for (j = 0; j < n - 1; j++) {
			fprintf(fp, "%f,", _mat(i, j));
		}
		fprintf(fp, "%f", _mat(i, n-1));
	}
	fclose(fp);
	return 0;
}

/**
 * Function: compare_float_arr
 * ---------------------
 * Compares two arrays of real numbers, returns true if they are equal
 */
bool compare_float_arr(float* x, float* y, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		if (x[i] != y[i])
			return false;
	}
	return true;
}