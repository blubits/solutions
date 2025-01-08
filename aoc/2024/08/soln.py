# TODO: Faster checks.
# For Part 1, is there an equation we can solve here? I think for every
# *ordered* pair of points, there's only one point along the same line such that
# dist(P, P1) + dist(P1, P2) == dist(P, P2) and dist(P, P1) * 2 == dist(P, P2).
# For Part 2, we can just count the lattice points of every line that two 
# points make, then subtract the intersection points.

FILENAME = "input"

def parse(filename):
    with open(filename) as f:
        return [list(line.strip()) for line in f]

def dist(tup1, tup2):
    return ((tup1[0] - tup2[0]) * (tup1[0] - tup2[0]) + (tup1[1] - tup2[1]) * (tup1[1] - tup2[1])) ** 0.5

def slope(tup1, tup2):
    try:
        return (tup2[0] - tup1[0]) / (tup2[1] - tup1[1])
    except ZeroDivisionError:
        return float("inf")

def locate_antennas(fmap):
    antennas = []
    for i in range(len(fmap)):
        for j in range(len(fmap[0])):
            if fmap[i][j] != ".":
                antennas.append((i, j))
    return antennas
    
def solve(data):
    antennas = locate_antennas(data)
    ans = 0
    for i in range(len(data)):
        for j in range(len(data[0])):
            found = False
            for a1 in antennas:
                for a2 in antennas:
                    if data[a1[0]][a1[1]] != data[a2[0]][a2[1]]: continue
                    if a1 == a2: continue
                    if dist((i, j), a1) + dist(a1, a2) == dist((i, j), a2):
                        if dist((i, j), a1) * 2 == dist((i, j), a2):
                            found = True
                            ans += 1
                            break
                if found: break
    return ans


def solve2(data):
    antennas = locate_antennas(data)
    antenna_freqs = []
    ans = 0
    for i, j in antennas:
        antenna_freqs.append(data[i][j])
    for i, j in antennas:
        if antenna_freqs.count(data[i][j]) == 1:
            ans -= 1
    ans += len(antennas)
    board = [row.copy() for row in data]
    for i in range(len(data)):
        for j in range(len(data[0])):
            found = False
            if (i, j) in antennas: continue
            for a1 in antennas:
                for a2 in antennas:
                    if data[a1[0]][a1[1]] != data[a2[0]][a2[1]]: continue
                    if a1 == a2: continue
                    if slope((i, j), a1) == slope(a1, a2) and slope(a1, a2) == slope((i, j), a2):
                        found = True
                        board[i][j] = "#"
                        ans += 1
                        break
                if found: break
    return ans

data = parse(FILENAME)
print(solve(data))
print(solve2(data))