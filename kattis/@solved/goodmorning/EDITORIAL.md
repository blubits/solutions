---
platform: "kattis"
code: "goodmorning"
title: "Good Morning"

date-created: 2023-09-30
date-updated: 2025-01-28
status: complete

problem-link: "https://open.kattis.com/problems/goodmorning"
problem-description: "Find the closest valid possible input on a number pad."
solution-summary: "Complete search with backtracking."
running-time: "$O(5^n)$"
solution-link: "https://github.com/blubits/solutions/blob/main/kattis/@solved/goodmorning/goodmorning.cpp"
tags:
    - complete-search
---

# Kattis `goodmorning` - Good Morning

Perform backtracking on the entire solution space.
- **State:** The current button being pressed, which you can notate as $(i, j)$ if the keypad is expressed as a 2D array $K$. Also note the number of buttons that have been pressed $p$, as well as the current combination actually pressed $C$.
- **Transition:** There are two decisions we need to make: whether we press the current button or not (such that $p \to p, C \to C$ or $p \to p + 1, C \to C + K_{ij}$), and where we move our finger towards. This makes five states in total:
	- We do not press the current button, and move right to $(i, j + 1)$;
	- We do not press the current button, and move down to $(i + 1, j)$;
	- We do press the current button, and stay at $(i, j)$;
	- We do press the current button, and move right to $(i, j + 1)$;
	- We do press the current button, and move down to $(i + 1, j)$.
- **Final state:** Since $1 \le k \le 200$, we can stop when we've pressed three buttons.

We combine all final states through adding $C$ to a global "valid" list. The list would thus contain all possible button inputs with at most three digits. We can filter out all inputs greater than 200 to fit the problem requirements.

Once we have a list of all possible inputs, for each intended input $k$, we simply find the closest possible input to $k$ (which is either the `upper_bound` or the `lower_bound` of $k$, if $k$ itself cannot be found in the list).
