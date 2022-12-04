ans = 0
MOD = 10000000000

for i in range(1, 1001):
    ans += (i ** i) % MOD
    ans %= MOD
print(ans)
