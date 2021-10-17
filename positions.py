import numpy as np
import matplotlib.pyplot as plt


def read_data(filename):
    infile = np.loadtxt(filename)
    N = int(np.max(infile.transpose()[0]) + 1)
    index = np.where(infile.transpose()[0] == 0)
    r = np.array([infile[index, 1:]])
    for i in range(1, N):
        index = np.where(infile.transpose()[0] == i)
        r = np.append(r, [infile[index, 1:]], axis=0)
    return r

"""
r = read_data("positions.txt")
x, y, z = np.transpose(r[0])

plt.figure()

plt.plot(z)

plt.show()
"""

