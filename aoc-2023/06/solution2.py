time, distance = [int("".join(line.rstrip().split(":")[1].split())) for line in open("input").readlines()]
print(time, distance)

times = 0
for speed in range(time + 1):
    if speed * (time - speed) > distance:
        times += 1
print(times)