for i in range(1, 10000000):
    s = ''.join(sorted(str(i)))
    for k in range(2, 6):
        ks = ''.join(sorted(str(i * k)))
        if s != ks:
            break
    else:
        print(i)
        break
