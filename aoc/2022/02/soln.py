points = {
    "AX": 0 + 3,
    "AY": 3 + 1,
    "AZ": 6 + 2,
    "BX": 0 + 1,
    "BY": 3 + 2,
    "BZ": 6 + 3,
    "CX": 0 + 2,
    "CY": 3 + 3,
    "CZ": 6 + 1,
}

with open("input") as input_file:
    moves = [line.rstrip().replace(" ", "") for line in input_file.readlines()]
    print(sum(points[move] for move in moves))
