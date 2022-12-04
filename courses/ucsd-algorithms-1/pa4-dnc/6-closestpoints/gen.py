from random import randint
from math import hypot

N = 100000
l = []

with open("gen.in", "w") as infile:
    infile.write("{0}\n".format(N))
    for _ in range(N):
        l.append((randint(-10000, 10000), randint(-10000, 10000)))
        infile.write("{0} {1}\n".format(*l[-1]))

# with open("gen.ans", "w") as ansfile:
#     md = float("inf")
#     for i in range(N):
#         for j in range(i + 1, N):
#             md = min(md, hypot(l[j][0] - l[i][0], l[j][1] - l[i][1]))
#     ansfile.write("{0:.9f}\n".format(md))
