"""
Note: Since there are fewer seeds, it's easier to actually store
each map part as a rule, instead of storing the actual maps in raw
memory.

Store each rule in each map as the following:
    [a, b): delta
where [a, b] are the bounds by which the rules apply and delta
is how the value changes if the value is found within those bounds.
This can be calculated as
    [src, src + length) = dest - src
"""

seeds = []
soil = []
fert = []
water = []
light = []
temp = []
hum = []
loc = []

curr = None
for line in open("input"):
    if line.startswith("seeds: "):
        seeds = [int(x) for x in line[7:].split()]
    elif line.startswith("seed-to-soil"):
        curr = "soil"
    elif line.startswith("soil-to-fertilizer"):
        curr = "fert"
    elif line.startswith("fertilizer-to-water"):
        curr = "water"
    elif line.startswith("water-to-light"):
        curr = "light"
    elif line.startswith("light-to-temperature"):
        curr = "temp"
    elif line.startswith("temperature-to-humidity"):
        curr = "hum"
    elif line.startswith("humidity-to-location"):
        curr = "loc"
    elif line.rstrip():
        dest, src, length = [int(x) for x in line.split(" ")]
        if curr == "soil":
            soil.append(((src, src + length - 1), dest - src))
        elif curr == "fert":
            fert.append(((src, src + length - 1), dest - src))
        elif curr == "water":
            water.append(((src, src + length - 1), dest - src))
        elif curr == "light":
            light.append(((src, src + length - 1), dest - src))
        elif curr == "temp":
            temp.append(((src, src + length - 1), dest - src))
        elif curr == "hum":
            hum.append(((src, src + length - 1), dest - src))
        elif curr == "loc":
            loc.append(((src, src + length - 1), dest - src))

# process seeds
intervals = []
for i in range(len(seeds) // 2):
    intervals.append((seeds[2 * i], seeds[2 * i] + seeds[2 * i + 1] - 1))

# to soil
for rule_list in [soil, fert, water, light, temp, hum, loc]:
    new_intervals = []
    unprocessed_intervals = []
    for rule, delta in rule_list:
        rL, rR = rule
        for L, R in intervals:
            # rule 1: left
            if L <= rL <= R <= rR:
                new_intervals.append((rL + delta, R + delta))
                if (L <= rL - 1): unprocessed_intervals.append((L, rL - 1))
            # rule 2: right
            elif rL <= L <= rR <= R:
                new_intervals.append((L + delta, rR + delta))
                if (rR + 1 <= R): unprocessed_intervals.append((rR + 1, R))
            # rule 3: inner
            elif rL <= L <= R <= rR:
                new_intervals.append((L + delta, R + delta))
            # rule 4: outer
            elif L <= rL <= rR <= R:
                new_intervals.append((rL + delta, rR + delta))
                if (L <= rL - 1): unprocessed_intervals.append((L, rL - 1))
                if (rR + 1 <= R): unprocessed_intervals.append((rR + 1, R))
            # rule 5: else
            else:
                unprocessed_intervals.append((L, R))
        intervals = unprocessed_intervals
        unprocessed_intervals = []
    new_intervals.extend(intervals)
    new_intervals.sort()
    intervals = new_intervals

print(intervals[0][0])


"""
     rL                  rR
      :-------------------: rule
:-------:                         left
                      :-------:   right
            :-------:       inner
:--------------------------------: outer
"""