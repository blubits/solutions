amicable = [0] * 10001

def sum_divisors(n):
    ans = []
    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            if i * i == n:
                ans.append(i)
            else:
                ans.extend([i, n // i])
    return sum(ans) - n

for i in range(1, 10001):
    amicable[i] = sum_divisors(i)

amicable_sum = 0
for i in range(1, 10001):
    if amicable[i] > 10000:
        if i == sum_divisors(amicable[i]):
            amicable_sum += i + amicable[i]
    else:
        if i != amicable[i] and i == amicable[amicable[i]]:
            amicable_sum += i + amicable[i]
print(amicable_sum // 2)
