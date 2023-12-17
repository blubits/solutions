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
            soil.append(((src, src + length), dest - src))
        elif curr == "fert":
            fert.append(((src, src + length), dest - src))
        elif curr == "water":
            water.append(((src, src + length), dest - src))
        elif curr == "light":
            light.append(((src, src + length), dest - src))
        elif curr == "temp":
            temp.append(((src, src + length), dest - src))
        elif curr == "hum":
            hum.append(((src, src + length), dest - src))
        elif curr == "loc":
            loc.append(((src, src + length), dest - src))
    
def apply(L, val):
    # Change val depending on rules in L.
    for rule, delta in L:
        a, b = rule
        if a <= val < b:
            return val + delta
    return val
    
print(min([
    apply(loc, apply(hum, apply(temp, apply(light, apply(water, apply(fert, apply(soil, seed))))))) for seed in seeds
]))