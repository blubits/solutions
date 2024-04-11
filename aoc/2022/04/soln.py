ans = 0

with open("input") as input_file:
    for line in input_file.readlines():
        range1, range2 = line.rstrip().split(",")
        left1, right1 = [int(i) for i in range1.split("-")]
        left2, right2 = [int(i) for i in range2.split("-")]
        if not (right1 < left2) and not (right2 < left1):
            ans += 1
print(ans)
