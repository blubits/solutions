---
platform: "kattis"
code: "crackingrsa"
title: "Cracking RSA"

date-created: 2023-09-28
date-updated: 2025-01-28
status: complete

problem_link: "https://open.kattis.com/problems/crackingrsa"
problem_description: "Crack a message encrypted via RSA."
solution_summary: "Complete search."
running_time: "$O(npq)$"
solution_link: "https://github.com/blubits/solutions/blob/main/kattis/@solved/crackingrsa/crackingrsa.cpp"
tags:
    - complete-search
    - number-theory
---

# Kattis `crackingrsa` - Cracking RSA

Some rough napkin math would suggest that, since $1 \le d \le \varphi(n)$, $\varphi(n) = (p-1)(q-1)$ (given $n = pq$) and $2 \le p, q \le 1000$, then $1 \le d \le 1000000$. We would need to, at most, search through a million possible values of $d$; there are most fifty test cases, so a total operation count of 50 million is reasonably doable and can be done within TLE.

We're given $n$ and $e$, so we have to figure out two things; first, calculate the $p$ and $q$ such that $n = pq$, and then calculate $d$ such that $de \equiv 1\mod \varphi(n)$ (or $de - 1 = 0 \mod \varphi(n)$). Both steps can be calculated using complete search. A few notes:

- Since $n$ is guaranteed to be a product of two primes, take $p$ to be the smaller prime; terminate when $p$ is found, since $q$ is simply given by $n \div p$. This turns a quadratic search space into a linear one.
- $de$ might not fit into an `int`, so take care to use a `long long` instead.
