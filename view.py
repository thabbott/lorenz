import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import animation

x = np.loadtxt('lorenz_x.out')
y = np.loadtxt('lorenz_y.out')
z = np.loadtxt('lorenz_z.out')

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
title = ax.set_title('Frame 0')
ax.set_xlim([-50, 50])
ax.set_ylim([-50, 50])
ax.set_zlim([0, 50])
scat, = \
    ax.plot(x[0,:], y[0,:], z[0,:], linestyle = "", marker = "o",
            markersize = 4.0)

def animate(ii):
    scat.set_data(x[ii,:], y[ii,:])
    scat.set_3d_properties(z[ii,:])
    title.set_text('Frame %d' % ii)
    return title, scat

anim = animation.FuncAnimation(fig, animate, np.arange(1,len(x[:,0])),
    interval=20, blit=True)

plt.show()
