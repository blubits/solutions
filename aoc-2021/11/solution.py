def solve1(lines):
    board = [[int(x) for x in line] for line in lines]
    flashes = 0
    steps = 100
    UNFLASHED = 0
    FLASHING = 1
    FLASHED = 2
    for _ in range(steps):
        board = [[x + 1 for x in line] for line in board]
        status = [[FLASHING if x >= 10 else UNFLASHED for x in line] for line in board]
        has_flashing = False
        while True:
            has_flashing = False
            for i in range(len(board)):
                for j in range(len(board[0])):
                    if status[i][j] == FLASHING:
                        flashes += 1
                        has_flashing = True
                        for dx in [-1, 0, 1]:
                            for dy in [-1, 0, 1]:
                                if not (dx == 0 and dy == 0):
                                    if 0 <= i + dx < len(board) and 0 <= j + dy < len(
                                        board[0]
                                    ):
                                        board[i + dx][j + dy] += 1
                                        if (
                                            board[i + dx][j + dy] >= 10
                                            and status[i + dx][j + dy] == UNFLASHED
                                        ):
                                            status[i + dx][j + dy] = FLASHING
                        status[i][j] = FLASHED
            if not has_flashing:
                board = [[0 if x >= 10 else x for x in line] for line in board]
                break
    return flashes


def solve2(lines):
    board = [[int(x) for x in line] for line in lines]
    flashes = 0
    steps = 10000
    UNFLASHED = 0
    FLASHING = 1
    FLASHED = 2
    for _ in range(steps):
        board = [[x + 1 for x in line] for line in board]
        status = [[FLASHING if x >= 10 else UNFLASHED for x in line] for line in board]
        has_flashing = False
        while True:
            has_flashing = False
            for i in range(len(board)):
                for j in range(len(board[0])):
                    if status[i][j] == FLASHING:
                        flashes += 1
                        has_flashing = True
                        for dx in [-1, 0, 1]:
                            for dy in [-1, 0, 1]:
                                if not (dx == 0 and dy == 0):
                                    if 0 <= i + dx < len(board) and 0 <= j + dy < len(
                                        board[0]
                                    ):
                                        board[i + dx][j + dy] += 1
                                        if (
                                            board[i + dx][j + dy] >= 10
                                            and status[i + dx][j + dy] == UNFLASHED
                                        ):
                                            status[i + dx][j + dy] = FLASHING
                        status[i][j] = FLASHED
            if not has_flashing:
                board = [[0 if x >= 10 else x for x in line] for line in board]
                if all([all(line) for line in status]):
                    print(status)
                    return _
                break
    return flashes


filename = "input"

with open(filename) as input_file:
    lines = [line.rstrip() for line in input_file.readlines()]
    print(solve1(lines))
    print(solve2(lines))
