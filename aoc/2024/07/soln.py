FILENAME = "input"

def parse(filename):
    with open(filename) as f:
        return {int(line.split()[0][:-1]): list(map(int, line.split()[1:])) for line in f}

def is_possible(curr_idx, numbers, curr_val, target):
    if curr_idx == len(numbers):
        return curr_val == target
    if curr_idx == 0:
        return is_possible(curr_idx + 1, numbers, numbers[curr_idx], target)
    else:
        return \
            is_possible(curr_idx + 1, numbers, curr_val + numbers[curr_idx], target) \
            or is_possible(curr_idx + 1, numbers, curr_val * numbers[curr_idx], target)
    
def is_possible2(curr_idx, numbers, curr_val, target):
    if curr_idx == len(numbers):
        return curr_val == target
    if curr_idx == 0:
        return is_possible2(curr_idx + 1, numbers, numbers[curr_idx], target)
    else:
        return \
            is_possible2(curr_idx + 1, numbers, curr_val + numbers[curr_idx], target) \
            or is_possible2(curr_idx + 1, numbers, curr_val * numbers[curr_idx], target) \
            or is_possible2(curr_idx + 1, numbers, int(str(curr_val) + str(numbers[curr_idx])), target)

def solve(data):
    ans = 0
    for target, numbers in data.items():
        if is_possible(0, numbers, 0, target):
            ans += target
    return ans

def solve2(data):
    ans = 0
    for target, numbers in data.items():
        if is_possible2(0, numbers, 0, target):
            ans += target
    return ans

data = parse(FILENAME)
print(solve(data))
print(solve2(data))
