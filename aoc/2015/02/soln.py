from functools import reduce
from operator import mul
FILENAME = "input"

def parse(filename):
    with open(filename) as f:
        return [list(map(int, line.strip().split("x"))) for line in f]
    
def solve(data):
    def area(L):
        lw = L[0] * L[1]
        wh = L[1] * L[2]
        lh = L[0] * L[2]
        return 2 * (lw + wh + lh) + min(lw, wh, lh)
    return sum(area(L) for L in data)

def solve2(data):
    def perimeter(L):
        lw = L[0] + L[1]
        wh = L[1] + L[2]
        lh = L[0] + L[2]
        return reduce(mul, L) + (2 * min(lw, wh, lh))
    return sum(perimeter(L) for L in data)

data = parse(FILENAME)
print(solve(data))
print(solve2(data))