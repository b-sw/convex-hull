"""
    Name: plot.py
    Purpose:

    @author Bartosz Świtalski, Piotr Frątczak

    Warsaw University of Technology
    Faculty of Electronics and Information Technology
"""
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import art3d
import matplotlib.colors as colors
# import scipy as sp
# from scipy.spatial.qhull import ConvexHull

LABELS = ['x', 'y', 'z']
GRID_DIMENSIONS = 111
PROJECTION_TYPE = '3d'
MARKER_COLOR = 'k'  # black
EDGE_COLOR = 'g'
MARKER = 'o'  # circle
LINESTYLE = 'none'
X_VALUES = 0
Y_VALUES = 1
Z_VALUES = 2
READ_FILE = 'r'
POINTS_FILE_NAME = 'points.data'
VERTICES_FILE_NAME = 'vertices.data'
FACETS_FILE_NAME = 'facets.data'
SEPARATOR = ';'
ALPHA = 0.8
DIMENSIONS = 3


def get_from_file(cast_type, file_name):
    values = []

    with open(file_name, READ_FILE) as file:
        for line in file:
            point = line.strip().split(SEPARATOR)
            for i in range(len(point)):
                point[i] = cast_type(point[i])
            values.append(point)

    return values


def plot_defining_vertices(ax, points, vertices):
    pts = []
    for vertex in vertices:
        pts.append(points[vertex])

    pts = np.array(pts)
    ax.plot(pts.T[X_VALUES], pts.T[Y_VALUES], pts.T[Z_VALUES], color=MARKER_COLOR, marker=MARKER, linestyle=LINESTYLE)


# def plot_facet(ax, facet):
#     ax.plot(facet.T[X_VALUES], facet.T[Y_VALUES], facet.T[Z_VALUES], color=EDGE_COLOR, linestyle='-')
#

def color_facet(ax, facet):
    surface = art3d.Poly3DCollection(facet)
    surface.set_color(colors.rgb2hex(np.random.rand(DIMENSIONS)))
    surface.set_edgecolor(EDGE_COLOR)
    surface.set_alpha(ALPHA)
    ax.add_collection3d(surface)


def plot_convex_hull():
    points = np.array(get_from_file(float, POINTS_FILE_NAME))
    vertices = np.array(get_from_file(int, VERTICES_FILE_NAME)[0])
    facets = np.array(get_from_file(int, FACETS_FILE_NAME))

    fig = plt.figure()
    ax = fig.add_subplot(GRID_DIMENSIONS, projection=PROJECTION_TYPE)

    plot_defining_vertices(ax, points, vertices)

    for facet in facets:
        facet_pts = np.array([points[facet[0]], points[facet[1]], points[facet[2]]])
        print(facet_pts)

        # plot_facet(ax, facet_pts)
        color_facet(ax, facet_pts)

    # Make axis label
    for label in LABELS:
        eval("ax.set_{:s}label('{:s}')".format(label, label))
    plt.show()
    # plt.savefig('...')


def main():
    plot_convex_hull()


if __name__ == '__main__':
    main()