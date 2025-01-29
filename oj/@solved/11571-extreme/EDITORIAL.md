---
platform: "oj"
code: "11571"
title: "Simple Equations - Extreme!!"

date-created: 2024-08-06
date-updated: 2025-01-29
status: complete

problem-link: "https://onlinejudge.org/external/115/11571.pdf"
problem-description: "Given $A, B, C$, find any $x, y, z$ that satisfies the given equations."
solution-summary: "Complete search through factors of $B$."
running-time: "$O(\\sigma_0(B)) \\approx O(\\log{B})$"
solution-link: "https://github.com/blubits/solutions/blob/main/oj/@solved/11571-extreme/extreme.cpp"
tags:
    - complete-search
    - number-theory
---

# OJ `11571` - Simple Equations - Extreme!!

This is a harder variation of [[oj/@solved/11565-equations/EDITORIAL|OJ `11565`]].

Even with our modified solution space from that problem, the new limits for this problem - $A, B, C \le 6 \times 10^{18}$ - are not enough to get AC. If we follow the same strategy from before, we'd have $x, y, z \in [-2.5 \times 10^9, 2.5 \times 10^9]$ which is still too huge. Given the input limits, we'd want our eventual algorithm to run in sub-linear time instead of cubic time.

To recall, here are our equations:

$$
\begin{equation}\begin{cases}x+y+z=A&(1)\\xyz=B&(2)\\x^2+y^2+z^2=C&(3)\end{cases}\end{equation}
$$

First off, let's try to cut down the for loop nesting from 3 to 2. From equation 1, we have $z = A - x - y$ so we just need to loop through $x$ and $y$ and determine $z$ from that.

We can still cut down the nesting from 2 to just 1. Substitute $z = A - x - y$ back to equation 2, and we have: [^1]

$$
\begin{align*}
	xy(A-x-y) &= B\\
	Axy - x^2y - xy^2 &= B\\
	Axy-x^2y-xy^2-B&=0\\
	-xy^2-x^2y+Axy-B&=0\\
	(-x)y^2-(x^2+Ax)y-B&=0\\
	(-x)y^2-(x(x+A))y-B&=0\\
	y^2+(x+A)y + \frac{B}{x}&=0
\end{align*}
$$

which is a quadratic equation in $y$, and easily solvable using the quadratic formula. (We can get both solutions and keep which ever one is positive, or simply get the positive root.)

Now we'll just have to loop through all possible values of $x$. There are still far too many possible values of $x$, so let's try to slim that down.

From equation 2, $x$ is a factor of $B$. Recall that $\sigma_0(n)$ calculates the number of factors of a number $n$. It would be reasonable to think that this would be a fairly reasonable number even for large values of $n$, and certainly much more reasonable than the billions of values for $x$ we'd have to search.[^2] So it would make sense for our input space to be $\{x \mid (x \mathrel{|} B)\}$, which we can derive by an $O(\log{n})$ adaptation of the prime factorization algorithm.

Deriving $y$ and $z$ takes constant time, and verifying our conditions would also take constant time, so this solution runs in $O(\sigma_0(B)) \approx O(\log{B})$ overall.

A few notes:

- Don't forget to use `long long`.
- $x, y, z$ might be out of order, so print them in the required lexicographical order before printing them to the screen.

[^1]: We can safely divide by $x$ because $x$ is never 0. If it was, $B = 0$, but the bounds guarantee $B$ is positive. $\frac{B}{x}$ is also integral because, as we'll see later, $x$ is a factor of $B$.
[^2]: Per [Terence Tao](https://terrytao.wordpress.com/2008/09/23/the-divisor-bound/): "For any large number $n$, only a "logarithmically small" set of numbers less than $n$ will actually divide $n$ exactly… The average value of \[$\sigma_0(n)$\] is much smaller, being about $\log{n}$ on the average."
