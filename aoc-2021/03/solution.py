def ox(lines):
    new_lines = []
    for i in range(12):
        if len(lines) == 1:
            return int(lines[0], base=2)
        count0, count1 = 0, 0
        for line in lines:
            if line[i] == "0":
                count0 += 1
            else:
                count1 += 1
        find = "0" if count0 > count1 else "1"
        for line in lines:
            if line[i] == find:
                new_lines.append(line)
        lines = new_lines
        new_lines = []
    return int(lines[0], base=2)

def co(lines):
    new_lines = []
    for i in range(12):
        if len(lines) == 1:
            return int(lines[0], base=2)
        count0, count1 = 0, 0
        for line in lines:
            if line[i] == "0":
                count0 += 1
            else:
                count1 += 1
        find = "1" if count0 > count1 else "0"
        for line in lines:
            if line[i] == find:
                new_lines.append(line)
        lines = new_lines
        new_lines = []
    return int(lines[0], base=2)

def solve(lines):
    return ox(lines) * co(lines)

with open("input") as input_file:
    print(solve([line.rstrip() for line in input_file.readlines()]))