from itertools import permutations, combinations_with_replacement

# def digit_iterator():
#     for a in range(10):
#         for b in range(10):
#             for c in range(10):
#                 for d in range(10):
#                     for e in range(10):
#                         for f in range(10):
#                             for g in range(10):
#                                 for h in range(10):
#                                     for i in range(10):
#                                         for j in range(10):
#                                             yield [a, b, c, d, e, f, g, h, i, j]

# for perm in digit_iterator():
#     num = int('1{}2{}3{}4{}5{}6{}7{}8{}9{}0'.format(*perm))
#     sqrt = int(num ** 0.5)
#     if sqrt * sqrt == num:
#         print(num, int(sqrt * sqrt))
#         break

for i in range(1010101010, 1389026623, 10):
    square = i * i
    every_other = ''.join([str(square)[i] for i in range(0, 19, 2)])
    #print(i, every_other)
    if every_other == '1234567890':
        print(i, square)
        break
