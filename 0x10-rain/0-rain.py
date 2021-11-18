#!/usr/bin/python3
"""
Given a list of non-negative integers representing
the heights of walls with unit width 1, as if viewing
the cross-section of a relief map, calculate how many
square units of water will be retained after it rains.
"""


def rain(walls):
	"""
	calculate how many square units of water will be retained after it rains.
	"""
	if len(walls) == 0:
		return 0

	res, lWall, rWall, empty = 0, 0, 0, 0
	i, j = 0, 0

	while i < len(walls):
		if walls[i] == 0:
			i += 1
			continue
		else:
			lWall = walls[i]
			j = i + 1
			while j < len(walls) - 1 and walls[j] == 0:
				empty += 1
				j += 1
				rWall = walls[j]
			res += empty * min(lWall, rWall)
		empty = 0
		i += 1

	return res
