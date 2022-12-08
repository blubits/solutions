from itertools import permutations

primes = [2, 3, 5, 7, 11, 13, 17]
def substring_divisible(perm):
    for i in range(7):
        if int(perm[i + 1:i + 4]) % primes[i] != 0:
            return False
    return True

ans = 0
for perm in permutations("0123456789"):
    perm = ''.join(perm)
    if substring_divisible(perm):
        print(perm)
        ans += int(perm)
print(ans)
