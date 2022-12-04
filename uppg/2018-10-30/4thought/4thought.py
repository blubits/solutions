from itertools import product

ops = ["+", "-", "*", "//"]

print("{")
for op1, op2, op3 in product(ops, ops, ops):
    s = "4 {0} 4 {1} 4 {2} 4".format(op1, op2, op3)
    print("{{{1}, \"{0}\"}},".format(s.replace("//", "/"), eval(s)))
print("}")
