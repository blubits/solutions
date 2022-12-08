def reacting(a, b):
    return a.lower() == b.lower() and a != b

def react(polymer):
    s = []
    for p in polymer:
        s.append(p)
        if len(s) >= 2:
            a, b = s[-1], s[-2]
            while reacting(a, b):
                s = s[:-2]
                if len(s) < 2:
                    break
                a, b = s[-1], s[-2]
    return ''.join(s)

with open("input.txt") as input_file:
    polymer = input_file.readline()[:-1]
    for letter in 'abcdefghijklmnopqrstuvwxyz':
        p = polymer.replace(letter, '').replace(letter.upper(), '')
        print(len(react(p)))
