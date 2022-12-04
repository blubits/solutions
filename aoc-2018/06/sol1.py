def print_board(board):
    for line in board:
        for t in line:
            if t == (-1, 0):
                print(".", end='')
            elif t == (-2, 2):
                print("=", end='')
            else:
                if 0 <= t[0] <= 25:
                    print(chr(t[0] + ord('a')), end='')
                else:
                    print(chr(t[0] - 25 + ord('A')), end='')
        print()
    print()

def dm(x1, y1, x2, y2):
    return abs(y2 - y1) + abs(x2 - x1)

def not_bfs(initial_nodes):
    area = {i: 1 for i, node in enumerate(initial_nodes)}
    L = max(node[0] for node in initial_nodes) + 1
    W = max(node[1] for node in initial_nodes) + 1
    visited = [[(-1, 0) for _ in range(W)] for _ in range(L)]

    for i, node in enumerate(initial_nodes):
        visited[node[0]][node[1]] = (i, 0)

    def on_corner(i, j):
        return i == 0 or i == L - 1 or j == 0 or j == W - 1

    for i in range(L):
        for j in range(W):
            if visited[i][j][0] != -1 and visited[i][j][1] == 0:
                continue
            distances = [dm(i, j, x, y) for x, y in initial_nodes]
            min_dist = min(distances)
            if distances.count(min_dist) > 1:
                visited[i][j] = (-2, 2)
            else:
                visited[i][j] = (distances.index(min_dist), min_dist)
                if on_corner(i, j):
                    area[distances.index(min_dist)] = float("inf")
                elif area[distances.index(min_dist)] != float("inf"):
                    area[distances.index(min_dist)] += 1

    print_board(visited)
    return area

with open("input.txt") as input_file:
    coords = [line.rstrip("\n") for line in input_file.readlines()]
    ls = []
    for coord in coords:
        x, y = coord.split(", ")
        ls.append((int(y), int(x)))
    area, candidate = not_bfs(ls)
    print(area, candidate)
    print(max([a for i, a in area.items() if a != float("inf")]))
