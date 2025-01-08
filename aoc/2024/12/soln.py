FILENAME = "inputsmall"

def parse(filename):
    with open(filename) as f:
        return [list(line.strip()) for line in f]
    
def solve(data):
    # Floodfill.
    regions = []
    visited = [[False for cell in row] for row in data]
    R, C = len(visited), len(visited[0])
    ans = 0
    for i in range(R):
        for j in range(C):
            if not visited[i][j]:
                plant_type = data[i][j]
                queue = [(i, j)]
                area, perimeter = 0, 0
                visited[i][j] = True
                while queue:
                    ci, cj = queue.pop(0)
                    area += 1
                    # Up
                    if ci > 0:
                        if data[ci - 1][cj] == plant_type:
                            if not visited[ci - 1][cj]:
                                queue.append((ci - 1, cj))
                                visited[ci - 1][cj] = True
                        else:
                            perimeter += 1
                    else:
                        perimeter += 1
                    # Down
                    if ci < R - 1:
                        if data[ci + 1][cj] == plant_type:
                            if not visited[ci + 1][cj]:
                                queue.append((ci + 1, cj))
                                visited[ci + 1][cj] = True
                        else:
                            perimeter += 1
                    else:
                        perimeter += 1
                    # Left
                    if cj > 0:
                        if data[ci][cj - 1] == plant_type:
                            if not visited[ci][cj - 1]:
                                queue.append((ci, cj - 1))
                                visited[ci][cj - 1] = True
                        else:
                            perimeter += 1
                    else:
                        perimeter += 1
                    # Right
                    if cj < C - 1:
                        if data[ci][cj + 1] == plant_type:
                            if not visited[ci][cj + 1]:
                                queue.append((ci, cj + 1))
                                visited[ci][cj + 1] = True
                        else:
                            perimeter += 1
                    else:
                        perimeter += 1
                regions.append((plant_type, area, perimeter))
                ans += area * perimeter
    return ans

def calculate_sides(region, boundary_start, R, C):
    for row in region:
        print(''.join("X" if cell else "." for cell in row))

    boundary = [boundary_start]
    directions = [(-1, 0), (0, 1), (1, 0), (0, -1), ]

    current = boundary_start
    current_direction = 0

    visited = set()
    visited.add(boundary_start)
    while True:
        for d in directions:
            ni, nj = current[0] + d[0], current[1] + d[1]
            if 0 <= ni < R and 0 <= nj < C and (ni, nj) not in visited and region[ni][nj]:
                boundary.append((ni, nj))
                visited.add((ni, nj))
                current = (ni, nj)
                break
        else:
            break
    print(boundary) 


def solve2(data):
    # Floodfill first.
    regions = []
    visited = [[False for cell in row] for row in data]
    R, C = len(visited), len(visited[0])
    ans = 0
    for i in range(R):
        for j in range(C):
            if not visited[i][j]:
                plant_type = data[i][j]
                region = [[False for cell in row] for row in data]
                queue = [(i, j)]
                area, perimeter = 0, 0
                visited[i][j] = True
                region[i][j] = True
                while queue:
                    ci, cj = queue.pop(0)
                    area += 1
                    # Up
                    if ci > 0:
                        if data[ci - 1][cj] == plant_type:
                            if not visited[ci - 1][cj]:
                                queue.append((ci - 1, cj))
                                visited[ci - 1][cj] = True
                                region[ci - 1][cj] = True
                    # Down
                    if ci < R - 1:
                        if data[ci + 1][cj] == plant_type:
                            if not visited[ci + 1][cj]:
                                queue.append((ci + 1, cj))
                                visited[ci + 1][cj] = True
                                region[ci + 1][cj] = True
                    # Left
                    if cj > 0:
                        if data[ci][cj - 1] == plant_type:
                            if not visited[ci][cj - 1]:
                                queue.append((ci, cj - 1))
                                visited[ci][cj - 1] = True
                                region[ci][cj - 1] = True
                    # Right
                    if cj < C - 1:
                        if data[ci][cj + 1] == plant_type:
                            if not visited[ci][cj + 1]:
                                queue.append((ci, cj + 1))
                                visited[ci][cj + 1] = True
                                region[ci][cj + 1] = True
                regions.append((plant_type, area))
                print(plant_type)
                sides = calculate_sides(region, (i, j), R, C)
    return regions

data = parse(FILENAME)
print(solve(data))
print(solve2(data))