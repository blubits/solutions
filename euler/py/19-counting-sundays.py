starting_day = 1
offsets = [3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3]
days = ["Sunday", "Monday", "Tuesday",
        "Wednesday", "Thursday", "Friday", "Saturday"]

def is_leap_year(n):
    if n % 100 == 0:
        return n % 4 == 0 and n % 400 == 0
    else:
        return n % 4 == 0

sundays = 0
for i in range(1, 101):
    for j in range(12):
        if i == 1 and j == 0:
            continue
        elif j == 2 and is_leap_year(1900 + i):
            starting_day = (starting_day + 1) % 7
        else:
            starting_day = (starting_day + offsets[j]) % 7
        if starting_day == 0:
            sundays += 1

# Dec 99 -> Jan 00
starting_day = (starting_day + 3) % 7
print(sundays + (1 if starting_day == 0 else 0))
