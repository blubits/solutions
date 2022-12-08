from itertools import permutations, combinations, combinations_with_replacement

def prime_sieve(sieve):
    x = 2
    dx = 0
    sieve[1] = 0
    SIZE = len(sieve) - 1
    try:
        while x < SIZE:
            while sieve[x] == 0:
                x += 1
            dx = 2 * x
            while dx <= SIZE:
                sieve[dx] = 0
                dx += x
            x += 1
    except IndexError:
        pass

sieve = list(range(10000))
prime_sieve(sieve)

for comb in combinations_with_replacement("123456789", 4):
    x = []
    for perm in permutations(comb):
        if sieve[int(''.join(perm))]:
            x.append(int(''.join(perm)))
    for sequence in combinations(x, 3):
        if sequence[2] != sequence[1] and sequence[2] - sequence[1] == sequence[1] - sequence[0]:
            print(''.join(str(x) for x in sequence))
