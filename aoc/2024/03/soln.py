import re

FILENAME = "input"

def parse(filename):
    with open(filename) as f:
        return "".join(f.readlines())

def solve(data):
    pattern = r"mul\((-?\d+(?:\.\d+)?)\s*,\s*(-?\d+(?:\.\d+)?)\)"
    matches = re.findall(pattern, data)
    return sum(int(match[0]) * int(match[1]) for match in matches)

def solve2(data):
    pattern = r"mul\((-?\d+(?:\.\d+)?)\s*,\s*(-?\d+(?:\.\d+)?)\)|do\(\)|don't\(\)"
    matches = re.finditer(pattern, data)
    multiplying = True
    ans = 0
    for match in matches:
        if match.group(1) and multiplying:
            ans += int(match.group(1)) * int(match.group(2))
        else:
            if match.group() == "do()":
                multiplying = True
            else:
                multiplying = False
    return ans

data = parse(FILENAME)
print(solve(data))
print(solve2(data))