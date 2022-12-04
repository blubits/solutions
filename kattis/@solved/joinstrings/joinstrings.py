from random import choice, randrange

N = 5
l = [[i] for i in range(N)]
nums = list(range(N))
strings = []

print(N)
for i in range(N):
    s = ''.join(chr(ord('a') + randrange(0, 26)) for _ in range(1000))
    strings.append(s)
    print(s)
for i in range(N - 1):
    while True:
        a, b = choice(nums), choice(nums)
        if a == b or not l[a] or not l[b]:
            continue
        l[a].extend(l[b])
        l[b] = []
        nums.remove(b)
        print(a+1, b+1)
        break
    if i == N - 2:
        for ll in l:
            if ll:
                with open("joinstrings.ans", 'w') as f:
                    f.write(''.join(strings[i] for i in ll) + '\n')
                break

