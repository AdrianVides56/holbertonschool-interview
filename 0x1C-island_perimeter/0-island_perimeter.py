#!/usr/bin/python3
""" Module to calc the perimeter """


def island_perimeter(grid):
    """ return the perimeter of the island """
    i, j, per = 0, 0, 0
    while i < len(grid):
        while j < len(grid[0]):
            if grid[i][j] == 1:
                per += 4
                if i > 0 and grid[i - 1][j] == 1:
                    per -= 1
                if i < (len(grid) - 1) and grid[i + 1][j] == 1:
                    per -= 1
                if j > 0 and grid[i][j - 1] == 1:
                    per -= 1
                if j < (len(grid[0]) - 1) and grid[i][j + 1] == 1:
                    per -= 1
            j += 1
        j = 0
        i += 1
    return per
