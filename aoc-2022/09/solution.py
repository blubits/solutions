def solve1(lines):
    directions = [line.split() for line in lines]
    initx, inity = 0, 0
    xu, xd, yl, yr = 0, 0, 0, 0
    tail_posn = {}
    x = [0 for i in range(2)]
    y = [0 for i in range(2)]
    tail_posn[(x[1], y[1])] = 1
    for direction, amount in directions:
        #print(direction, amount)
        amount = int(amount)
        dx, dy = 0, 0
        if direction == "U":
            dx = -1
        elif direction == "D":
            dx = 1
        elif direction == "L":
            dy = -1
        else:
            dy = 1
        xhn, yhn = x[0] + (amount * dx), y[0] + (amount * dy)
        while x[0] != xhn or y[0] != yhn:
            x[0], y[0] = x[0] + dx, y[0] + dy
            for i in range(1):
                if abs(x[i] - x[i + 1]) == 0 and abs(y[i] - y[i + 1]) == 2:
                    y[i + 1] += (y[i] - y[i + 1]) // 2
                if abs(x[i] - x[i + 1]) == 2 and abs(y[i] - y[i + 1]) == 0:
                    x[i + 1] += (x[i] - x[i + 1]) // 2
                if abs(x[i] - x[i + 1]) == 1 and abs(y[i] - y[i + 1]) == 2:
                    x[i + 1] = x[i]
                    y[i + 1] += (y[i] - y[i + 1]) // 2
                if abs(x[i] - x[i + 1]) == 2 and abs(y[i] - y[i + 1]) == 1:
                    y[i + 1] = y[i]
                    x[i + 1] += (x[i] - x[i + 1]) // 2
                if abs(x[i] - x[i + 1]) == 2 and abs(y[i] - y[i + 1]) == 2:
                    y[i + 1] += (y[i] - y[i + 1]) // 2
                    x[i + 1] += (x[i] - x[i + 1]) // 2
            tail_posn[(x[1], y[1])] = 1
    return sum(tail_posn.values())

def solve2(lines):
    directions = [line.split() for line in lines]
    initx, inity = 0, 0
    xu, xd, yl, yr = 0, 0, 0, 0
    tail_posn = {}
    x = [0 for i in range(10)]
    y = [0 for i in range(10)]
    tail_posn[(x[9], y[9])] = 1
    for direction, amount in directions:
        #print(direction, amount)
        amount = int(amount)
        dx, dy = 0, 0
        if direction == "U":
            dx = -1
        elif direction == "D":
            dx = 1
        elif direction == "L":
            dy = -1
        else:
            dy = 1
        xhn, yhn = x[0] + (amount * dx), y[0] + (amount * dy)
        while x[0] != xhn or y[0] != yhn:
            x[0], y[0] = x[0] + dx, y[0] + dy
            for i in range(9):
                if abs(x[i] - x[i + 1]) == 0 and abs(y[i] - y[i + 1]) == 2:
                    y[i + 1] += (y[i] - y[i + 1]) // 2
                if abs(x[i] - x[i + 1]) == 2 and abs(y[i] - y[i + 1]) == 0:
                    x[i + 1] += (x[i] - x[i + 1]) // 2
                if abs(x[i] - x[i + 1]) == 1 and abs(y[i] - y[i + 1]) == 2:
                    x[i + 1] = x[i]
                    y[i + 1] += (y[i] - y[i + 1]) // 2
                if abs(x[i] - x[i + 1]) == 2 and abs(y[i] - y[i + 1]) == 1:
                    y[i + 1] = y[i]
                    x[i + 1] += (x[i] - x[i + 1]) // 2
                if abs(x[i] - x[i + 1]) == 2 and abs(y[i] - y[i + 1]) == 2:
                    y[i + 1] += (y[i] - y[i + 1]) // 2
                    x[i + 1] += (x[i] - x[i + 1]) // 2
            tail_posn[(x[9], y[9])] = 1
    return sum(tail_posn.values())

with open("input") as input_file:
    lines = [line.rstrip() for line in input_file.readlines()]
    print(solve1(lines))
    print(solve2(lines))
