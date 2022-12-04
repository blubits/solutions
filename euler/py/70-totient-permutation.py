from math import ceil

def prime_sieve(N):
    sieve = list(range(N + 1))
    sieve[1] = 0
    for i in range(2, int(N ** 0.5) + 1):
        if sieve[i]:
            sieve[i * i:N + 1:i] = [0] * ((N // i - i) + 1)
    return [i for i in sieve if i != 0]

def totients_up_to(N):
    totients = list(range(N + 1))
    primes = prime_sieve(N)
    for prime in primes:
        k = 1
        while k * prime <= N:
            totients[k * prime] = (totients[k * prime] // prime) * (prime - 1)
            k += 1
    return totients

phi = totients_up_to(10000000)

min_ratio = 100000000
for i in range(10000000, 1, -1):
    count = phi[i]
    ratio = i / count
    if ratio < min_ratio and sorted(str(count)) == sorted(str(i)):
        print(i, count, ratio)
        min_ratio = ratio
