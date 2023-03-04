import os
from os import listdir
import matplotlib.pyplot as plt


import numpy as np
from os.path import isfile, join

class kitti_object(object):
    '''Load and parse object data into a usable format.'''
    def __init__(self, root_dir, split=""):
        '''root_dir contains training and testing folders'''
        self.root_dir = root_dir
        self.split = split
        self.split_dir = os.path.join(root_dir, split)
        #
        self.lidar_dir = os.path.join('', self.split_dir)

    def get_lidar(self, idx):
        lidar_filename = os.path.join(self.lidar_dir, '%06d.bin'%(idx))
        return load_velo_scan(lidar_filename)


def load_velo_scan(velo_filename):
    scan = np.fromfile(velo_filename, dtype=np.float32)
    scan = scan.reshape((-1, 4))
    # print(scan)
    return scan

dataset = kitti_object('data') #change the directory

path = "data"
files = [f for f in listdir(path) if isfile(join(path, f)) and f.split(".")[-1] == 'bin']
num_of_files = len(files)

total_areas = []
for x in range(num_of_files):

    lidar_data = dataset.get_lidar(x)

    max_values = lidar_data.max(axis=0)
    min_values = lidar_data.min(axis=0)

    total_area = (max_values[0] - min_values[0]) * (max_values[1] - min_values[1]) * (max_values[2] - min_values[2])
    total_areas.append(total_area)

_, bins, _ = plt.hist(total_areas, 10)
plt.title('Total Area Count')
plt.xlabel('Total Area')
plt.ylabel('Count')
plt.xticks(bins, rotation=90)
plt.tight_layout()
plt.show()