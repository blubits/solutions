from collections import Counter

def convert(value):
    if value == "A": return 14
    if value == "T": return 10
    elif value == "J": return 1
    elif value == "Q": return 12
    elif value == "K": return 13
    else: return int(value)

def classify(hand):
    distinct_cards = Counter(hand)
    hand_type = tuple(reversed(sorted(distinct_cards.values())))
    # greedily turn all "J" cards into the most common card in the hand
    if distinct_cards["J"] > 0:
        most_common = distinct_cards.most_common(1)[0][0]
        # if J is the most common, turn it into the second most common card in each hand
        if most_common == "J":
            try:
                most_common = distinct_cards.most_common(2)[1][0]
            except IndexError:
                # if there is no second most common card, then the hand is all Js
                pass     
        distinct_cards = Counter(hand.replace("J", most_common))
        hand_type = tuple(reversed(sorted(distinct_cards.values())))
    default_value = (
          100000000 * convert(hand[0])
        + 1000000 * convert(hand[1])
        + 10000 * convert(hand[2])
        + 100 * convert(hand[3])
        + convert(hand[4])
    )
    if hand_type == (5,):
        return 60000000000 + default_value
    elif hand_type == (4, 1):
        return 50000000000 + default_value
    elif hand_type == (3, 2):
        return 40000000000 + default_value
    elif hand_type == (3, 1, 1):
        return 30000000000 + default_value
    elif hand_type == (2, 2, 1):
        return 20000000000 + default_value
    elif hand_type == (2, 1, 1, 1):
        return 10000000000 + default_value
    else:
        return default_value
    

bids = [line.rstrip().split() for line in open("input").readlines()]
bids = [(x, int(y)) for x, y in bids]
bids.sort(key=lambda t: classify(t[0]))
ans = 0
for i, bid in enumerate(bids):
    hand, bid_amnt = bid
    ans += (i + 1) * bid_amnt
    print(i, bid, classify(bid[0]), ans)
print(ans)

