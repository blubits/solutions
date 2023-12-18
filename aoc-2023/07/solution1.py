from collections import Counter

def convert(value):
    if value == "A": return 14
    if value == "T": return 10
    elif value == "J": return 11
    elif value == "Q": return 12
    elif value == "K": return 13
    else: return int(value)

def classify(hand):
    distinct_cards = Counter(hand)
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

