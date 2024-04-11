from json import loads
from functools import cmp_to_key

def compare(a, b):
    if isinstance(a, int) and isinstance(b, int):
        if a < b:
            return -1
        elif a > b:
            return 1
        else:
            return 0
    if isinstance(a, list) and isinstance(b, list):
        for i in range(min(len(a), len(b))):
            if compare(a[i], b[i]) != 0:
                return compare(a[i], b[i])
        if len(a) < len(b):
            return -1
        elif len(b) < len(a):
            return 1
        else:
            return 0
    if isinstance(a, int) and isinstance(b, list):
        return compare([a], b)
    if isinstance(a, list) and isinstance(b, int):
        return compare(a, [b])


def solve1(lines):
    lines = list(filter(lambda x: x != "", lines))
    ans = 0
    for i in range(len(lines) // 2):
        if compare(loads(lines[2 * i]), loads(lines[2 * i + 1])) == 1:
            ans += i + 1
    return ans


def solve2(lines):
    lines = [loads(line) for line in filter(lambda x: x != "", lines)]
    lines.append([[2]])
    lines.append([[6]])
    x = 1
    for b, i in enumerate(sorted(lines, key=cmp_to_key(compare))):
        if i == [[2]] or i == [[6]]:
            x *= (b + 1)
    return x


with open("input") as input_file:
    lines = [line.rstrip() for line in input_file.readlines()]
    print(solve1(lines))
    print(solve2(lines))
