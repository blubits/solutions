"""
Observation:
    Each node XXA cycles to a single node XXZ with regularity;
    get the length for each XXA=>XXZ cycle and simply
    find the LCM of all cycle lengths.
"""

from math import lcm

lines = [line.rstrip() for line in open("input").readlines()]
instructions = lines[0]
tree_lines = lines[2:]
tree = {}
for line in tree_lines:
    node, children = line.split(" = ")
    children = tuple(children[1:-1].split(", "))
    tree[node] = children
curr = [node for node in tree.keys() if node.endswith("A")]
regular_cycles = []
for node in curr:
    steps = 0
    cycle = []
    curr_node = node
    while True:
        step = instructions[steps % len(instructions)]
        if step == "L":
            curr_node = tree[curr_node][0]
        else:
            curr_node = tree[curr_node][1]
        steps += 1
        if curr_node.endswith("Z"):
            regular_cycles.append(steps)
            break
print(lcm(*regular_cycles))