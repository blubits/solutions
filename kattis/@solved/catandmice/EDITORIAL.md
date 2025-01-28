---
platform: "kattis"
code: "catandmice"
title: "Cat and Mice"

date-created: 2024-04-22
date-updated: 2025-01-28
status: complete

problem_link: "https://open.kattis.com/problems/catandmice"
problem_description: "Determine the minimum velocity in which a cat can catch all hiding mice."
solution_summary: "DP on subsets: $f(M, i)$."
running_time: "$O(n^2 2^n \\ log (\\max V))$"
solution_link: "https://github.com/blubits/solutions/blob/main/kattis/%40solved/catandmice/catandmice.cpp"
tags:
    - dp
    - subset-dp
    - binary-search-the-answer
---

# Kattis `catandmice` - Cat and Mice

As a quick refresh of basic kinematics, recall that $t = d/v$.

Define the following state variables:

- $M$ is the set of all mice that have already been eaten by the cat.
- Of these mice, $i$ is the last mouse that was eaten. (Therefore $i \in M$.)

Let $t(M, i)$ be the minimum time it takes for the cat to eat all mice in $M$, ending at $i$. The optimal time that it takes to eat all mice in $M$ can be determined by the optimal time to eat all mice in $M \setminus \left\{i\right\}$, plus the time it takes to go from the last mice in the previous optimal choice to $i$. This tells us two things: one, the problem exhibits optimal substructure, and two, we need the additional parameter $i$.

Thus:

$$
t(M, i)=\min_{\forall j \in M, j \neq i} (t(M \setminus \left\{i\right\}, j) + \frac{d_{ij}}{v_\text{curr}}
$$

where $d_{ij}$ is the Cartesian distance between mice $i$ and $j$ and $v_\text{curr}$ is the cat's current velocity, which based on the problem description is hampered by the number of mice already eaten. Let $v_0$ be our initial choice of velocity. Each mouse the cat eats slows them down by a factor of $m$. Therefore, if the cat has eaten $\left|M\right|$ mice, their velocity when eating the last mouse is given by

$$
v_\text{curr}=v_0 \times m^{\left|M\right|-1}
$$

An additional complication is that a mouse can hide after a certain time. Let $h(i)$ be the time at which mouse $i$ hides. Thus if $t(M, i) > h(i)$, the cat can't eat mice $i$, and we set $t(M, i) = \infty$.

Note that:

- Our base cases can be found for $t(\left\{i\right\}, i)$ for all mice $i$. This is just the time it takes for the cat to start from the origin and eat the $i$th mouse, which is given by $\frac{d_{0i}}{v_0}$. Note that if this is greater than $h(i)$, we still set the time to infinity.
- Our initial cases can be found for $t(M_\forall, i)$ (the cat visiting every single mouse, ending at $i$) for all mice $i$. If $t(M_\forall, i) < \infty$ for any $i$, the cat can eat all the mice, ending at $i$.

Going back to the problem statement, we are tasked to find the minimum $v_0$ for which the cat can eat all the mice, that is, $t(M_\forall, i) < \infty$ for any $i$. We can try all possible values of $v_0$ and find the minimum value for which there exists a valid cat chase.

Define $f(v_0)$ to be true if there exists a valid cat chase and false otherwise. Note that $f$ is monotone - if the cat can chase all the mice given a certain initial speed, they can certainly still chase the mice if they went faster. Thus we can do binary search the answer on $f(v_0)$ until the desired precision.
