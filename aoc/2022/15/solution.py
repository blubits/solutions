import re

def distance(pt1, pt2):
    return abs(pt1[0] - pt2[0]) + abs(pt1[1] - pt2[1])

def process(lines):
    regex = r"Sensor at x=(-?\d+), y=(-?\d+): closest beacon is at x=(-?\d+), y=(-?\d+)"
    processed = []
    for line in lines:
        match = re.match(regex, line)
        data = {
            "sensor": (int(match[1]), int(match[2])),
            "beacon": (int(match[3]), int(match[4])),
        }
        data["distance"] = distance(data["sensor"], data["beacon"])
        data["is_within"] = lambda pt: distance(data["sensor"], pt) <= data["distance"]
        processed.append(data)
    return processed


def solve1(lines):
    sensors = process(lines)
    yline = 2000000
    intervals = []
    for sensor in sensors:
        # get all points [a, 2000000] to [b, 20000000] that are at most `d` away from the sensor
        # d = abs(sx - x) + abs(sy - 20000000)
        sx = sensor["sensor"][0]
        sy = sensor["sensor"][1]
        d = sensor["distance"]
        left = sx + abs(sy - yline) - d
        right = sx - abs(sy - yline) + d
        if left <= right:
            intervals.append((left, right))
    intervals_new = []
    for begin, end in sorted(intervals):
        if intervals_new and intervals_new[-1][1] >= begin - 1:
            intervals_new[-1][1] = max(intervals_new[-1][1], end)
        else:
            intervals_new.append([begin, end])
    return intervals_new[0][1] - intervals_new[0][0]

def solve2(lines):
    sensors = process(lines)
    for yline in range(4000000):
        intervals = []
        for sensor in sensors:
            # get all points [a, 2000000] to [b, 20000000] that are at most `d` away from the sensor
            # d = abs(sx - x) + abs(sy - 20000000)
            sx = sensor["sensor"][0]
            sy = sensor["sensor"][1]
            d = sensor["distance"]
            left = sx + abs(sy - yline) - d
            right = sx - abs(sy - yline) + d
            if left <= right:
                intervals.append((left, right))
        intervals_new = []
        for begin, end in sorted(intervals):
            if intervals_new and intervals_new[-1][1] >= begin - 1:
                intervals_new[-1][1] = max(intervals_new[-1][1], end)
            else:
                intervals_new.append([begin, end])
        if len(intervals_new) != 1:
            xdist = (intervals_new[0][1] + intervals_new[1][0]) // 2
            return yline + xdist * 4000000



with open("input") as input_file:
    lines = [line.rstrip() for line in input_file.readlines()]
    print(solve1(lines))
    print(solve2(lines))
