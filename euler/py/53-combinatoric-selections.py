def Ctable(n):
    TABLE = [[0] * (i + 1) for i in range(n + 1)]
    TABLE[0][0] = 1
    for i in range(1, n + 1):
        TABLE[i][0] = 1
        TABLE[i][i] = 1
    for i in range(2, n + 1):
        for j in range(1, i):
            TABLE[i][j] = TABLE[i - 1][j] + TABLE[i - 1][j - 1]
    return TABLE

x = Ctable(100)
count = 0
for row in x:
    for item in row:
        if item > 1000000:
            count += 1
print(count)
