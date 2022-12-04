def coprime_generator(n, a=1, b=1):
    yield (a, b)
    k = 1
    while a * k + b <= n:
        for i in coprime_generator(n, a * k + b, a):
            yield i
        k += 1

count = 0
for D, N in coprime_generator(1000000):
    if N / D != 1:
        count += 1
