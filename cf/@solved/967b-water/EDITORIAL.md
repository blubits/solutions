---
platform: "cf"
code: "967b-water"
title: "Watering System"

date-created: 2025-01-30
date-updated: 2025-01-30
status: complete

problem-link: "https://codeforces.com/problemset/problem/967/B"
problem-description: "Count the minimum number of holes to cover to get enough water flow."
solution-summary: "Greedily close the largest unopened hole."
running-time: "$O(n \\log n)$"
solution-link: "https://github.com/blubits/solutions/blob/main/cf/@solved/967b-water/water.cpp"
tags:
    - greedy
    - float-free
---

# Codeforces `967B` - Watering System

Let $s_1$ be the first hole and $S$ be the sum of all non-blocked holes. We should block any number of holes, besides the first hole, such that at least $B$ liters flows out of the first hole, i.e.

$$
\frac{s_1A}{S}\le B
$$

Since $s_1$ and $A$ are fixed, we have to decrease $S$ for the entire fraction to exceed $B$.

We need to subtract the largest amount from $S$ while blocking a minimum number of holes. This is only possible by repeatedly blocking the largest unblocked hole - again, without blocking the first hole. So we sort all holes bar the first one, and repeatedly subtract the largest unblocked hole from the sorted set.

Note that $\displaystyle \frac{s_1A}{S}$ is not necessarily integral. We can avoid working with floats, since we never actually need to know the threshold flow. The float-free condition would be:

$$
s_1A\le BS
$$
