def basin(board, visited, i, j):
    if board[i][j] == 9:
        return 0
    size = 1
    visited[i][j] = True
    if i != 0 and not visited[i - 1][j]:
        size += basin(board, visited, i - 1, j)
    if i != len(board) - 1 and not visited[i + 1][j]:
        size += basin(board, visited, i + 1, j)
    if j != 0 and not visited[i][j - 1]:
        size += basin(board, visited, i, j - 1)
    if j != len(board[0]) - 1 and not visited[i][j + 1]:
        size += basin(board, visited, i, j + 1)
    return size

def solve(lines):
    board = [[int(x) for x in line] for line in lines]
    visited = [[False for x in line] for line in lines]
    basins = []
    for i in range(len(board)):
        for j in range(len(board[0])):
            lowpoint = True
            if i != 0:
                lowpoint = lowpoint and (board[i - 1][j] > board[i][j])
            if i != len(board) - 1:
                lowpoint = lowpoint and (board[i + 1][j] > board[i][j])
            if j != 0:
                lowpoint = lowpoint and (board[i][j - 1] > board[i][j])
            if j != len(board[0]) - 1:
                lowpoint = lowpoint and (board[i][j + 1] > board[i][j])
            if lowpoint:
                basins.append(basin(board, visited, i, j))
    basins.sort(reverse=True)
    return basins[0] * basins[1] * basins[2]

with open("input") as input_file:
    print(solve([line.rstrip() for line in input_file.readlines()]))