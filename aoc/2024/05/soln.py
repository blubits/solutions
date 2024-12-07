import re
from functools import cmp_to_key

FILENAME = "input"

def parse(filename):
    rules = set()
    jobs = []
    with open(filename) as f:
        for line in f:
            line = line.strip()
            if not line: continue
            if re.match(r'^\d+\|\d+$',line):
                num1, num2 =line.split('|')
                rules.add((int(num1), int(num2)))
            else:
                jobs.append(list(map(int,line.split(','))))
    return (rules, jobs)

def sort(job, rules):
    swap = True
    while swap:
        swap = False
        for i in range(len(job) - 1):
            pair = (job[i + 1], job[i])
            if pair in rules:
                job[i + 1], job[i] = job[i], job[i + 1]
                swap = True

def solve(data):
    rules, jobs = data
    ans = 0
    for job in jobs:
        valid_job = True
        for i in range(len(job)):
            for j in range(i + 1, len(job)):
                pair = (job[j], job[i])
                if pair in rules:
                    valid_job = False
                    break
            if not valid_job:
                break
        if valid_job:
            ans += job[len(job)//2]
    return ans

def solve2(data):
    rules, jobs = data
    ans = 0
    for job in jobs:
        valid_job = True
        for i in range(len(job)):
            for j in range(i + 1, len(job)):
                pair = (job[j], job[i])
                if pair in rules:
                    valid_job = False
                    break
            if not valid_job:
                break
        if not valid_job:
            sort(job, rules)
            ans += job[len(job)//2]
    return ans

data = parse(FILENAME)
print(solve(data))
print(solve2(data))
