def is_prime(n):
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

for number in range(987654322, 2, -1):
    print(number)
    if is_prime(number):
        s = str(number)
        l = len(s)
        number_sorted = ''.join(sorted(s))
        pandigital_sorted = ''.join([str(x)
                                     for x in sorted(list(range(1, l + 1)))])
        if number_sorted == pandigital_sorted:
            print(number)
            break
