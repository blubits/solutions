k = set()
for i in range(2000):
    for j in range(2000):
        s = str(i) + str(j) + str(i * j)
        if len(s) == 9 and ''.join(sorted(s)) == "123456789":
            print(i, j, i * j)
            k.add(i * j)
print(sum(k))
