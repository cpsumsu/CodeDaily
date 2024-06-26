BINARY_TREE = """
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
"""
SINGLE_LINKED_LIST = """
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
LEETCODE_HEADER = """from functools import cache
from typing import List
from bisect import bisect_left
import math
from heapq import heapify, heappop, heappush
from collections import deque
import collections
"""

