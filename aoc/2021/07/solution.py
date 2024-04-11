def f(x, crabs):
    def g(x, crab):
        diff = abs(x - crab)
        return (diff * (diff + 1)) // 2
    return sum(
        [g(x, crab) for crab in crabs]
    )

def solve(lines):
    crabs = [int(x) for x in lines[0].split(",")]
    crabs.sort()
    domain = list(set(crabs))
    print(f(464, crabs))
    return
    # ternary search
    left = min(domain)
    right = max(domain)
    while abs(left - right) >= 0.01:
        print(left, right)
        left_third = (2 * left + right) // 3
        right_third = (left + 2 * right) // 3
        if f(left_third, crabs) > f(right_third, crabs):
            left = left_third
        else:
            right = right_third

with open("sampleinput") as input_file:
    print(solve([line.rstrip() for line in input_file.readlines()]))