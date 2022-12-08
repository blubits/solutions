fact = [1]
for i in range(9):
    fact.append((i + 1) * fact[i])

def sum_fact(x):
    return sum(fact[int(digit)] for digit in str(x))

occ = {}
succ = {}
