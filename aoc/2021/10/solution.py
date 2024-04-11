def solve(lines):
    all_points = []
    tally = {
        ")": 3,
        "]": 57,
        "}": 1197,
        ">": 25137
    }
    tally_two = {
        "(": 1,
        "[": 2,
        "{": 3,
        "<": 4
   }
    for line in lines:
        points = 0
        stack = []
        for character in line:
            if character in "([{<":
                stack.append(character)
            else:
                last = stack.pop()
                if last == "(" and character != ")":
                    break
                if last == "<" and character != ">":
                    break
                if last == "[" and character != "]":
                    break
                if last == "{" and character != "}":
                    break
        else:
            for char in reversed(stack):
                points *= 5
                points += tally_two[char]
            all_points.append(points)
    all_points.sort()
    return all_points[len(all_points) // 2]

with open("input") as input_file:
    print(solve([line.rstrip() for line in input_file.readlines()]))