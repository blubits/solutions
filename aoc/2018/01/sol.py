with open("input") as input_file:
    nums = [int(num[:-1]) for num in input_file.readlines()]
    freq = {}
    s = 0
    b = True
    while b:
        for num in nums:
            s += num
            if s not in freq:
                freq[s] = 1
            else:
                print(s)
                b = False
                break
