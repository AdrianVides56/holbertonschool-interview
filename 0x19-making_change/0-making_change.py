#!/usr/bin/python3
"""
Solution of the problem
"""

from audioop import reverse


def makeChange(coins, total):
    """determine the fewest number of coins needed to meet a given amount"""
    count, aux, i = 0, 0, 0

    coins.sort(reverse=True)

    if total == 0:
        return count

    while i < len(coins):
        if coins[i] <= total and coins[i] + aux <= total:
            count += 1
            aux += coins[i]
        else:
            i += 1

    if aux < total:
        return -1
    return count
