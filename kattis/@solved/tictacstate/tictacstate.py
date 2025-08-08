T = int(input())
for _ in range(T):
    binary = bin(int(input(), 8))[2:].zfill(19)[::-1]
    pp = list(map(lambda x: x == "1", binary[:9]))
    xo = list(map(lambda x: x == "1", binary[9:18]))
    turn = bool(binary[18])

    winner = "Cat's" if all(pp) else "In progress"

    # horizontal
    if pp[0] and pp[1] and pp[2]:
        if xo[0] == xo[1] == xo[2]:
            winner = "X" if xo[0] else "O"
    if pp[3] and pp[4] and pp[5]:
        if xo[3] == xo[4] == xo[5]:
            winner = "X" if xo[3] else "O"
    if pp[6] and pp[7] and pp[8]:
        if xo[6] == xo[7] == xo[8]:
            winner = "X" if xo[6] else "O"

    # vertical
    if pp[0] and pp[3] and pp[6]:
        if xo[0] == xo[3] == xo[6]:
            winner = "X" if xo[0] else "O"
    if pp[1] and pp[4] and pp[7]:
        if xo[1] == xo[4] == xo[7]:
            winner = "X" if xo[1] else "O"
    if pp[2] and pp[5] and pp[8]:
        if xo[2] == xo[5] == xo[8]:
            winner = "X" if xo[2] else "O"

    # diagonal
    if pp[0] and pp[4] and pp[8]:
        if xo[0] == xo[4] == xo[8]:
            winner = "X" if xo[0] else "O"
    if pp[2] and pp[4] and pp[6]:
        if xo[2] == xo[4] == xo[6]:
            winner = "X" if xo[2] else "O"

    if winner == "X":
        winner = "X wins"
    elif winner == "O":
        winner = "O wins"

    print(winner)



