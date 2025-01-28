---
platform: "kattis"
code: "getshorty"
title: "Get Shorty"

date-created: 2024-04-21
date-updated: 2025-01-28
status: incomplete

problem_link: ""
problem_description: ""
solution_summary: ""
running_time: ""
solution_link: ""
tags:
    -
---

# Kattis `getshorty` - Get Shorty

The problem can be reduced to a longest (multiplicative) path in a graph. By doing the transformation $w \to -\ln{w}$, we can turn the path weights additive (since the logarithm turns a multiplicative function into an additive one) and make the edge weights positive (since $0 \le w \le 1$, $\ln{w}\le 0$ and thus $-\ln{w} \ge 0$). This should turn the problem back into a shortest path.
