#include <util.h>

/* K-means clustering: k-means.c */
void k_means(size_t d, size_t M, size_t N, float centers[M][d], float samples[N][d], float* O[N]);
float euclidian_d(size_t d, float x[d], float w[d]);
float dispersion(size_t d, size_t M, size_t N, float samples[N][d], float* O[N]);
void initialize_centers(size_t d, size_t M, size_t N, float centers[M][d], float samples[N][d]);