import re

gears = {}

rx = r"\d+"
map = [x.rstrip() for x in open("input").readlines()]
for row, line in enumerate(map):
    for m in re.finditer(rx, line):
        surrounded = True
        for i in range(max(0, row - 1), min(len(map) - 1, row + 1) + 1):
            for j in range(max(0, m.start() - 1), min(len(map[0]) - 1, m.end() + 1)):
                if not (i == row and m.start() <= j < m.end()):
                    if map[i][j] != "." and not map[i][j].isdigit():
                        surrounded = False
                        if map[i][j] == "*":
                            if (i, j) in gears:
                                gears[(i, j)].append(int(m.group()))
                            else:
                                gears[(i, j)] = [int(m.group())]
sum = 0
for gear, nums in gears.items():
    if len(nums) == 2:
        sum += nums[0] * nums[1]
print(sum) 