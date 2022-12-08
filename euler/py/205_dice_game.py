from itertools import product

d4 = [1, 2, 3, 4]
d6 = [1, 2, 3, 4, 5, 6]

peter_dice = [d4] * 9
peter_results = {}
for result in product(*peter_dice):
    if sum(result) in peter_results:
        peter_results[sum(result)] += 1
    else:
        peter_results[sum(result)] = 1
print(peter_results)

colin_dice = [d6] * 6
colin_results = {}
for result in product(*colin_dice):
    if sum(result) in colin_results:
        colin_results[sum(result)] += 1
    else:
        colin_results[sum(result)] = 1
print(colin_results)

pete_wins = 0
total_games = 0
for peter, colin in product(peter_results, colin_results):
    print(peter, 'vs', colin, 'Peter wins' if peter >
          colin else 'Peter loses', peter_results[peter] * colin_results[colin], 'games')
    total_games += peter_results[peter] * colin_results[colin]
    if peter > colin:
        pete_wins += peter_results[peter] * colin_results[colin]
print(pete_wins, total_games, "{:07}".format(pete_wins / total_games))
