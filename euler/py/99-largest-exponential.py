from math import log

with open("p099_base_exp.txt") as infile:
    numbers = [[int(number) for number in line.strip('\n').split(',')]
               for line in infile.readlines()]
    max_number = 0
    max_line_no = 0
    curr_line_no = 1
    for base, exp in numbers:
        number = exp * log(base)
        if number > max_number:
            max_line_no = curr_line_no
            max_number = number
        curr_line_no += 1
    print("{0}^{1}".format(*numbers[max_line_no - 1]), max_line_no)
