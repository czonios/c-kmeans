/**
 * Main K-means module
 * -------------------
 * 
 * Author:  Christos Zonios
 */
#include <k-means.h>

#define M 		5	// # clusters/centers
#define NUM_SAMPLES 	500	// # samples
#define d 		2	// dimensionality of samples

#define PLOT_CLUSTERS	true

int main()
{

	/* Intializes random number generator */
	srand((unsigned) omp_get_wtime());

	float samples[NUM_SAMPLES][d];
	/* Read input and label matrices */
	if (read_2d_mat("../data/clustering_dataset.txt", samples, NUM_SAMPLES, d) == -1) {
		printf("Error opening input file!\n");
		exit(1);
	}

	float w[M][d];

	float* O[NUM_SAMPLES];
	k_means(d, M, NUM_SAMPLES, w, samples, O);

	if (write_2d_mat("../data/calculated_centers.txt", w, M, d) == -1) {
		printf("Error opening output file!\n");
		exit(1);
	}
	
	printf("Total dispersion: %f\n", dispersion(d, M, NUM_SAMPLES, samples, O));

	/* Fork process and call Python scripts */
	int pid = fork();
	if (pid == 0) {
		if (PLOT_CLUSTERS) {
			/* Call Python script to plot clusters and centers */
			system("python ../scripts/create_k-means_plots.py");
		}
		return (0);
	}

	return 0;
}