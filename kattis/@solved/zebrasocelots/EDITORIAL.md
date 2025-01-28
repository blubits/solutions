---
platform: "kattis"
code: "zebrasocelots"
title: "Zebras and Ocelots"

date-created: 2023-06-24
date-updated: 2025-01-28
status: complete

problem_link: "open.kattis.com/problems/zebrasocelots"
problem_description: "Count the number of times a peculiar event can happen."
solution_summary: "Convert decimal to binary."
running_time: "$O(n)$"
solution_link: "https://github.com/blubits/solutions/blob/main/kattis/@solved/zebrasocelots/zebrasocelots.cpp"
tags:
    - implementation
---

# Kattis `zebrasocelots` - Zebras and Ocelots

Let's run through the percieved event, specifically working with sample 2. To make things easier, let's rewrite the stack in a single line, where top is at the left.

```
OZZO
```

Initially, our stack looks like this. An ocelot is at the top and bottom, and two zebras are in the middle.

When the zoo bell rings, the ocelot lowest in the pile becomes a zebra. Let's see how this works on a single zoo bell ring, with the lowest ocelot turning into a zebra:

```
OZZZ
```

When the zoo bell rings next, the top ocelot becomes a zebra. All zebras below it become ocelots.

```
ZOOO
```

This repeats until no ocelots exist. Let's run the entire simulation here.

```
OZZO
OZZZ
ZOOO
ZOOZ
ZOZO
ZOZZ
ZZOO
ZZOZ
ZZZO
ZZZZ
```

The stack terminates at `ZZZZ`, where no more ocelots exist.

Notice anything peculiar? Let `O = 1, Z = 0`:

```
1001
1000
0111
0110
0101
0100
0011
0010
0001
0000
```

In binary, this is simply the numbers 9 to 0. The "process" exactly mimics the process of decrementing a binary digit by one: the least significant one (the bottom-most ocelot) becomes a zero (a zebra), and all zeroes after it (all zebras below it) become ocelots (ones).

The code is thus simply just a simple decimal-to-binary conversion, since the number of times you can decrement $x$ by 1 is equal to the original number $x$. Be mindful of integer limits; since $N=60$, the answer can reach up to $2^{60}$, which can only fit in a `long long`.
