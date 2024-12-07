FILENAME = "input"

def parse(filename):
    with open(filename) as f:
        return f.readline().strip()
    
def solve(data):
    return sum(
        map(lambda x: 1 if x == "(" else -1, data)
    )

def solve2(data):
    curr_floor = 0
    for idx, move in enumerate(data):
        curr_floor += 1 if move == "(" else -1
        if curr_floor == -1:
            return idx + 1

data = parse(FILENAME)
print(solve(data))
print(solve2(data))