translator = {
    "zero": "zero0zero",
    "one": "one1one",
    "two": "two2two",
    "three": "three3three",
    "four": "four4four",
    "five": "five5five",
    "six": "six6six",
    "seven": "seven7seven",
    "eight": "eight8eight",
    "nine": "nine9nine",
}
sum = 0
for line in open("input"):
    for word, numeral in translator.items():
        line = line.replace(word, numeral)
    numbers = [x for x in line if x in "0123456789"]
    val = numbers[0] + numbers[-1]
    sum += int(val)
print(sum)
