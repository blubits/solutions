with open("input.txt") as input_file:
    strs = [s[:-1] for s in input_file.readlines()]
    common = []
    three_cnt = 0
    two_cnt = 0
    for i in range(len(strs)):
        si = strs[i]
        for j in range(1, len(strs)):
            sj = strs[j]
            diff = [1 if si[k] != sj[k] else 0 for k in range(len(sj))]
            if sum(diff) == 1:
                a = diff.index(1)
                print(si)
                print(sj)
                print(si[:a] + si[a + 1:])
                break
