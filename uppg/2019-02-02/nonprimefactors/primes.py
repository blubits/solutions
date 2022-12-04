n = list(range(int(2000001 ** 0.5) + 1))
n[0] = n[1] = 0

p = 2
while p != len(n):
    if n[p] != 0:
        for i in range(2 * p, len(n), p):
            n[i] = 0
    p += 1

primes = [i for i in n if i != 0]
f = open("primes.txt", "w")
f.write("{")
f.write(', '.join([str(p) for p in primes]))
f.write("}\n")
