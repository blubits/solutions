base = 1
exp = 1
powerful_power_exists = True
count = 0
while powerful_power_exists:
    powerful_power_exists = False
    ans = 0
    base = 1
    while True:
        ans = base ** exp
        if len(str(ans)) == exp:
            print("{0}^{1} = {2}".format(base, exp, ans))
            powerful_power_exists = True
            count += 1
        elif len(str(ans)) > exp:
            break
        elif powerful_power_exists:
            break
        base += 1
    exp += 1
print(count)
