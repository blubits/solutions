FILENAME = "input"

def parse(filename):
    with open(filename) as f:
        board = [list(map(int, line.split())) for line in f.readlines()]
        return board

def solve(data):
    safety_reports = [
        list(map(lambda x: x[0] - x[1], zip(line[1:], line[:-1]))) for line in data
    ]
    safety_report_inc = [
        all(map(lambda x: x > 0, line)) or all(map(lambda x: x < 0, line)) for line in safety_reports
    ]
    safety_report_val = [
        all(map(lambda x: 1 <= abs(x) <= 3, line)) for line in safety_reports
    ]
    return [a and b for a, b in zip(safety_report_inc, safety_report_val)].count(True)

def solve2(data):
    problem_dampener = [
        [line.copy()[:i] + line.copy()[i + 1:] for i in range(len(line))] for line in data
    ]
    safety_reports = [
        [list(map(lambda x: x[0] - x[1], zip(line[1:], line[:-1]))) for line in level] for level in problem_dampener
    ]
    safety_report_inc = [
        [all(map(lambda x: x > 0, line)) or all(map(lambda x: x < 0, line)) for line in level] for level in safety_reports
    ]
    safety_report_val = [
        [all(map(lambda x: 1 <= abs(x) <= 3, line)) for line in level] for level in safety_reports
    ]
    safety_report_summary = [
        [a and b for a, b in zip(x, y)] for x, y in zip(safety_report_inc, safety_report_val)
    ]
    safety_report_summary = [any(line) for line in safety_report_summary]
    return safety_report_summary.count(True)

data = parse(FILENAME)
print(solve(data))
print(solve2(data))