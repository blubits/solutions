def solve(lines):
    lines = [line.split(" ") for line in lines]
    aim, position, depth = 0, 0, 0
    for command, num in lines:
        if command == "forward":
            depth += aim * int(num)
            position += int(num)
        elif command == "up":
            aim -= int(num)
        else:
            aim += int(num)
    return position * depth


with open("input") as input_file:
    print(solve([line.rstrip() for line in input_file.readlines()]))