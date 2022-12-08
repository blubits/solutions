from fractions import Fraction

x = 1
count = 0
for _ in range(1000):
    x = 1 + Fraction(1, x + 1)
    if len(str(x.numerator)) > len(str(x.denominator)):
        print(x)
        count += 1
print(count)
