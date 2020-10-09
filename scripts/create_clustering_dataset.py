#!/usr/bin/python3
"""
Dataset creation script
-----------------------

Author:	Christos Zonios
"""
from random import uniform, shuffle
from matplotlib import pyplot as plt
import numpy as np
import os

def rand_in_range(min, max):
	return uniform(min, max)

def create_points():
	"""Creates the inputs of the dataset consisting of 500 points

	Returns
	-------
	list
		Length: 500 
		Containing float pairs (x1, x2)
		100 random points in square [-0.3, 0.3]x[-0.3, 0.3]
		100 random points in square [-1.1, -0.5]x[0.5, 1.1]
		100 random points in square [-1.1, -0.5]x[-1.1, -0.5]
		100 random points in square [0.5, 1.1]x[-1.1, -0.5]
		100 random points in square [0.5, 1.1]x[0.5, 1.1]
	"""
	points = []
	for i in range(100):
		x_1 = float(rand_in_range(-0.3, 0.3))
		x_2 = float(rand_in_range(-0.3, 0.3))
		points.append([x_1, x_2])

	for i in range(100):
		x_1 = float(rand_in_range(-1.1, -0.5))
		x_2 = float(rand_in_range(0.5, 1.1))
		points.append([x_1, x_2])

	for i in range(100):
		x_1 = float(rand_in_range(-1.1, -0.5))
		x_2 = float(rand_in_range(-1.1, -0.5))
		points.append([x_1, x_2])

	for i in range(100):
		x_1 = float(rand_in_range(0.5, 1.1))
		x_2 = float(rand_in_range(-1.1, -0.5))
		points.append([x_1, x_2])

	for i in range(100):
		x_1 = float(rand_in_range(0.5, 1.1))
		x_2 = float(rand_in_range(0.5, 1.1))
		points.append([x_1, x_2])

	return points


def main():
	"""Generates the dataset and saves to two separate files
	"""
	samples = create_points()
	shuffle(samples)
	script_dir = os.path.dirname(os.path.abspath(__file__))

	chameleon = (0.541,0.886,0.204)
	butter = (0.988,0.914,0.310)
	skyblue = (0.447,0.624,0.812)
	scarletred = (0.937,0.161,0.161)
	chocolate = (0.914,0.725,0.431)
	plum = (0.678,0.498,0.659)

	for sample in samples:
		plt.plot(sample[0], sample[1], color=skyblue, marker='x')
	plt.savefig(os.path.join(script_dir, '../graphs/dataset.png'), format='png')
	plt.show()

	script_dir = os.path.dirname(__file__)
	data_dir = os.path.join(script_dir, '../data')
	dataset_file = os.path.join(data_dir, 'clustering_dataset.txt')
	# Save dataset to file
	with open(dataset_file, 'w') as f:
		for sample in samples:
			f.write(' {0} {1}\n'.format(sample[0], sample[1]))
	f.close()


if __name__ == "__main__":
	main()