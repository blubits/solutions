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

ans = 0
for number in sieve:
    if number > 10:
        s = str(number)
        for i in range(1, len(s)):
            if not (sieve[int(s[i:])] and sieve[int(s[:i])]):
                break
        else:
            print(number)
            for i in range(1, len(s)):
                print("\t{0}\t{1}".format(
                    sieve[int(s[i:])], sieve[int(s[:i])]))
            ans += number
print(ans)
