def solve(lines):
    lines = [int(i) for i in lines]
    ans = 0
    for i in range(len(lines) - 3):
        if (lines[i + 1] + lines[i + 2] + lines[i + 3]) > (lines[i] + lines[i + 1] + lines[i + 2]):
            ans += 1
    return ans

with open("input") as input_file:
    print(solve([line.rstrip() for line in input_file.readlines()]))