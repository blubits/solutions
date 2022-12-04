from math import ceil

def count_prime_factors(n):
    pf = set()
    p = 2
    while p <= ceil(n ** 0.5):
        if n % p == 0:
            pf.add(p)
            n //= p
        else:
            if p == 2:
                p = 3
            else:
                p += 2
    if n != 1:
        pf.add(n)
    return len(pf)

four_primes = 0
for i in range(1, 1000000):
    if count_prime_factors(i) == 4:
        four_primes += 1
    else:
        if four_primes > 2:
            print(
                "{0}-length run found from {1} to {2}".format(four_primes, i - four_primes + 1, i))
        four_primes = 0
    if four_primes == 4:
        print(
            "{0}-length run found from {1} to {2}".format(four_primes, i - four_primes + 1, i))
        break
