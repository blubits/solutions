---
platform: "kattis"
code: "geppetto"
title: "Geppetto"

date-created: 2023-09-27
date-updated: 2025-01-28
status: complete

problem_link: "https://open.kattis.com/problems/geppetto"
problem_description: "Determine all possible unique, legal pizza combinations."
solution_summary: "Complete search."
running_time: "$O(m2^n)$"
solution_link: "https://github.com/blubits/solutions/blob/main/kattis/@solved/geppetto/geppetto.cpp"
tags:
    - complete-search
---

# Kattis `geppetto` - Geppetto

The set of all possible pizzas is the power set of the possible toppings for each pizza, so without restrictions, the number of possible pizzas given $N$ toppings is $2^N$. This can be seen in sample input 2.

To filter out configurations with illegal or invalid pairs, we have to find and remove every subset that contains an illegal pair. For example, if `1 2` and `2 3` are illegal pairs, then the pizzas containing toppings `1 2`, `2 3`, and `1 2 3` are all illegal, for a total of 5 valid pizzas.

Since the maximum number of toppings is low ($N \le 20$), we can simply run through all possible subsets of toppings, represented as a bitmask. For each bitmask, we check if it contains at least one of the $m$ possible illegal pairs; if it does, we subtract one from the maximum number of valid toppings and move on to the next mask.

A naive way to check if the subset contains a pair is to convert the bitmask to an actual set and check for the presence of the pair $a$ and $b$ in the subset. A faster way would be to represent the pair as a bitmask itself. Let `pair_bitmask = (1 << (a - 1)) | (1 << (b - 1))`. For example, for invalid pair `1 2`, `pair_bitmask = 011`. We simply check if `pair_bitmask` is a subset of `mask` by checking if `pair_bitmask | mask = mask` - in set notation, this checks if the union of the set $\{a, b\}$ and the set represented by the mask $M$ is equal to the set $M$ itself, which is only possible if $\{a, b\} \subseteq M$.
