from functools import reduce
from operator import mul

s = ""

for i in range(1, 1000000):
    s += str(i)
    if len(s) > 1000000:
        print(i, "here")
        break

print([int(s[(10 ** i) - 1]) for i in range(7)])
print(reduce(mul, [int(s[(10 ** i) - 1]) for i in range(7)]))
