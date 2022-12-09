from itertools import permutations

mapping = {
    "ABCEFG": 0,
    "CF": 1,
    "ACDEG": 2,
    "ACDFG": 3,
    "BCDF": 4,
    "ABDFG": 5,
    "ABDEFG": 6,
    "ACF": 7,
    "ABCDEFG": 8,
    "ABCDFG": 9
}

def decode(signal):
    orig = "abcdefg"
    for perm in permutations("ABCDEFG"):
        result = {}
        translation = str.maketrans(orig, ''.join(perm))
        for config in signal:
            config_translated = config.translate(
                translation
            )
            config_decoded = mapping.get(''.join(sorted(config_translated)), -1)
            if config_decoded == -1:
                continue
            else:
                result[config] = config_decoded
        if len(result) == 10:
            return result

def solve(lines):
    # process
    lines = [line.split("| ") for line in lines]
    signals = [[''.join(sorted(signal)) for signal in line[0].split()] for line in lines]
    numbers = [[''.join(sorted(number)) for number in line[1].split()] for line in lines]
    total = 0
    for i in range(len(lines)):
        signal = signals[i]
        number = numbers[i]
        decoded = decode(signal)
        number = int(''.join([str(decoded[digit]) for digit in number]))
        total += number
    return total

with open("input") as input_file:
    print(solve([line.rstrip() for line in input_file.readlines()]))