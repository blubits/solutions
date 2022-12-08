from math import ceil

def prime_factors(n):
    pf = {}
    p = 2
    while p <= ceil(n ** 0.5):
        if n % p == 0:
            if p not in pf:
                pf[p] = 1
            else:
                pf[p] += 1
            n //= p
        else:
            if p == 2:
                p = 3
            else:
                p += 2
    if n != 1:
        if n not in pf:
            pf[n] = 1
        else:
            pf[n] += 1
    return pf

def phi(n):
    prod = 1
    for prime in prime_factors(n):
        prod *= (1 - (1 / prime))
    return int(n * prod)

for i in range(2, 1000000):
    phi(i)

# max_ratio = 0
# for i in range(2, 1000001):
#     count = phi(i)
#     ratio = i / count
#     if ratio > max_ratio:
#         print(i, count, ratio)
#         max_ratio = ratio
