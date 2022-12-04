x = list(range(1, 100))

def count(coins, m, s):
    # ways we can sum coins[0..m] to get s
    TABLE = [[0] * m for i in range(s + 1)]
    for j in range(m):
        # 1 way to make s out of nothing
        TABLE[0][j] = 1
    for i in range(1, s + 1):     # for each sum...
        for j in range(m):      # for each subarray...
            # we either exclude the last item coins[j]
            if j >= 1:
                # there is still something to exclude
                exclude = TABLE[i][j - 1]
            else:
                exclude = 0
            # or include coins[j]
            if i - coins[j] >= 0:
                # we can still include the coin without going over
                include = TABLE[i - coins[j]][j]
            else:
                include = 0
            TABLE[i][j] = exclude + include
    return TABLE[s][m - 1]

print(count(x, len(x), 100))
