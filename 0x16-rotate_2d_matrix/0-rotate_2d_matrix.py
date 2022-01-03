#!/usr/bin/python3
""" Initialize module """


def rotate_2d_matrix(matrix):
    """Rotates a 2d matrix 90 degrees clockwise"""
    new_matrix = [row[:] for row in matrix]
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            matrix[i][j] = new_matrix[len(matrix) - 1 - j][i]
