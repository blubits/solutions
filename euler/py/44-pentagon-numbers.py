def P(n):
    return (n * (3 * n - 1)) // 2

def isP(n):
    return (24 * n + 1) ** 0.5 % 6 == 5

PN = [P(n) for n in range(100000)]

min_dist = 1000000000000000
min_i = 0
min_j = 0
for i in range(1, 100000):
    for j in range(i + 1, 100000):
        if isP(PN[i] + PN[j]) and isP(PN[j] - PN[i]):
            if PN[j] - PN[i] < min_dist:
                min_dist = PN[j] - PN[i]
                min_i = i
                min_j = j
                print(min_i, min_j, PN[min_i], PN[min_j], min_dist)
