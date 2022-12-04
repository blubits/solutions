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

sieve = list(range(2000001))
prime_sieve(sieve)

for number in range(3, 10000):
    if sieve[number] == 0 and number % 2 == 1:
        # odd composite
        possible_squares = int((number // 2) ** 0.5)
        for i in range(possible_squares, 0, -1):
            if sieve[number - (2 * i * i)]:
                print("{0} = {1} + 2*{2}^2".format(number,
                                                   number - (2 * i * i), i))
                break
        else:
            print("{0} fails Goldbach's other conjecture".format(number))
            break
