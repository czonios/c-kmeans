/**
 * K-means algorithm and dispersion calculations
 * ---------------------------------------------
 *
 * Author:	Christos Zonios
 */

#include <k-means.h>



void k_means(size_t d, size_t M, size_t N, float centers[M][d], float samples[N][d], float* O[N])
{
	/* NOTE: O[i] holds a *pointer* to the cluster center it is closest to */
	size_t t = 0;
	size_t i, j, k;
	initialize_centers(d, M, N, centers, samples);
	float prev_centers[M][d];
	float tmp;

	do {
		float sums[M][d];
		size_t counters[M];

		/* Initialize counters, sums to 0 and update previous centers */
		for (j = 0; j < M; j++) {
			counters[j] = 0;
			for (k = 0; k < d; k++) {
				sums[j][k] = 0.0;
				prev_centers[j][k] = centers[j][k];
			}
		}

		/* Find min euclidian distance for each sample to each center */
		for (i = 0; i < N; i++) {
			float min_dist = euclidian_d(d, samples[i], centers[0]);
			size_t index = 0;
			for (j = 1; j < M; j++) {
				if (tmp = euclidian_d(d, samples[i], centers[j]) < min_dist) {
					min_dist = tmp;
					index = j;
				}
			}
			O[i] = centers[index];
			counters[index]++;
			for (k = 0; k < d; k++) {
				sums[index][k] += samples[i][k];
			}
		}
		/* Update centers */
		for (j = 0; j < M; j++) {
			for (k = 0; k < d; k++) {
				if (counters[j] == 0)
					centers[j][k] = centers[j][k];
				else
					centers[j][k] = sums[j][k] / counters[j];
			}
		}

		t++;
	} while (!compare_float_arr(centers, prev_centers, d));

	printf("\nTotal iterations: %d\n", t);

	for (i = 0; i < N; i++) {
		float min_dist = euclidian_d(d, samples[i], centers[0]);
		size_t index = 0;
		for (j = 1; j < M; j++) {
			if (tmp = euclidian_d(d, samples[i], centers[j]) < min_dist) {
				min_dist = tmp;
				index = j;
			}
		}
		O[i] = centers[index];
	}
}

float euclidian_d(size_t d, float x[d], float w[d])
{
	size_t i;
	float sum = 0.0;
	for (i = 0; i < d; i++) {
		sum += pow((x[i] - w[i]), 2);
	}

	return sqrt(sum);
}

/**
 * Function: dispersion
 * --------------------
 * Calculates the total despersion of the clusters
 *
 * centers: (float[][]) the centers the K-means algorithm converged to
 * samples: (float[][]) the input samples
 *
 * returns: (output_t[]) the network output vector
 *
 */
float dispersion(size_t d, size_t M, size_t N, float samples[N][d], float* O[N])
{
	size_t i, j;
	float sum = 0.0;

	for (i = 0; i < N; i++) {
		for (j = 0; j < d; j++) 
			sum += pow((O[i][j] - samples[i][j]), 2);
	}

	return sum;
}

void initialize_centers(size_t d, size_t M, size_t N, float centers[M][d], float samples[N][d])
{
	size_t i, j;
	for (i = 0; i < M; i++) {
		int rand_center = floor(rand_in_range(0, N-1));
		for (j = 0; j < d; j++) {
			centers[i][j] = samples[rand_center][j];
		}
	}
}