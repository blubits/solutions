from itertools import permutations

i = 1
for perm in permutations(range(10)):
    if i == 1000000:
        print(''.join([str(x) for x in perm]))
        break
    i += 1
