def signum(x):
    if x > 0:
        return 1
    elif x < 0:
        return -1
    else:
        return 0


def solve(lines):
    board = [[0 for i in range(1000)] for j in range(1000)]
    for line in lines:
        fr, to = line.split(" -> ")
        x1, y1 = [int(x) for x in fr.split(",")]
        x2, y2 = [int(x) for x in to.split(",")]
        dx, dy = signum(x2 - x1), signum(y2 - y1)
        xc, yc = x1, y1
        while True:
            board[xc][yc] += 1
            xc += dx
            yc += dy
            if xc == x2 and yc == y2:
                break 
        board[xc][yc] += 1
    ans = 0
    for row in board:
        for item in row:
            if item > 1:
                ans += 1
    return ans


with open("input") as input_file:
    print(solve([line.rstrip() for line in input_file.readlines()]))
