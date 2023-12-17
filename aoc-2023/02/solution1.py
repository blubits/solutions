def process(L):
    res = {}
    for item in L:
        num, color = item.split(" ")
        res[color] = int(num)
    return res

ans = 0
for line in open("input"):
    game, items = line.split(": ")
    game = int(game.split(" ")[-1])
    items = [process(item.rstrip().split(", ")) for item in items.split("; ")]
    valid = True
    for L in items:
        if not (L.get("red", 0) <= 12 and L.get("green", 0) <= 13 and L.get("blue", 0) <= 14):
            valid = False
            break
    if valid:
        ans += game
print(ans)