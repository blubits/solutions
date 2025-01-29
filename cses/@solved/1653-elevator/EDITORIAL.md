---
platform: "cses"
code: "1653-elevator"
title: "Elevator Rides"

date-created: 2024-04-23
date-updated: 2025-01-28
status: complete

problem-link: "https://cses.fi/problemset/task/1653"
problem-description: "Find the optimal number of elevator rides for a set of people."
solution-summary: "Perform DP on subsets."
running-time: "$O(n2^n)$"
solution-link: "https://github.com/blubits/solutions/blob/main/cses/@solved/1653-elevator/elevator.cpp"
tags:
    - dp
    - subset-dp
---

# CSES `1653` - Elevator Rides

In set-theoretical terms, we need to minimize the number of partitions to make to a set $S$, such that the sum of each partition does not exceed $x$.

Define $S$ as the set of people who we've already brought to the top. Define two functions:

- $n(S)$ is the number of trips it took to deliver everyone in $S$.
- $w(S)$ is the combined weight of the last elevator trip that the people in $S$ took.

Given a set $S$ and the last person transported $i$, either $i$ adds to the last elevator ride or, if adding $i$ exceeds the weight limit, a new elevator ride is added with $i$ as the sole occupant. In more formal terms:

$$
n(S), w(S) = \min_{\forall i \in S} \begin{cases}n(S \setminus \left\{i\right\}), w(S \setminus \left\{i\right\}) + w_i&w(S \setminus \left\{i\right\}) + w_i\le x\\n(S \setminus \left\{i\right\}) + 1, w_i&\text{otherwise}\end{cases}
$$

The problem exhibits optimal substructure since the optimal value for a given set is only derived from the optimal value for any of its subsets, without regard as to how those subsets are actually ordered. Each state can also possibly appear many times, which implies the subproblems are overlapping.
