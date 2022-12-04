with open("input.txt") as input_file:
    nums = [[int(i) for i in row[:-1].split()]
            for row in input_file.readlines()]
    s = 0
    for row in nums:
        k = False
        for i in range(len(row)):
            for j in range(i + 1, len(row)):
                a = max(row[i], row[j])
                b = min(row[i], row[j])
                if a % b == 0:
                    print(a, b)
                    s += a // b
                    k = True
                    break
            if k:
                break
    print(s)
