weights = []
curr_wt = 0
with open("input") as input_file:
    for line in input_file.readlines():
        if line == "\n":
            weights.append(curr_wt)
            curr_wt = 0
        else:
            curr_wt += int(line.rstrip())
weights.sort(reverse=True)
print(sum(weights[0:3]))