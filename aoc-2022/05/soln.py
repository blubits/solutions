# [N]     [Q]         [N]            
# [R]     [F] [Q]     [G] [M]        
# [J]     [Z] [T]     [R] [H] [J]    
# [T] [H] [G] [R]     [B] [N] [T]    
# [Z] [J] [J] [G] [F] [Z] [S] [M]    
# [B] [N] [N] [N] [Q] [W] [L] [Q] [S]
# [D] [S] [R] [V] [T] [C] [C] [N] [G]
# [F] [R] [C] [F] [L] [Q] [F] [D] [P]
#  1   2   3   4   5   6   7   8   9

stacks = [
    list("FDBZTJRN"),
    list("RSNJH"),
    list("CRNJGZFQ"),
    list("FVNGRTQ"),
    list("LTQF"),
    list("QCWZBRGN"),
    list("FCLSNHM"),
    list("DNQMTJ"),
    list("PGS")
] 

with open("input") as input_file:
    for line in input_file.readlines():
        instruction = line.split(" ")
        qty, fr, to = int(instruction[1]), int(instruction[3]) - 1, int(instruction[5]) - 1
        blocks = stacks[fr][len(stacks[fr]) - qty:]
        del stacks[fr][len(stacks[fr]) - qty:]
        stacks[to].extend(blocks)
for stack in stacks:
    print(stack[-1], end='')
print()