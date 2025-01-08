FILENAME = "input"

def parse(filename):
    with open(filename) as f:
        return list(f.readline().strip())
    
def solve(data):
    curr_posn = 0+0j
    visited = {curr_posn}
    dir_vectors = {
        "<": -1,
        ">": 1,
        "^": -1j,
        "v": 1j
    }
    for move in data:
        curr_posn += dir_vectors[move]
        visited.add(curr_posn)
    return len(visited)

def solve2(data):
    curr_posn = 0+0j
    curr_posn_robo = 0+0j
    visited = {curr_posn}
    dir_vectors = {
        "<": -1,
        ">": 1,
        "^": -1j,
        "v": 1j
    }
    turn = 0
    for move in data:
        if not turn:
            curr_posn += dir_vectors[move]
            visited.add(curr_posn)
        else:
            curr_posn_robo += dir_vectors[move]
            visited.add(curr_posn_robo)
        turn = 0 if turn else 1
    return len(visited)

data = parse(FILENAME)
print(solve(data))
print(solve2(data))