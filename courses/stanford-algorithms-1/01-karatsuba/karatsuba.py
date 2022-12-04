def karatsuba(a: str, b: str) -> int:
    """
    Defines the karatsuba algorithm.
    """
    if len(a) == 1 and len(b) == 1:
        print("{0} * {1} = {2}".format(a, b, int(a) * int(b)))
        return int(a) * int(b)
    if len(a) > len(b):
        b = ("0" * (len(a) - len(b))) + b
    if len(a) < len(b):
        a = ("0" * (len(b) - len(a))) + a
    sz = len(a) // 2
    a1, a2 = a[:sz], a[sz:]
    a1, a2 = a[:sz], a[sz:]
    b1, b2 = b[:sz], b[sz:]
    p = sz + (1 if len(a) % 2 == 1 else 0)
    if not a1:
        a1 = "0"
    if not a2:
        a2 = "0"
    if not b1:
        b1 = "0"
    if not b2:
        b2 = "0"
    q1 = karatsuba(a1, b1)
    q2 = karatsuba(a2, b2)
    q3 = karatsuba(str(int(a1) + int(a2)), str(int(b1) + int(b2))) - q1 - q2
    pow_10 = 10 ** p
    ans = (q1 * pow_10 * pow_10) + (q3 * pow_10) + q2
    print("{7}|{8} * {9}|{10} = ({3}/{4}/{5}) {2} ({6})".format(a, b, ans, q1,
                                                                q3, q2, "equal" if ans == int(a) * int(b) else "not equal", a1, a2, b1, b2))
    return (q1 * pow_10 * pow_10) + (q3 * pow_10) + q2


a = "3141592653589793238462643383279502884197169399375105820974944592"
b = "2718281828459045235360287471352662497757247093699959574966967627"
print(karatsuba(a, b))
print(int(a) * int(b))
