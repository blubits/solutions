with open("13-large-sum.in") as infile:
    x = [int(x) for x in infile.readlines()]

print(str(sum(x))[0:10])
