#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """
    Method that determines if all the boxes can be opened
    - A key with the same number as a box opens that box
    """

    if len(boxes) == 0:
        return False

    keys = [0]
    for box in keys:
        for key in boxes[box]:
            if key not in keys and key < len(boxes):
                keys.append(key)
                print(keys)

    if len(keys) == len(boxes):
        return True
    return False
