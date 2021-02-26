from mpl_toolkits.mplot3d import axes3d
from matplotlib import pyplot
from mpl_toolkits import mplot3d
import numpy as np
import time
import numpy
pyplot.figure(figsize=(6,6))
fig = pyplot.figure()
def generate(X, Y, phi):
    R = 1 - numpy.sqrt(X * X + Y * Y)
    return numpy.cos(1.01 * numpy.pi * X + phi) * R
def call_back(event):
    axtemp = event.inaxes
    x_min, x_max = axtemp.get_xlim()
    y_min, y_max = axtemp.get_ylim()
    rangex = (x_max - x_min) / 10
    rangey = (y_max - y_min) / 10
    if event.button == 'up':
        axtemp.set(xlim = (x_min + rangex, x_max - rangex))
        axtemp.set(ylim = (x_min + rangey, x_max - rangey))
        print('up')
    elif event.button == 'down':
        axtemp.set(xlim=(x_min - rangex, x_max - rangex))
        axtemp.set(ylim=(y_min - rangey, y_max - rangey))
        print('down')
    fig.canvas.draw_idle()
fig.canvas.mpl_connect('scroll_event', call_back)
fig.canvas.mpl_connect('button_press_event', call_back)
ax = fig.add_subplot(111, projection='3d')
ax.xaxis.set_major_formatter(pyplot.NullFormatter())
ax.yaxis.set_major_formatter(pyplot.NullFormatter())
a = numpy.linspace(-1,2,50)
b = numpy.linspace(-1,2,50)
x, y = numpy.meshgrid(a, b)
ax.set_zlim(-5,5)
wframe = None
tstart = time.time()
for phi in np.linspace(0, 180.0 / np.pi, 100):
    if wframe:
        ax.collections.remove(wframe)
    z = generate(x, y, phi)
    wframe = ax.plot_wireframe(x, y, z, rstride = 2, cstride = 2, color = np.random.rand(3))
    pyplot.pause(0.1)
    ax.set_axis_off()
fig = pyplot.figure()
wf = pyplot.axes( projection='3d')
wf.plot_wireframe(x,y,z, color= np.random.rand(3))

# ax.text(2.0, 2.0, "WAVE ", transform=ax.transAxes,
#         ha="right", va="bottom", color="r",
#         family="sans-serif", fontweight="bold", fontsize=16)
# ax.text(2.0, 2.0, "PLATFORM", transform=ax.transAxes,
#         ha="left", va="bottom", color="r",
#         family="sans-serif", fontweight="bold", fontsize=16)

pyplot.show()