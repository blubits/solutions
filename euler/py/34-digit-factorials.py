factorials = [1, 1]
for i in range(2, 11):
    factorials.append(i * factorials[i - 1])

CACHE = {}
def sum_factorials(n):
    if len(n) == 1:
        return factorials[int(n)]
    if n in CACHE:
        return CACHE[n]
    return factorials[int(str(n)[0])] + sum_factorials(n[1:])

# print(sum_factorials(str(4000)))

result = 0
for i in range(10, 1000000):
    if i == sum_factorials(str(i)):
        print(i)
        result += i
print(result)
