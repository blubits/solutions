def wordify(n):
    # works for N up to 1000
    # a recursive version could work for N > 1000
    if n == 1000:
        return "one thousand"
    ones = ["zero", "one", "two", "three", "four",
            "five", "six", "seven", "eight", "nine"]
    teens = ["ten", "eleven", "twelve", "thirteen", "fourteen",
             "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
    tens = ["", "", "twenty", "thirty", "forty",
            "fifty", "sixty", "seventy", "eighty", "ninety"]
    digits = [int(x) for x in str(n)]
    place = len(digits)
    prev_digit = 0
    ans = ""
    IS_TEEN = False
    for digit in digits:
        if place == 3:
            ans += ones[digit] + " hundred"
        elif place == 2:
            if digit == 1:
                IS_TEEN = True
                if prev_digit != 0:
                    ans += " and "
            elif prev_digit != 0 and digit != 0:
                ans += " and " + tens[digit]
            else:
                ans += tens[digit]
        elif place == 1:
            if IS_TEEN:
                ans += teens[digit]
            elif digit == 0 and n != 0:
                continue
            elif digit > 0 and prev_digit != 0:
                ans += "-" + ones[digit]
            elif prev_digit == 0 and n > 10:
                ans += " and " + ones[digit]
            else:
                ans += ones[digit]
        place -= 1
        prev_digit = digit
    return ans

def count_letters(x):
    return sum([1 for letter in wordify(x) if letter not in (' ', '-')])

print(sum([count_letters(n) for n in range(1, 1001)]))

# for i in range(1, 1001):
#     print(wordify(i), count_letters(i))
