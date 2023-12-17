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
    r, g, b = 0, 0, 0
    for L in items:
        r = max(r, L.get("red", 0))
        g = max(g, L.get("green", 0))
        b = max(b, L.get("blue", 0))
    ans += r * g * b
print(ans)