from fractions import Fraction

def D(n):
    if n % 3 == 2:
        return 2 * (n // 3 + 1)
    return 1

def cfrac(n, d, k):
    def recur(i):
        if i > k:
            return 0
        else:
            return Fraction(n(i), d(i) + recur(i + 1))
    return recur(1)

result = 2 + cfrac(lambda n: 1, D, 99)
print(sum([int(x) for x in str(result.numerator)]))
