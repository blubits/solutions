---
platform: "kattis"
code: "presidentialelections"
title: "Presidential Elections"

date-created: 2024-06-05
date-updated: 2025-01-28
status: complete

problem-link: "https://open.kattis.com/problems/presidentialelections"
problem-description: "Count how many votes you need to win a majority."
solution-summary: "Knapsack-type DP with preprocessing."
running-time: "$O(S \\ cdot \\max{D})$"
solution-link: "https://github.com/blubits/solutions/blob/main/kattis/%40solved/presidentialelections/presidentialelections.cpp"
tags:
    - dp
    - knapsack-dp
---

# Kattis `presidentialelections` - Presidential Elections

> [!info]- Sidenote: Presidential elections in the real world
> The United States presidential election works using the **electoral college** system, similar to the system discussed in this problem. In US elections, each of the 50 states is assigned a set number of delegates; there are 538 delegates in total. Whoever wins a majority of the votes in one state wins all the delegates for that state.[^1] Whoever gets a majority of delegates, 270, wins the state.
>
> Note that, in a national tie, it is the United States congress that decides who wins, instead of whoever is the oldest party.

First off, let's talk about the overall win condition and the win condition for each state.

- **National win condition:** You win if you get more than half of the number of total delegates $t$. If $t$ is odd, then this is just $\lceil \frac{t}{2} \rceil = \lfloor \frac{t}{2} \rfloor + 1$; if $t$ is even, this is $\frac{t}{2} + 1$ (since a national delegate tie would hand the win to your opponent). Overall, this is just `t/2 + 1` (integer division plus one).
- **State win condition**: Each state is winner-takes-all: the winner in that state wins all the delegates, regardless of how close the actual election is within that state. Thus to win all the delegates for a state, you only need to win 50% + 1 of the total vote. This is just `(c + f + u) / 2 + 1` votes.

Not all states are up for grabs, since it is possible that even if all undecided voters decide to go for one party, the other party still has more votes. We can classify each state into three categories: **safe-C states** ($f + u < c$), **safe-F states** ($c + u \le f$), and **swing states** (neither safe-C nor safe-F).

Note that if the number of delegates for safe-C states exceeds the national win threshold, you win (with 0 extra votes needed). If the number of delegates for safe-F states exceeds the national win threshold or is exactly equal to your delegate count, it is impossible for you to win.

If neither of you meet the threshold, you'll need to pick off from the list of swing states. To win a swing state, you'll need to pick off enough undecided voters to make you the majority. This is equal to the state win condition, `(c + f + u) / 2 + 1`, minus the number of votes you already have locked up, `c`. Let's name this threshold $T_i$ for the $i$th swing state. Let's also notate $D_i$ as the number of delegates the $i$th swing state can provide.

You want to select a subset of swing states that minimize your vote count, while still allowing you to win. Let $m(n, d)$ be the minimum number of votes needed to capture at most $d$ delegates, considering all swing states from $S_1$ to $S_n$. Either $S_n$ is included in that set or not, in which case we add $T_i$ votes or 0 votes:

$$
m(n, d) = \min(m(n - 1, d), m(n - 1, d - D_i)) + T_i
$$

To win nationally, you need to have `t/2 + 1 - C_sure` states (where `C_sure` is the number of delegates of the states you've locked up). Let's mark this threshold $d_{w}$. The minimum number of votes is thus equal to

$$
\min_{i = d_w}^{t} \left(m(|S|, i)\right)
$$

i.e. the value of $m(|S|, i)$ for all valid $i$, from the number of delegates you strictly need to the total number of delegates.

---
[^1]: Two states - Maine and Nebraska - award one delegate for each congressional district, as well as three delegates for the state-wide winner.
