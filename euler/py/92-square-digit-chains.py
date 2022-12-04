def square_sum(n):
    return sum([int(x) ** 2 for x in str(n)])

NEXT = [None] * 10000001

def square_chain_ends_at_89(n):
    s = n
    while True:
        print(s)
        if NEXT[s] is not None:
            NEXT[n] = NEXT[s]
            break
        if s == 89:
            NEXT[n] = True
            break
        if s == 1:
            NEXT[n] = False
            break
        s = square_sum(s)
    return NEXT[n]

count = 0
for i in range(1, 10000001):
    if i == 1000000:
        print(NEXT[44])
    if square_chain_ends_at_89(i):
        count += 1
print(count)
