def solve1(lines):
    folds = [line.replace("fold along ", "").split("=") for line in lines if line.startswith("fold along")]
    lines = [line for line in lines if not (line.startswith("fold along") or line == "")]
    coordinates = {(int(x), int(y)) for x, y in [line.split(",") for line in lines]}
    xl = 0
    xh = max({point[0] for point in coordinates})
    yl = 0
    yh = max({point[1] for point in coordinates})
    folds = [folds[0]]
    for direction, line in folds:
        new_coordinates = set()
        line = int(line)
        for x, y in coordinates:
            if direction == "x":
                if x > line:
                    new_coordinates.add((2 * line - x, y))
                else:
                    new_coordinates.add((x, y))
            else:
                if y > line:
                    new_coordinates.add((x, 2 * line - y))
                else:
                    new_coordinates.add((x, y))
        coordinates = new_coordinates
    return len(coordinates)

def solve2(lines):
    folds = [line.replace("fold along ", "").split("=") for line in lines if line.startswith("fold along")]
    lines = [line for line in lines if not (line.startswith("fold along") or line == "")]
    coordinates = {(int(x), int(y)) for x, y in [line.split(",") for line in lines]}
    xl = 0
    xh = max({point[0] for point in coordinates})
    yl = 0
    yh = max({point[1] for point in coordinates})
    for direction, line in folds:
        new_coordinates = set()
        line = int(line)
        for x, y in coordinates:
            if direction == "x":
                if x > line:
                    new_coordinates.add((2 * line - x, y))
                else:
                    new_coordinates.add((x, y))
            else:
                if y > line:
                    new_coordinates.add((x, 2 * line - y))
                else:
                    new_coordinates.add((x, y))
        coordinates = new_coordinates
    xl = 0
    xh = max({point[0] for point in coordinates})
    yl = 0
    yh = max({point[1] for point in coordinates})
    ans = ""
    for i in range(yh + 1):
        for j in range(xh + 1):
            if (j, i) in coordinates:
                ans += "██"
            else:
                ans += "░░"
        ans += "\n"
    return ans


with open("input") as input_file:
    lines = [line.rstrip() for line in input_file.readlines()]
    print(solve1(lines))
    print(solve2(lines))
