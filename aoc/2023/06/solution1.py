times, distances = [[int(val) for val in line.rstrip().split(":")[1].split()] for line in open("input").readlines()]

prod = 1
for time, distance in zip(times, distances):
    times = 0
    for speed in range(time + 1):
        if speed * (time - speed) > distance:
            times += 1
    prod *= times
print(prod)