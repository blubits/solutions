---
platform: "oj"
code: "11565"
title: "Simple Equations"

date-created: 2024-08-06
date-updated: 2025-01-28
status: complete

problem-link: "https://onlinejudge.org/external/115/11565.pdf"
problem-description: "Given $A, B, C$, find any $x, y, z$ that satisfies the given equations."
solution-summary: "Complete search over $x, y, z$ with pruning."
running-time: "$O(n^3)$"
solution-link: "https://github.com/blubits/solutions/blob/main/oj/@solved/11565-equations/equations.cpp"
tags:
    - complete-search
---

# OJ `11565` - Simple Equations

The most naive solution would be to simply run through all possible values of $x, y, z$. The corresponding solution space - $\{(x,y,z)\mid -10000 \le x, y, z \le 10000\}$ - is huge, so we need to prune this significantly.

Recall that we have three equations we need to satisfy:

$$
\begin{equation}\begin{cases}x+y+z=A\\xyz=B\\x^2+y^2+z^2=C\end{cases}\end{equation}
$$

Note that $1 \le A, B, C \le 10000$. Take $x=y=1$ and $C=10000$. Then by equation 3,

$$
\begin{align}1^2+1^2+z^2&=10000 \\ z^2 &= 10000-1^2-1^2 \\ z^2 &= 9998 \\ z &= \sqrt{9998} \le 100 \end{align}
$$

By a similar argument, $x$ and $y$ is also at most 100; thus, the output space is now $x, y, z \in [-100,100]$ and we prune the output space from a magnitude of a trillion ($20000^3=8 \times 10^{12}$) to a magnitude of a million ($200^3=8 \times 10^6$), which will already get AC.

To optimize this further, use the second equation. Without loss of generality, take $x$ to be the smallest number. Since $x \le y$ and $x \le z$, we have $xyz \le x^3 = B$, or $x \le \sqrt[3]{B}$. Since $B\le 10000$, thus $x \le \sqrt[3]{10000}$ or $-22 \le x \le 22$.

Notes:

- We add a few `if` statements to end the loop early if a branch of the complete search is untenable.
- Note that the outputs $x, y, z$ can be in any order, since the equations are all commutative. Because of our iteration strategy, it is possible that we find a set of outputs such that $x > y$, but we need to get the output with the least $x$; thus, we simply swap $x$ and $y$ if needed.
