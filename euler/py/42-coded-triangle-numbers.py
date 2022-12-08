def value(string):
    return sum([ord(letter) - ord('a') + 1 for letter in string.lower()])

triangle_numbers = list(range(1000))
for i in range(2, 1000):
    triangle_numbers[i] += triangle_numbers[i - 1]

with open("p042_words.txt") as infile:
    words = [word.strip('"') for word in infile.readline().split(',')]
    count = 0
    for word in words:
        if value(word) in triangle_numbers:
            print(word, value(word))
            count += 1
    print(count)
