def solve(lines):
    fishes = [int(x) for x in lines[0].split(",")]
    # cycles[i] = number of fish that hatch on cycle `i`
    cycles_old = [0, 0, 0, 0, 0, 0, 0]
    # cycles[i] = number of new fish that reset-hatch on cycle `i`
    cycles_new = [0, 0, 0, 0, 0, 0, 0, 0, 0]
    for fish in fishes:
        cycles_old[fish] += 1
    for i in range(256):
        old_cycle = i % 7
        new_cycle = i % 9
        old_fish_count = cycles_old[old_cycle]
        new_fish_count = cycles_new[new_cycle]
        # every old fish births a new fish
        # every new fish also births a new fish
        cycles_new[new_cycle] += old_fish_count
        # every new fish matures into an old fish
        cycles_old[old_cycle] += new_fish_count
    return sum(cycles_old) + sum(cycles_new)

with open("input") as input_file:
    print(solve([line.rstrip() for line in input_file.readlines()]))