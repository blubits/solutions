def P(a, b):
    def Pn(n):
        return (n ** 2) + (a * n) + (b)
    return Pn

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

sieve = list(range(1000001))
prime_sieve(sieve)

max_prod = 0
max_run = 0
for a in range(-1000, 1001):
    for b in range(-1000, 1001):
        f = P(a, b)
        run = 0
        while sieve[f(run)]:
            run += 1
        if run > max_run:
            print(a, b, run + 1)
            max_run = run + 1
            max_prod = abs(a * b)
print(max_prod)
