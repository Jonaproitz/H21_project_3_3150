import numpy as np
import matplotlib.pyplot as plt
import pyarma as pa


filename = "positions.bin"

R = pa.mat()
R.load(filename)

x, y, z = np.array(R)

plt.figure()

plt.plot(z)

plt.show()