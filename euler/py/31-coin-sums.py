x = [1, 2, 5, 10, 20, 50, 100, 200]

def count(coins, m, s):
    if s == 0:
        return 1
    if s < 0:
        return 0
    if m < 0:
        return 0
    return count(coins, m - 1, s) + count(coins, m, s - coins[m])

print(count(x, len(x) - 1, 200))
