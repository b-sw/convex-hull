"""
    Name: plot.py
    Purpose:

    Author: Bartosz Świtalski, Piotr Frątczak

    Warsaw University of Technology
    Faculty of Electronics and Information Technology
"""
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import art3d
import matplotlib.colors as colors
import scipy as sp
from scipy.spatial.qhull import ConvexHull

LABELS = ['x', 'y', 'z']
GRID_DIMENSIONS = 111
PROJECTION_TYPE = '3d'
VERTEX_MARKER_COLOR = 'r'  # black
INSIDE_MARKER_COLOR = 'y'
EDGE_COLOR = 'r'
VERTEX_MARKER = '.'  # circle
INSIDE_MARKER = ','
LINESTYLE = 'none'
X_VALUES = 0
Y_VALUES = 1
Z_VALUES = 2
READ_FILE = 'r'
POINTS_FILE_NAME = 'points.data'
VERTICES_FILE_NAME = 'vertices.data'
FACES_FILE_NAME = 'faces.data'
SEPARATOR = ';'
ALPHA = 0.01
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


def plot_inside_points(ax, points):
    pts = np.array(points)
    ax.plot(pts.T[X_VALUES], pts.T[Y_VALUES], pts.T[Z_VALUES], color=INSIDE_MARKER_COLOR, marker=INSIDE_MARKER, linestyle=LINESTYLE)


def plot_defining_vertices(ax, points, vertices):
    pts = []
    for vertex in vertices:
        pts.append(points[vertex])

    pts = np.array(pts)
    ax.plot(pts.T[X_VALUES], pts.T[Y_VALUES], pts.T[Z_VALUES], color=VERTEX_MARKER_COLOR, marker=VERTEX_MARKER, linestyle=LINESTYLE)


def color_face(ax, face):
    surface = art3d.Poly3DCollection(face, linewidths=0.5)
    surface.set_color(colors.rgb2hex(np.random.rand(DIMENSIONS)))
    surface.set_edgecolor(EDGE_COLOR)
    surface.set_alpha(ALPHA)
    ax.add_collection3d(surface)


def plot_convex_hull():
    points = np.array(get_from_file(float, POINTS_FILE_NAME))
    vertices = np.array(get_from_file(int, VERTICES_FILE_NAME)[0])
    faces = np.array(get_from_file(int, FACES_FILE_NAME))

    fig = plt.figure(num='nasza')
    ax = fig.add_subplot(GRID_DIMENSIONS, projection=PROJECTION_TYPE)

    plot_inside_points(ax, points)
    plot_defining_vertices(ax, points, vertices)

    for face in faces:
        face_pts = np.array([points[face[0]], points[face[1]], points[face[2]]])
        color_face(ax, face_pts)

    ax.set_facecolor((0.1, 0.2, 0.3))
    plt.axis('off')
    # Make axis label
    for label in LABELS:
        eval("ax.set_{:s}label('{:s}')".format(label, label))
    plt.show()
    # plt.savefig('...')


def debug_plot():
    points = np.array(get_from_file(float, POINTS_FILE_NAME))

    chull = ConvexHull(points)
    vertices = chull.vertices
    faces = chull.simplices

    fig = plt.figure(num='debug')
    ax = fig.add_subplot(GRID_DIMENSIONS, projection=PROJECTION_TYPE)

    plot_inside_points(ax, points)
    plot_defining_vertices(ax, points, vertices)

    for face in faces:
        face_pts = np.array([points[face[0]], points[face[1]], points[face[2]]])
        color_face(ax, face_pts)
        print(face)

    for label in LABELS:
        eval("ax.set_{:s}label('{:s}')".format(label, label))
    plt.show()


def main():
    plot_convex_hull()
    debug_plot()


if __name__ == '__main__':
    main()
