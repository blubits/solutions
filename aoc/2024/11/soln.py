FILENAME = "input"

def parse(filename):
    with open(filename) as f:
        return list(map(int, f.readline().strip().split()))
    
def solve(data):
    sim = data.copy()
    for i in range(25):
        new_sim = []
        for stone in sim:
            if stone == 0:
                new_sim.append(1)
                continue
            if len(str(stone)) % 2 == 0:
                s = str(stone)
                new_sim.append(int(s[:len(s)//2]))
                new_sim.append(int(s[len(s)//2:]))
            else:
                new_sim.append(stone * 2024)
        sim = new_sim
    return len(sim)

cache = {}
def count_stones(curr_stone, blinks_left):
    """
    This function takes a stone and a number of blinks left, and returns the
    number of stones that will be produced after the blinks are done.

    The rules for the blinks are as follows:
    - If the stone is 0, the next stone is 1
    - If the stone's length is even, the next two stones are the two halves of
      the stone
    - If the stone's length is odd, the next stone is the stone multiplied by
      2024
    """
    # There are tons of overlapping subproblems here, so having the cache
    # helps speed things up.
    if blinks_left == 0:
        return 1
    if (curr_stone, blinks_left) in cache:
        return cache[(curr_stone, blinks_left)]
    if curr_stone == 0:
        cache[(curr_stone, blinks_left)] = count_stones(1, blinks_left - 1)
        return cache[(curr_stone, blinks_left)]
    s = str(curr_stone)
    l = len(s)
    if l % 2 == 0:
        cache[(curr_stone, blinks_left)] = \
            count_stones(int(s[:l//2]), blinks_left - 1) \
                + count_stones(int(s[l//2:]), blinks_left - 1)
        return cache[(curr_stone, blinks_left)]
    else:
        cache[(curr_stone, blinks_left)] = \
            count_stones(curr_stone * 2024, blinks_left - 1)
        return cache[(curr_stone, blinks_left)] 

def solve2(data):
    sim = data.copy()
    times = 75
    ans = 0
    for stone in sim:
        ans += count_stones(stone, times)
    return ans 

data = parse(FILENAME)
print(solve(data))
print(solve2(data))