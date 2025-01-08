FILENAME = "input"

def custom_int(s):
    if s == ".": return -10000
    else: return int(s)

def parse(filename):
    with open(filename) as f:
        return [list(map(custom_int, line.strip())) for line in f]

def locate_starts(board):
    starts = []
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == 0:
                starts.append((i, j))
    return starts

def neighbors(i, j, board):
    res = []
    if i > 0 and board[i - 1][j] - board[i][j] == 1: 
        res.append((i - 1, j))
    if i < len(board) - 1 and board[i + 1][j] - board[i][j] == 1: 
        res.append((i + 1, j))
    if j > 0 and board[i][j - 1] - board[i][j] == 1: 
        res.append((i, j - 1))
    if j < len(board[0]) - 1 and board[i][j + 1] - board[i][j] == 1: 
        res.append((i, j + 1))
    return res

def neighbors_T(i, j, board):
    res = []
    if i > 0 and board[i - 1][j] - board[i][j] == -1: 
        res.append((i - 1, j))
    if i < len(board) - 1 and board[i + 1][j] - board[i][j] == -1: 
        res.append((i + 1, j))
    if j > 0 and board[i][j - 1] - board[i][j] == -1: 
        res.append((i, j - 1))
    if j < len(board[0]) - 1 and board[i][j + 1] - board[i][j] == -1: 
        res.append((i, j + 1))
    return res
    
def solve(data):
    starts = locate_starts(data)
    ans = 0
    for i, j in starts:
        visited = [[False for cell in row] for row in data]
        bfs_queue = [(i, j)]
        while bfs_queue:
            ci, cj = bfs_queue.pop(0)
            if data[ci][cj] == 9 and not visited[ci][cj]:
                ans += 1
            visited[ci][cj] = True
            for ni, nj in neighbors(ci, cj, data):
                if not visited[ni][nj]:
                    bfs_queue.append((ni, nj))
    return ans

def solve2(data):
    starts = locate_starts(data)
    ans = 0
    for i, j in starts:
        # Pass 1: Explore the graph to find the trail.
        visited = [[False for cell in row] for row in data]
        num_paths = [[0 for cell in row] for row in data]
        bfs_queue = [(i, j)]
        nines_queue = []
        while bfs_queue:
            ci, cj = bfs_queue.pop(0)
            if data[ci][cj] == 9 and not visited[ci][cj]:
                nines_queue.append((ci, cj))
                num_paths[ci][cj] = 1
            visited[ci][cj] = True
            for ni, nj in neighbors(ci, cj, data):
                if not visited[ni][nj]:
                    bfs_queue.append((ni, nj))
        visited = [[False for cell in row] for row in data]
        edges = set()
        while nines_queue:
            ci, cj = nines_queue.pop(0)
            visited[ci][cj] = True
            for ni, nj in neighbors_T(ci, cj, data):
                if not visited[ni][nj]:
                    nines_queue.append((ni, nj))
                    if (ni, nj, ci, cj) not in edges:
                        num_paths[ni][nj] += num_paths[ci][cj]
                        edges.add((ni, nj, ci, cj))
        ans += num_paths[i][j]
    return ans

data = parse(FILENAME)
print(solve(data))
print(solve2(data))