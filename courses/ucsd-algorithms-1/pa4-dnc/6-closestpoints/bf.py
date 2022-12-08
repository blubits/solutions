from math import hypot

N = int(input())
l = [tuple(int(x) for x in input().split()) for _ in range(N)]

for i in range(N):
    for j in range(i + 1, N):
        print(l[i], l[j], hypot(l[j][0] - l[i][0], l[j][1] - l[i][1]))
