def dig_sum(n):
    return sum([int(x) for x in str(n)])

print(max([dig_sum(i ** j) for i in range(2, 100) for j in range(2, 100)]))
