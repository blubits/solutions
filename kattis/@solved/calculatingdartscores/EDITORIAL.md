---
platform: "kattis"
code: "calculatingdartscores"
title: "Calculating Dart Scores"

date-created: 2023-09-27
date-updated: 2025-01-28
status: complete

problem_link: "https://open.kattis.com/problems/calculatingdartscores"
problem_description: "Calculate dart scores."
solution_summary: "Complete search."
running_time: "Effectively $O(1)$"
solution_link: "https://github.com/blubits/solutions/blob/main/kattis/@solved/calculatingdartscores/calculatingdartscores.cpp"
tags:
    - complete-search
---

# Kattis `calculatingdartscores` - Calculating Dart Scores

The output space would be all possible six-tuples $(a, x, b, y, c, z)$ such that $ax+by+cz = n$, with $0 \le n \le 180$, $0 \le a, b, c \le 3$, and $1 \le x, y, z \le 20$. This means that the size of the output space is $3^3 \times 20^3=216000$. Given that there is only one input anyway, this means that we only need to search through the output space once; the hardest part would be to convert the six-tuple into the output format needed by the problem.
