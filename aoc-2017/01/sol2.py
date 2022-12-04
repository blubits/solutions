with open("input.txt") as input_file:
    s = input_file.readlines()[0][:-1]
    chk = 0
    for i in range(len(s)):
        j = (i + (len(s) // 2)) % len(s)
        if s[i] == s[j]:
            chk += int(s[i])
    print(chk)
