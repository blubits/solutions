# A fraction in lowest terms with a prime denominator other than 2 or 5
# (i.e. coprime to 10) always produces a repeating decimal.

sieve = list(range(1001))

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
for i in range(1000, 0, -1):
    if sieve[i] != 0:
        print(sieve[i])
        break
