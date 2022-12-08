def is_double_base_palindrome(n):
    d = str(n)
    b = "{0:b}".format(n)
    return d == d[::-1] and b == b[::-1]

ans = 0
for i in range(1, 1000001):
    if is_double_base_palindrome(i):
        print(i, bin(i))
        ans += i
print(ans)
