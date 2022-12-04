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

circular_primes = 0
for number in sieve:
    if number != 0:
        # prime
        if number < 10:
            # automatic circular prime
            circular_primes += 1
        else:
            for i in range(1, len(str(number))):
                new_num = int(str(number)[i:] + str(number)[:i])
                if sieve[new_num] == 0:
                    break
            else:
                circular_primes += 1
print(circular_primes)
