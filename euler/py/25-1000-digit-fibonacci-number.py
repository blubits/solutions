fib = [0, 1, 1]
i = 3
while True:
    new = fib[i - 1] + fib[i - 2]
    if len(str(new)) >= 1000:
        print(i)
        break
    fib.append(new)
    i += 1
