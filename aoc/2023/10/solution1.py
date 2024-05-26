import queue

grid = [line.rstrip() for line in open("input").readlines()]
visited = [[False for cell in line] for line in grid]
distance = [[0 for cell in line] for line in grid]

def neighbors(i, j):
    """
              (7/F/|)
    (-/L/F)      .      (-/J/7)
              (L/J/|)
    """
    neighbors_list = []
    if grid[i][j] == "S":
        # north
        if i != 0 and grid[i - 1][j] in "7F|":
            neighbors_list.append((i - 1, j))
        # south
        if i != len(grid) - 1 and grid[i + 1][j] in "LJ|":
            neighbors_list.append((i + 1, j))
        # west
        if j != 0 and grid[i][j - 1] in "-LF":
            neighbors_list.append((i, j - 1))
        # east
        if j != len(grid[0]) - 1 and grid[i][j + 1] in "-J7":
            neighbors_list.append((i, j + 1))
    else:
        # north
        if i != 0 and grid[i][j] in "LJ|":
            neighbors_list.append((i - 1, j))
        # south
        if i != len(grid) - 1 and grid[i][j] in "7F|":
            neighbors_list.append((i + 1, j))
        # west
        if j != 0 and grid[i][j] in "-J7":
            neighbors_list.append((i, j - 1))
        # east
        if j != len(grid[0]) - 1 and grid[i][j] in "-LF":
            neighbors_list.append((i, j + 1))
    return neighbors_list
        
Sx, Sy = -1, -1
for i in range(len(grid)):
    for j in range(len(grid[i])):
        if grid[i][j] == "S":
            Sx, Sy = i, j
            break
    if not (Sx == -1 and Sy == -1):
        break

q = queue.Queue()
q.put((Sx, Sy))
distance[Sx][Sy] = 0
while not q.empty():
    Cx, Cy = q.get()
    visited[Cx][Cy] = True
    for Nx, Ny in neighbors(Cx, Cy):
        if not visited[Nx][Ny]:
            q.put((Nx, Ny))
            distance[Nx][Ny] = distance[Cx][Cy] + 1
print(max([max(line) for line in distance]))