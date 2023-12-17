s = 0
for line in open("input"):
    card_id, ticket = line.split(": ")
    winning, filed = ticket.split(" | ")
    card_id = int(ticket.split(" ")[-1][:-1])
    winning = set(int(x.strip()) for x in winning.split())
    filed = set(int(x.strip()) for x in filed.split())
    s += (1 << (len(winning & filed) - 1)) if len(winning & filed) != 0 else 0
print(s)