def solve1(lines):
    folds = [line.replace("fold along ", "").split("=") for line in lines if line.startswith("fold along")]
    lines = [line for line in lines if not (line.startswith("fold along") or line == "")]
    coordinates = {(int(x), int(y)) for x, y in [line.split(",") for line in lines]}
    xl = 0
    xh = max({point[0] for point in coordinates})
    yl = 0
    yh = max({point[1] for point in coordinates})
    print(xl, xh, yl, yh)
    folds = [folds[0]]
    for direction, line in folds:
        new_coordinates = {}
        line = int(line)
        for x, y in coordinates:
            if direction == "x":
                if x > line:
                    new_x = x - line
                    new_coordinates.append(())
            else:
        print(direction, line)

def solve2(lines):
    pass


with open("input") as input_file:
    lines = [line.rstrip() for line in input_file.readlines()]
    print(solve1(lines))
    print(solve2(lines))
