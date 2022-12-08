for a in range(1, 100):
    for b in range(1, 100, 2):
        print(a, b, sum(pow(i, b, a) for i in range(1, a + 1)) % a)
