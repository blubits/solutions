board = [[0] * 1500 for i in range(1500)]

with open("input.txt") as input_file:
    claims = input_file.readlines()
    for claim in claims:
        _, _, idx, size = claim.split()
        j, i = [int(x) for x in idx[:-1].split(",")]
        w, h = [int(x) for x in size.split('x')]
        for a in range(i, i + h):
            for b in range(j, j + w):
                board[a][b] += 1
    k = 0
    for i in range(1500):
        for j in range(1500):
            if board[i][j] > 1:
                k += 1
    print(k)
