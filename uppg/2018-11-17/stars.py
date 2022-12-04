from random import randint

for i in range(50):
    k = randint(1, 10)
    l = randint(1, 10)
    print(k, l)
    for i in range(k):
        for j in range(l):
            if randint(0, 1):
                print("-", end='')
            else:
                print("#", end='')
        print()
