from math import ceil

def f(x):
    return 10 * (x ** 0.5)

x = 80
for i in range(10):
    print(i, x)
    x = f(x)
