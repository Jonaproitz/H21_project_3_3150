import numpy as np
import matplotlib.pyplot as plt


def read_data(filename):
    infile = np.loadtxt(filename)
    N = int(np.max(infile.transpose()[0]) + 1)
    index = np.where(infile.transpose()[0] == 0)
    x = np.array(infile[index, 1:])
    for i in range(1, N):
        index = np.where(infile.transpose()[0] == i)
        x = np.append(x, infile[index, 1:], axis=0)
    return x

def plot_1_particle():
    r = read_data("positions.txt")
    x, y, z = np.transpose(r[0])

    plt.figure()

    plt.plot(z)

    plt.show()



def plot_2_particles():
    r = read_data("positions.txt")
    r1 = r[0]
    r2 = r[1]

    plt.figure()
    plt.plot(np.transpose(r1)[0], np.transpose(r1)[1])
    plt.plot(np.transpose(r2)[0], np.transpose(r2)[1])
    plt.show()

plot_2_particles()
