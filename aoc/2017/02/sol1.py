with open("input.txt") as input_file:
    nums = [[int(i) for i in row[:-1].split()]
            for row in input_file.readlines()]
    print(sum([max(row) - min(row) for row in nums]))
