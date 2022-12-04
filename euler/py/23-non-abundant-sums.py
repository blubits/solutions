abundant_numbers = []
non_abundant_sums = list(range(28124))

def sum_divisors(n):
    ans = []
    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            if i * i == n:
                ans.append(i)
            else:
                ans.extend([i, n // i])
    return sum(ans) - n

for i in range(1, 28124):
    if sum_divisors(i) > i:
        abundant_numbers.append(i)

for i in range(len(abundant_numbers)):
    for j in range(len(abundant_numbers)):
        abundant_sum = abundant_numbers[i] + abundant_numbers[j]
        if abundant_sum <= 28123:
            non_abundant_sums[abundant_sum] = 0
print(sum(non_abundant_sums))
