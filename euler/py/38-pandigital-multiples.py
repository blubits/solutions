for i in range(1, 50001):
    s = ""
    for j in range(1, 10):
        s += str(i * j)
        if len(s) > 9:
            break
        elif len(s) == 9:
            if ''.join(sorted(s)) == "123456789":
                print(s, ''.join(sorted(s)), i)
            break
