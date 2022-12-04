power_set = set()
for i in range(2, 101):
    for j in range(2, 101):
        power_set.add(i ** j)
print(len(power_set))
