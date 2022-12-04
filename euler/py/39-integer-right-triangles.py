from math import gcd, ceil

"""
The solution below relies on Euclid's formula for generating Pythagorean
triples:

    a = m^2 + n^2
    b = 2mn
    c = m^2 - n^2

Either one of a, b, or c must be equal to the number we're looking for, x.
For each formula, we try to look for the values (m, n) that make the
equality a/b/c = x true.

The most naive way to do this (and probably the easiest) is to simply
run through all possible pairs of values (m, n), up to (x, x). You'll
have to take care of the wrong values that come up, but otherwise the
solution will be correct.

A better solution involves factorization. The specifics are in the
code below, if you're interested, but we're basically taking advantage
of the fact that

b/2 = (m)(n)
c = (m - n)(m + n)

and trying to find integer solutions to these equalities.
"""

def A(m, n):
    return (m ** 2) - (n ** 2)

def B(m, n):
    return 2 * m * n

def C(m, n):
    return (m ** 2) + (n ** 2)

def coprime(x, y, z):
    return gcd(x, y) == 1 and gcd(y, z) == 1 and gcd(x, z) == 1

def not_coprime(x, y, z):
    return gcd(x, y) != 1 and gcd(y, z) != 1 and gcd(x, z) != 1

def find_triplets_naive(x):
    # Runtime approx 3x^2
    ans_a = []
    ans_b = []
    ans_c = []
    # General algorithm: generate and iterate through all pairs of (m, n) up
    # until (x-1, x-1) and check if it can generate a valid triple per Euclid
    # (1) Get (other side, hypotenuse) given (side)
    for m in range(1, x):
        for n in range(1, x):
            at = A(m, n)
            bt = B(m, n)
            ct = C(m, n)
            # We check if the gcd of all three numbers is equal to 1
            # to prevent non-primitive triplets from getting into our
            # answer
            if at == x and coprime(x, bt, ct):
                ans_a.append((x, bt, ct))
            # Since m^2 - n^2 can be negative, we check for signs here
            if bt == x and at > 0 and coprime(at, x, ct):
                if x > at:
                    ans_b.append((at, x, ct))
                else:
                    ans_a.append((x, at, ct))
    # (2) Get (side, other side) given (hypotenuse)
    for m in range(1, x):
        for n in range(1, x):
            at = A(m, n)
            bt = B(m, n)
            ct = C(m, n)
            if ct == x and at > 0 and coprime(at, bt, x):
                ans_c.append((at, bt, x))
    return ans_a + ans_b + ans_c


pair_factors = {}
def generate_pair_factors(x):
    """
    Generates a list of pairs (a, b) such that ab * x, i.e. a and b are
    factors of x.
    """
    # Employs memoization
    try:
        return pair_factors[x]
    except KeyError:
        ans = []
        for i in range(1, ceil(x ** 0.5) + 1):
            if x / i == x // i:
                ans.append((x // i, i))
        pair_factors[x] = tuple(ans)
        return tuple(ans)

def find_triplets_factorize(x):
    # Runtime approx x^2 + 2sqrt(x)
    # Asymptotically the same as above, but the change in algorithms
    # for two cases vastly improves running time
    ans_a = []
    ans_b = []
    ans_c = []
    # (1) Get (other side, hypotenuse) given (side)
    # Instead of iterating through all possible pairs, we use the
    # following facts:
    # (a) Since b = 2mn, mn = b//2; (m, n) are the factors of b/2
    # (b) Since a = m^2 - n^2, a = (m+n)(m-n); (m - n, m + n) are the factors
    # of b, and the sum of these factors over 2 is equal to m
    pairs_b = [] if x % 2 != 0 else generate_pair_factors(x // 2)
    pairs_a = [pair for pair in generate_pair_factors(x)
               if (pair[0] + pair[1]) % 2 == 0]
    # For (b), we transform (m + n, m - n) into (m, n)
    # Again, adding m + n + m - n -> 2m
    # We can then get n by subtracting m from the first element of the pair
    for mt, nt in reversed(pairs_a):
        m = (mt + nt) // 2
        n = mt - m
        bt = B(m, n)
        ct = C(m, n)
        if bt <= 0 or not_coprime(x, bt, ct):
            continue
        elif bt > x:
            ans_a.append((x, bt, ct))
        else:
            ans_b.append((bt, x, ct))
    # Simple straightforward iteration
    for m, n in reversed(pairs_b):
        at = A(m, n)
        ct = C(m, n)
        if at <= 0 or not_coprime(at, x, ct):
            continue
        elif at > x:
            ans_a.append((x, at, ct))
        else:
            ans_b.append((at, x, ct))
    # (2) Get (side, other side) given (hypotenuse)
    # No choice but to bruteforce here
    # Note that we're only looping until sqrt(x); m^2 + n^2 cannot be greater
    # than a, so m or n must be less than sqrt(x)
    for m in range(1, ceil(x ** 0.5)):
        for n in range(1, ceil(x ** 0.5)):
            if m < n:
                # m^2 - n^2 will be negative; skip pair
                continue
            if (m + n) > x:
                # m^2 + n^2 will be greater than x; skip par
                # To see why this holds true, square both sides
                continue
            if gcd(m, n) != 1:
                # Skip pairs of (m, n) that are not coprime
                # since this will result in a non-primitive triplet
                continue
            at = A(m, n)
            bt = B(m, n)
            ct = C(m, n)
            if ct == x and at > 0 and coprime(at, bt, x):
                if at < bt:
                    ans_c.append((at, bt, x))
                else:
                    ans_c.append((bt, at, x))
    return ans_a + ans_b + ans_c

# -----------------------------------------------


nums = range(1, 1001)

d = {}
for num in nums:
    answ = find_triplets_factorize(num)
    for ans in answ:
        s = sum(ans)
        for i in range(1, (1000 // s) + 1):
            if s * i in d:
                d[s * i] += 1
            else:
                d[s * i] = 1

for i in range(1, 1001):
    if i in d:
        print(i, d[i])
