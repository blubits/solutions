from collections import deque, namedtuple

def print_board(board):
    for line in board:
        for t in line:
            if t == True:
                print("X", end='')
            else:
                print(".", end='')
        print()
    print()

def dm(x1, y1, x2, y2):
    return abs(y2 - y1) + abs(x2 - x1)

def not_bfs(initial_nodes):
    l = max(node[0] for node in initial_nodes) + 1
    w = max(node[1] for node in initial_nodes) + 1
    visited = [[False for _ in range(w)] for _ in range(l)]
    c = 0

    for i in range(l):
        for j in range(w):
            sum_dist = sum([dm(i, j, x, y) for x, y in initial_nodes])
            if sum_dist < 10000:
                visited[i][j] = True
                c += 1
            else:
                visited[i][j] = False

    print_board(visited)
    return c

with open("input.txt") as input_file:
    coords = [line.rstrip("\n") for line in input_file.readlines()]
    l = []
    for coord in coords:
        x, y = coord.split(", ")
        l.append((int(y), int(x)))
    print(not_bfs(l))
