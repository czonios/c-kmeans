#!/usr/bin/python
"""
Plot creation script
--------------------

Author:	Christos Zonios
"""

import matplotlib.pyplot as plt
import numpy as np
import re
import os

def has_float(str):
	return re.findall(r'\.*([0-9]+\.[0-9]+)', str)

def zero_to_nan(values):
	"""Replace every 0 with 'nan' and return a copy."""
	return [float('nan') if x==0 else x for x in values]


def plot_clusters():
	"""
	Plot clusters
	"""

	script_dir = os.path.dirname(os.path.abspath(__file__))
	data_dir = os.path.join(script_dir, '../data')

	sage = '#87ae73'
	scarletred = (0.937,0.161,0.161)
	samples = []
	with open(os.path.join(data_dir, "clustering_dataset.txt"), "r") as f:
		lines = f.readlines()
		for line in lines:
			sample = []
			for num in line.split(" "):
				if (not has_float(num)):
					continue
				sample.append(float(num.replace('\n', '')))
			samples.append(sample)

	centers = []
	with open(os.path.join(data_dir, "calculated_centers.txt"), "r") as f:
		lines = f.readlines()
		for line in lines:
			center = []
			for num in line.split(","):
				center.append(float(num.replace('\n', '')))
			centers.append(center)
	
	# os.remove('../src/k-means/.tmp/calculated_centers.txt')


	for sample in samples:
		plt.plot(sample[0], sample[1], color=sage, marker='+')
	for center in centers:
		plt.plot(center[0], center[1], color=scarletred, marker='*')
	plt.savefig(os.path.join(script_dir, '../graphs/kmeans.png'), format='png')
	plt.show()

if __name__ == '__main__':
	plot_clusters()