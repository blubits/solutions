FILENAME = "input"

def parse(filename):
    with open(filename) as f:
        return [line.strip() for line in f]
    
def solve(data):
    return data

def solve2(data):
    pass

data = parse(FILENAME)
print(solve(data))
print(solve2(data))