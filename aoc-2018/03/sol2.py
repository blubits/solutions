board = [[set() for _ in range(1500)] for i in range(1500)]

with open("input.txt") as input_file:
    claims = input_file.readlines()
    overlapping = {}
    for claim in claims:
        cid, _, idx, size = claim.split()
        j, i = [int(x) for x in idx[:-1].split(",")]
        w, h = [int(x) for x in size.split('x')]
        cid = int(cid[1:])
        for a in range(i, i + h):
            for b in range(j, j + w):
                board[a][b].add(cid)
        overlapping[cid] = False
    for i in range(1500):
        for j in range(1500):
            if len(board[i][j]) > 1:
                for cid in board[i][j]:
                    overlapping[cid] = True
    for cid, b in overlapping.items():
        if not b:
            print(cid)
            break
