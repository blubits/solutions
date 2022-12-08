ans = 0
bunch = []
with open("input") as input_file:
    for line in input_file.readlines():
        bunch.append(line.rstrip())
        if len(bunch) == 3:
            first, second, third = bunch
            print(set(first).intersection(set(second), set(third)))
            [intersection] = set(first).intersection(set(second), set(third))
            ans += (ord(intersection) % 32) + (26 if intersection.isupper() else 0)
            bunch = []
print(ans)
