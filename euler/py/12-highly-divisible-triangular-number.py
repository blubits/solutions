from math import ceil

def count_factors(x):
    ans = 0
    for i in range(1, ceil(x ** 0.5) + 1):
        if x / i == x // i:
            if x // i == i:
                ans += 1
            else:
                ans += 2
    return ans

x = 2
ts = 1
count = 0
while count < 500:
    count = count_factors(ts)
    if count > 50:
        print(ts, count)
    ts += x
    x += 1
print(ts, count)
