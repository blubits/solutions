# Uses python3

from itertools import permutations
import sys

def largest_number(a):
    # write your code here
    res = ""
    for x in permutations(a):
        if ''.join(x) > res:
            res = ''.join(x)
    return res

if __name__ == '__main__':
    input = sys.stdin.read()
    data = input.split()
    a = data[1:]
    print(largest_number(a))
