def power_sum_fifths(n):
    return sum([int(x) ** 5 for x in str(n)])

x = 0
for i in range(10, 100000000):
    if i == power_sum_fifths(i):
        print(i)
        x += i
print(x)
