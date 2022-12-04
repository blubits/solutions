def number_spiral_diagonal_sum(n):
    iterations = n // 2
    diagonal_sum = 1
    curr_number = 1
    change = 2
    for _ in range(iterations):
        for _ in range(4):
            curr_number += change
            diagonal_sum += curr_number
        change += 2
    return diagonal_sum

print(number_spiral_diagonal_sum(5))
print(number_spiral_diagonal_sum(1001))
