l = []
for line in open("input"):
    card_id, ticket = line.split(": ")
    winning, filed = ticket.split(" | ")
    card_id = int(ticket.split(" ")[-1][:-1])
    winning = set(int(x.strip()) for x in winning.split())
    filed = set(int(x.strip()) for x in filed.split())
    l.append(len(winning & filed))
x = [1] * len(l)
for i in range(len(x)):
    for d in range(1, l[i] + 1):
        x[i + d] += x[i]
print(sum(x))