sequences = [[int(x) for x in line.rstrip().split()] for line in open("inputsmall").readlines()]

sum = 0
for sequence in sequences:
    curr = sequence.copy()
    differences = [sequence.copy()]
    while any(curr):
        curr = list(map(lambda x: x[1] - x[0], zip(curr[:-1], curr[1:])))
        differences.append(curr.copy())
    differences.reverse()
    differences[0].append(0)
    for i in range(1, len(differences)):
        differences[i].append(differences[i][-1] + differences[i - 1][-1])
    sum += differences[-1][-1]
print(sum)