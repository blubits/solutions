from hashlib import md5

FILENAME = "input"

def parse(filename):
    with open(filename) as f:
        return f.readline().strip()
    
def solve(data):
    i = 1
    while True:
        if md5((data + str(i)).encode()).hexdigest()[0:5] == "00000":
            return i
        i += 1

def solve2(data):
    i = 1
    while True:
        if md5((data + str(i)).encode()).hexdigest()[0:6] == "000000":
            return i
        i += 1


data = parse(FILENAME)
print(solve(data))
print(solve2(data))