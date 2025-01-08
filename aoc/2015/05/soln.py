FILENAME = "input"

def parse(filename):
    with open(filename) as f:
        return [line.strip() for line in f]
    
def is_nice(string):
    if len(list(filter(lambda x: x in "aeiou", string))) < 3:
        return False
    if not (any((letter * 2) in string for letter in "abcdefghijklmnopqrstuvwxyz")):
        return False
    if "ab" in string or "cd" in string or "pq" in string or "xy" in string:
        return False
    return True
    
def solve(data):
    return [is_nice(string) for string in data].count(True)

def solve2(data):
    pass

data = parse(FILENAME)
print(solve(data))
print(solve2(data))