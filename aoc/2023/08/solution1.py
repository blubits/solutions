lines = [line.rstrip() for line in open("input").readlines()]
instructions = lines[0]
tree_lines = lines[2:]
tree = {}
for line in tree_lines:
    node, children = line.split(" = ")
    children = tuple(children[1:-1].split(", "))
    tree[node] = children
curr = "AAA"
current_instruction = 0
steps = 0
while curr != "ZZZ":
    step = instructions[current_instruction % len(instructions)]
    if step == "L":
        curr = tree[curr][0]
    else:
        curr = tree[curr][1]
    steps += 1
    current_instruction += 1
print(steps)