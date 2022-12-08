def isP(n):
    return (24 * n + 1) ** 0.5 % 6 == 5

def isH(n):
    return (8 * n + 1) ** 0.5 % 4 == 3

triangle_numbers = list(range(100000))
for i in range(2, 100000):
    triangle_numbers[i] += triangle_numbers[i - 1]

for number in triangle_numbers:
    if isP(number) and isH(number):
        print(number)
