grid = ["OBIDAIBKR", "RKAULHISP", "SADIYANNO", "HEISAWHIA",
        "IRAKIBULS", "MFBINTRNO", "UTOYZIFAH", "LEBSYNUNE", "EMOTIONAL"]
names = ["RAKIBUL",
         "ANINDYA",
         "MOSHIUR",
         "SHIPLU",
         "KABIR",
         "SUNNY",
         "OBAIDA",
         "WASI"]

for name in names:
    print("Finding", name)
    lname = len(name)
    # horizontal
    for i in range(9):
        for j in range(9 - lname + 1):
            string = grid[i][j:j + lname]
            if sorted(string) == sorted(name):
                print("Found", name, "as", string)
    # vertical
    for i in range(9 - lname + 1):
        for j in range(9):
            string = ''.join([grid[i + k][j] for k in range(lname)])
            if sorted(string) == sorted(name):
                print("Found", name, "as", string)
