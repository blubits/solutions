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

sieve = list(range(1000000))
prime_sieve(sieve)

prime_partial_sums = [i for i in sieve if i != 0]
for i in range(1, len(prime_partial_sums)):
    prime_partial_sums[i] += prime_partial_sums[i - 1]

mr = 0
ms = 0
for i in range(len(prime_partial_sums)):
    for j in range(i + 1, len(prime_partial_sums)):
        s = prime_partial_sums[j] - prime_partial_sums[i]
        r = j - i + 1
        if s < len(sieve) and sieve[s] and r > mr:
            print(s, r)
            mr = r
            ms = s
