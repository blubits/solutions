def is_prime(n):
    if n == 1:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

def number_spiral_diagonals():
    curr_number = 1
    change = 2
    yield [1]
    while True:
        lst = []
        for _ in range(4):
            curr_number += change
            lst.append(curr_number)
        change += 2
        yield lst

side_length = 1
primes = 0
total = 0
for lst in number_spiral_diagonals():
    for number in lst:
        if is_prime(number):
            primes += 1
        total += 1
    print(side_length, "by", side_length, "-", primes,
          "prime(s) of", total, "total, % prime =", primes / total)
    if 0 < (primes / total) < 0.1:
        break
    side_length += 2
