import re

FILENAME = "input"

def parse(filename):
    with open(filename) as f:
        return [list(line.strip()) for line in f.readlines()]

def solve(data):
    rows, cols = len(data), len(data[0])
    xmas_count = 0

    # Horizontal search
    for row in range(rows):
        for col in range(cols - 3):
            if data[row][col:col+4] == ['X', 'M', 'A', 'S'] or data[row][col:col+4] == ['S', 'A', 'M', 'X']:
                xmas_count += 1

    # Vertical search
    for row in range(rows - 3):
        for col in range(cols):
            if [data[row+i][col] for i in range(4)] == ['X', 'M', 'A', 'S'] or [data[row+i][col] for i in range(4)] == ['S', 'A', 'M', 'X']:
                xmas_count += 1

    # Diagonal search (top-left to bottom-right)
    for row in range(rows - 3):
        for col in range(cols - 3):
            if [data[row+i][col+i] for i in range(4)] == ['X', 'M', 'A', 'S'] or [data[row+i][col+i] for i in range(4)] == ['S', 'A', 'M', 'X']:
                xmas_count += 1

    # Diagonal search (bottom-left to top-right)
    for row in range(3, rows):
        for col in range(cols - 3):
            if [data[row-i][col+i] for i in range(4)] == ['X', 'M', 'A', 'S'] or [data[row-i][col+i] for i in range(4)] == ['S', 'A', 'M', 'X']:
                xmas_count += 1

    return xmas_count

def solve2(data):
    rows, cols = len(data), len(data[0])
    pattern_count = 0

    # Search for pattern
    for row in range(rows - 2):
        for col in range(cols - 2):
            if data[row][col] == 'M' and data[row+2][col] == 'S' and data[row+1][col+1] == 'A' and data[row][col+2] == 'M' and data[row+2][col+2] == 'S':
                pattern_count += 1
            if data[row][col] == 'S' and data[row+2][col] == 'M' and data[row+1][col+1] == 'A' and data[row][col+2] == 'S' and data[row+2][col+2] == 'M':
                pattern_count += 1
            if data[row][col] == 'M' and data[row+2][col] == 'M' and data[row+1][col+1] == 'A' and data[row][col+2] == 'S' and data[row+2][col+2] == 'S':
                pattern_count += 1
            if data[row][col] == 'S' and data[row+2][col] == 'S' and data[row+1][col+1] == 'A' and data[row][col+2] == 'M' and data[row+2][col+2] == 'M':
                pattern_count += 1

    return pattern_count

data = parse(FILENAME)
print(solve(data))
print(solve2(data))