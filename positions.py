import numpy as np
import matplotlib.pyplot as plt
import pyarma as pa


r = np.loadtxt("positions.txt")
x, y, z = np.transpose(r)

plt.figure()

plt.plot(z)

plt.show()