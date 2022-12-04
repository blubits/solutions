with open("11-largest-product-in-a-grid.in") as infile:
    x = [[int(i) for i in line.split()] for line in infile.readlines()]

dxs = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]

maxprod = 0
for i in range(20):
    for j in range(20):
        prods = []
        for dx in dxs:
            di = i
            dj = j
            prod = x[i][j]
            for k in range(3):
                di += dx[0]
                dj += dx[1]
                print(i, j, di, dj, di < 0 or di > 20 or dj < 0 or dj > 20)
                if di < 0 or di > 19 or dj < 0 or dj > 19:
                    break
                else:
                    prod *= x[di][dj]
            else:
                prods.append(prod)
        maxprod = max(maxprod, max(prods))

print(maxprod)
