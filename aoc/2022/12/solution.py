import queue

def solve1(lines):
    board = [[ord(x) - ord("a") for x in line] for line in lines]
    visited = [[False for x in line] for line in lines]
    xs, ys, xe, ye = 0, 0, 0, 0
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == -14:
                board[i][j] = 0
                xs, ys = i, j
            elif board[i][j] == -28:
                board[i][j] = 25
                xe, ye = i, j
    q = queue.Queue()
    shortest_path = 10000
    q.put((xs, ys, 0))
    while not q.empty():
        x, y, length = q.get()
        if visited[x][y]:
            continue
        else:
            visited[x][y] = True
        if x == xe and y == ye:
            shortest_path = min(shortest_path, length)
            continue
        # up
        if x != 0 and board[x - 1][y] - board[x][y] <= 1:
            q.put((x - 1, y, length + 1))
        # down
        if x != len(board) - 1 and board[x + 1][y] - board[x][y] <= 1:
            q.put((x + 1, y, length + 1))
        # left
        if y != 0 and board[x][y - 1] - board[x][y] <= 1:
            q.put((x, y - 1, length + 1))
        # right
        if y != len(board[0]) - 1 and board[x][y + 1] - board[x][y] <= 1:
            q.put((x, y + 1, length + 1))
    return shortest_path


def solve2(lines):
    board = [[ord(x) - ord("a") for x in line] for line in lines]
    xs, ys, xe, ye = 0, 0, 0, 0
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == -14:
                board[i][j] = 0
                xs, ys = i, j
            elif board[i][j] == -28:
                board[i][j] = 25
                xe, ye = i, j
    q = queue.Queue()
    shortest_path = 10000
    for i in range(len(board)):
        for j in range(len(board[i])):
            visited = [[False for x in line] for line in lines]
            if board[i][j] == 0:
                q.put((i, j, 0))
                while not q.empty():
                    x, y, length = q.get()
                    if visited[x][y]:
                        continue
                    else:
                        visited[x][y] = True
                    if x == xe and y == ye:
                        shortest_path = min(shortest_path, length)
                        continue
                    # up
                    if x != 0 and board[x - 1][y] - board[x][y] <= 1:
                        q.put((x - 1, y, length + 1))
                    # down
                    if x != len(board) - 1 and board[x + 1][y] - board[x][y] <= 1:
                        q.put((x + 1, y, length + 1))
                    # left
                    if y != 0 and board[x][y - 1] - board[x][y] <= 1:
                        q.put((x, y - 1, length + 1))
                    # right
                    if y != len(board[0]) - 1 and board[x][y + 1] - board[x][y] <= 1:
                        q.put((x, y + 1, length + 1))
    return shortest_path


with open("input") as input_file:
    lines = [line.rstrip() for line in input_file.readlines()]
    print(solve1(lines))
    print(solve2(lines))
