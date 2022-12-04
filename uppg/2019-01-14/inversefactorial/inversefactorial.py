from math import factorial, log10, ceil

i = 1
f = 1
nd = 0
print("f\t\test\t\tact")
while len(str(f)) <= 1e6:
    f *= i
    nd += log10(i)
    i += 1
    print("{0}\t\t{1}\t\t{2}".format(
        i - 1, ceil(nd), len(str(f))))

# for i in range(1, 21):
#     print('if (num == "{0}") cout << {1};'.format(factorial(i), i))
