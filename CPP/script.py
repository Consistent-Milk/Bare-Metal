"""
Run to auto generate directories for 20 chapters
"""
import os

directory_list = []

base_directory = 'ch_0'

for i in range(1, 10):
    directory_list.append(f'{base_directory}{i}')

base_directory = 'ch_1'

for i in range(10):
    directory_list.append(f'{base_directory}{i}')

directory_list.append('ch_20')

for index, directory in enumerate(directory_list):
    if directory not in os.listdir():
        os.makedirs(directory)
