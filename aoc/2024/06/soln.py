import re
from functools import cmp_to_key

FILENAME = "input"

def parse(filename):
    with open(filename) as f:
        return [list(line.strip()) for line in f]

def locate_guard(board):
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == "^":
                return (i, j)

def in_bounds(board, tup):
    x, y = tup
    return 0 <= x < len(board) and 0 <= y < len(board[0])

def move(posn, inc):
    return (posn[0] + inc[0], posn[1] + inc[1])

def solve(data):
    movement = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    curr_movement = 0
    curr_posn = locate_guard(data)
    board = [row.copy() for row in data]
    ans = 0
    while in_bounds(board, curr_posn):
        next_posn = move(curr_posn, movement[curr_movement])
        if not in_bounds(board, next_posn):
            ans += 1
            break
        if board[next_posn[0]][next_posn[1]] == "#":
            curr_movement = (curr_movement + 1) % 4
        else:
            if board[curr_posn[0]][curr_posn[1]] != "X":
                board[curr_posn[0]][curr_posn[1]] = "X"
                ans += 1
            curr_posn = next_posn
    return ans

def detect_loop(board, curr_dir, curr_posn):
    dir_vecs = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    visited = set()
    curr_dir = 0
    curr_posn = locate_guard(board)
    while in_bounds(board, curr_posn):
        next_posn = move(curr_posn, dir_vecs[curr_dir])
        if not in_bounds(board, next_posn):
            return False
        else:
            while board[next_posn[0]][next_posn[1]] == "#":
                curr_dir = (curr_dir + 1) % 4
                next_posn = move(curr_posn, dir_vecs[curr_dir])
            if (curr_posn, curr_dir) in visited:
                return True
            visited.add((curr_posn, curr_dir))
            curr_posn = next_posn

def solve2(data):
    board = [row.copy() for row in data]
    posns = set()
    ans = 0
    # Improved visiting strategy; now we're going to use a set instead of relying
    # on Xs.
    visited = set()
    dir_vecs = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    curr_dir = 0
    curr_posn = locate_guard(data)
    while in_bounds(board, curr_posn):
        next_posn = move(curr_posn, dir_vecs[curr_dir])
        if not in_bounds(board, next_posn):
            break
        else:
            while board[next_posn[0]][next_posn[1]] == "#":
                curr_dir = (curr_dir + 1) % 4
                next_posn = move(curr_posn, dir_vecs[curr_dir])
            board[next_posn[0]][next_posn[1]] = "#"
            if detect_loop(board, curr_dir, curr_posn):
                posns.add(next_posn)
            board[next_posn[0]][next_posn[1]] = "."
            visited.add((curr_posn, curr_dir))
            curr_posn = next_posn
    return len(posns)

data = parse(FILENAME)
print(solve(data))
print(solve2(data))
