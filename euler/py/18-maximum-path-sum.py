def max_length_path(triangle, n):
    MAX_COST = [[0] * (n + 1) for i in range(n + 1)]
    MAX_COST[0][0] = triangle[0][0]
    for i in range(1, n + 1):
        for j in range(i + 1):
            print(i, j)
            if j == 0:
                MAX_COST[i][j] = triangle[i][j] + MAX_COST[i - 1][j]
            if j == i:
                MAX_COST[i][j] = triangle[i][j] + MAX_COST[i - 1][j - 1]
            else:
                MAX_COST[i][j] = triangle[i][j] + max(
                    MAX_COST[i - 1][j], MAX_COST[i - 1][j - 1]
                )
    print(MAX_COST)
    return max(MAX_COST[n])

with open("18-maximum-path-sum.in") as infile:
    triangle = [[int(x) for x in line.split()]
                for line in infile.readlines()]
    print(max_length_path(triangle, 14))
