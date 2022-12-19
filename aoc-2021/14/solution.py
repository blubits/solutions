def solve1(lines):
    string = lines[0]
    first, last = string[0], string[-1]
    replacements = lines[2:]
    rules = {}
    string_pairs = {}
    for replacement in replacements:
        fr, to = replacement.split(" -> ")
        fx, fy = fr
        rules[fr] = (f"{fx}{to}", f"{to}{fy}")
    for pair in zip(string, string[1:]):
        pair = ''.join(pair)
        if pair not in string_pairs:
            string_pairs[pair] = 1
        else:
            string_pairs[pair] += 1
    for i in range(10):
        new_string_pairs = {}
        for pair, num in string_pairs.items():
            new_pairs = rules.get(pair, [pair])
            for pair in new_pairs:
                if pair not in new_string_pairs:
                    new_string_pairs[pair] = num
                else:
                    new_string_pairs[pair] += num
        string_pairs = new_string_pairs
    letter_freq = {}
    for pair, freq in string_pairs.items():
        for letter in pair:
            if letter not in letter_freq:
                letter_freq[letter] = freq
            else:
                letter_freq[letter] += freq
    letter_freq[first] += 1
    letter_freq[last] += 1
    letter_freq = list(sorted(letter_freq.items(), key=lambda x: x[1], reverse=True))
    return (letter_freq[0][1] - letter_freq[-1][1]) // 2


def solve2(lines):
    string = lines[0]
    first, last = string[0], string[-1]
    replacements = lines[2:]
    rules = {}
    string_pairs = {}
    for replacement in replacements:
        fr, to = replacement.split(" -> ")
        fx, fy = fr
        rules[fr] = (f"{fx}{to}", f"{to}{fy}")
    for pair in zip(string, string[1:]):
        pair = ''.join(pair)
        if pair not in string_pairs:
            string_pairs[pair] = 1
        else:
            string_pairs[pair] += 1
    for i in range(40):
        new_string_pairs = {}
        for pair, num in string_pairs.items():
            new_pairs = rules.get(pair, [pair])
            for pair in new_pairs:
                if pair not in new_string_pairs:
                    new_string_pairs[pair] = num
                else:
                    new_string_pairs[pair] += num
        string_pairs = new_string_pairs
    letter_freq = {}
    for pair, freq in string_pairs.items():
        for letter in pair:
            if letter not in letter_freq:
                letter_freq[letter] = freq
            else:
                letter_freq[letter] += freq
    letter_freq[first] += 1
    letter_freq[last] += 1
    letter_freq = list(sorted(letter_freq.items(), key=lambda x: x[1], reverse=True))
    return (letter_freq[0][1] - letter_freq[-1][1]) // 2


with open("input") as input_file:
    lines = [line.rstrip() for line in input_file.readlines()]
    print(solve1(lines))
    print(solve2(lines))
