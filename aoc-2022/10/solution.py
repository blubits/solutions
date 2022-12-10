def solve1(lines):
    instructions = [line.split() for line in lines]
    cycle = 0
    register = 1
    values = {}
    for instruction in instructions:
        if instruction[0] == "noop":
            cycle += 1
            values[cycle] = register
        else:
            cycle += 1
            values[cycle] = register
            cycle += 1
            values[cycle] = register
            register += int(instruction[1])
    values[cycle] = register
    return sum([i * values[i] for i in range(20, 221, 40)])

def solve2(lines):
    instructions = [line.split() for line in lines]
    cycle = 0
    register = 1
    values = {}
    for instruction in instructions:
        if instruction[0] == "noop":
            cycle += 1
            values[cycle] = register
        else:
            cycle += 1
            values[cycle] = register
            cycle += 1
            values[cycle] = register
            register += int(instruction[1])
    values[cycle] = register
    board = []
    for i in range(6):
        board.append([])
        for j in range(40):
            cycle = 1 + i * 40 + j
            posn = j
            board[i].append("██" if posn - 1 <= values[cycle] <= posn + 1 else "░░")
    return "\n".join(["".join(line) for line in board])



with open("input") as input_file:
    lines = [line.rstrip() for line in input_file.readlines()]
    print(solve1(lines))
    print(solve2(lines))
