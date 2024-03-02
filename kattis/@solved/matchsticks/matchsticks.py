matchsticks_required = {
    "1": 2,
    "2": 5,
    "3": 5,
    "4": 4,
    "5": 5,
    "6": 6,
    "7": 3,
    "8": 7,
    "9": 6,
    "0": 6
}

minimum = [-1] * 101
minimum[0] = minimum[1] = 0

i = 1
while not all([i > 0 for i in minimum]):
    req = sum([matchsticks_required[x] for x in str(i)])
    if minimum[req] == -1:
        print(req, i)
        minimum[req] = i
    i += 1

for i in range(2, 101):
    print(i, minimum[i])