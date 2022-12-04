from fractions import Fraction

def simplify_incorrectly(n, d):
    intersection = set(str(n)) & set(str(d))
    new_n = set(str(n)) - intersection
    new_d = set(str(d)) - intersection
    if len(new_d) == 2 or len(new_n) == 2:
        return -1
    try:
        return Fraction(int(new_n.pop()), int(new_d.pop()))
    except KeyError:
        return -1

product = 1
for i in range(11, 100):
    for j in range(10, i):
        if i % 10 != 0 and j % 10 != 0 and i % 11 != 0 and j % 11 != 0:
            if Fraction(j, i) == simplify_incorrectly(j, i):
                product *= Fraction(j, i)
print(product)
