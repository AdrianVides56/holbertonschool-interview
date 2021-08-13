#!/usr/bin/python3
"""
Initialize module
"""


def minOperations(n):
    """
    In a text file, there is a single character H. Your text editor can execute
    only two operations in this file: Copy All and Paste. Given a number n,
    write a method that calculates the fewest number of operations needed to
    result in exactly n H characters in the file.
    """
    if n < 2:
        return 0

    num, numOper, div = n, 0, 2

    while num > 1:
        if num % div == 0:
            num /= div
            numOper += div
        else:
            div += 1
    return numOper
