sum = 0
for line in open("input"):
    numbers = [x for x in line if x in "0123456789"]
    val = numbers[0] + numbers[-1]
    sum += int(val)
print(sum)