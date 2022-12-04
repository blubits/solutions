from fractions import Fraction

three_sevenths = Fraction(3, 7)
before_three_sevenths = 0

for i in range(999990, 1000001):
    for j in range(int(0.41 * i), int(0.43 * i) + 1):
        if before_three_sevenths < Fraction(j, i) < three_sevenths:
            # print(before_three_sevenths, '<',
            #       Fraction(j, i), '<', three_sevenths)
            before_three_sevenths = Fraction(j, i)


print(before_three_sevenths)
