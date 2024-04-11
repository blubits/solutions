sequences = [[int(x) for x in line.rstrip().split()] for line in open("input").readlines()]

sum = 0
for sequence in sequences:
    curr = sequence.copy()
    differences = [sequence.copy()]
    while any(curr):
        curr = list(map(lambda x: x[1] - x[0], zip(curr[:-1], curr[1:])))
        differences.append(curr.copy())
    differences.reverse()
    differences[0].insert(0, 0)
    for i in range(1, len(differences)):
        differences[i].insert(0, differences[i][0] - differences[i - 1][0])
    sum += differences[-1][0]
print(sum)