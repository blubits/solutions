def collatz_length(x):
    ans = 1
    while x != 1:
        if x % 2 == 0:
            x //= 2
        else:
            x = (3 * x) + 1
        ans += 1
    return ans

max_length = 0
max_num = 0
for i in range(1, 1000001):
    length = collatz_length(i)
    if length > max_length:
        print(max_num, "length", max_length)
        max_length = length
        max_num = i
print(max_num, "length", max_length)
