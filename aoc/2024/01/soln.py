with open("input") as input_file:
    numbers = [tuple(map(int, line.split())) for line in input_file.readlines()]
    nums1, nums2 = [x[0] for x in numbers], [x[1] for x in numbers]
    nums1.sort()
    nums2.sort()
    print(sum(map(lambda x: x * nums2.count(x), nums1)))