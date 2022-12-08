def value(string):
    return sum([ord(letter) - ord('a') + 1 for letter in string.lower()])

with open("p022_names.txt") as infile:
    names = [name.strip('"') for name in infile.readline().split(",")]
    names.sort()
    print(sum([value(name) * (idx + 1) for idx, name in enumerate(names)]))
