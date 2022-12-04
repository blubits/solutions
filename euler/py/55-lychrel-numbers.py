def is_lychrel(n):
    s = n
    for _ in range(50):
        s += int(str(s)[::-1])
        if str(s) == str(s)[::-1]:
            return False
    return True

count = 0
for i in range(10000):
    if is_lychrel(i):
        print(i)
        count += 1
print(count)
