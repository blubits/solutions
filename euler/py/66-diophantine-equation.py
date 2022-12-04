# TODO get back when

def is_perfect_square(n):
    x = int(n ** 0.5)
    return x * x == n

def find_sol_di(D):
    y = 1
    while True:
        other = 1 + D * y * y
        if is_perfect_square(other):
            return (int(other ** 0.5), y)
        y += 1

max_x = 0
for D in range(2, 1000):
    x = int(D ** 0.5)
    if x * x != D:
        sol = find_sol_di(D)
        print("{0}² - {1} × {2}² = 1".format(sol[0], D, sol[1]))
        if sol[0] > max_x:
            max_x = sol[0]
print(max_x)
