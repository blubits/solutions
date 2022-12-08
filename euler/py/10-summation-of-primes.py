sieve = list(range(2000001))

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
    except:
        print(x, dx)

prime_sieve(sieve)
print(sieve[-1])
print(sum(sieve))
