---
platform: "atc"
code: "abc227-e"
title: "Swap"

date-created: 2024-06-29
date-updated: 2025-01-28
status: complete

problem_link: "https://atcoder.jp/contests/abc227/tasks/abc227_e"
problem_description: "Count the number of strings that can be generated from $S$ after $k$ swaps."
solution_summary: "Perform DP on ranges: $c(s, k, e, y)$."
running_time: "$O(k^5)$"
solution_link: "https://github.com/blubits/solutions/blob/main/atc/@solved/abc227-e/e.cpp"
tags:
    - dp
    - range-dp
---

# AtCoder `abc227-e` - Swap

Let's try to visualize the optimal substructure in this problem. The input string is our "model string". Instead of thinking about swaps in this original string, let's try to build a string from scratch and count the number of swaps needed to get that string from the original string (in other words, an inversion count).

Let's take the input `KKEEYY` as an example. Let's represent it as the pair `(letter: index)` for visualization.

```cpp
(K: 0) (K: 1) (E: 2) (E: 3) (Y: 4) (Y: 5)
```

Again, let's try to build up a new string from these letters from scratch and see how many swaps it takes to get a letter we insert to that string. Let's say we want to insert Y in the first position:

- First off, let's insert the first Y we see, which is at position 4.
- It takes 4 swaps to get Y into the first position. 4 is simply the number of positions between `Y: 4` and the first position in the string.

```cpp
(K: 0) (K: 1) (E: 2) (E: 3) (Y: 4) (Y: 5)
[ Y ] (n = 4)
```

What if we try to insert the second Y?

- This Y is at position 5.
- It takes 4 swaps to get Y into the first position. We can count this easily from above, or we can think of it this way: there are 2 E's and 2 K's before position 5 and we have to clear all of this to get to our correct position.

This results in the following natural recurrence. Let $c(s, k, e, y)$ represent the number of strings with $k$ Ks, $e$ Es, $y$ Ys that were generated with $s$ adjacent swaps. Each time we add the letter K to the string, we run the following equation:

$$
c(s + s_{k+1}, k + 1, e, y) = c(s + s_k, k + 1, e, y) + c(s, k, e, y)
$$

This is a push recurrence. This means that when we arrive at $c(s, k, e, y)$, the value is already correct, we simply push its value onto the states that are based of its value.

where $s_{k+1}$ is the number of swaps it takes to add in K into the string. From our observation before, it's the number of Es and Ys before the position of the $(k+1)$th K. Right now our calculation of that is equal to:

$$
s_{k+1} = (\text{\# of Es before the } k+1\text{th k})+(\text{\# of Ys before the } k+1\text{th k})
$$

But note that if some Es and Ys are already placed in the string, we'll have to take them into account by subtracting it from the swap count since we no longer have to swap them out:

$$
s_{k+1} = ((\text{\# of Es before the } k+1\text{th k}) - e)+((\text{\# of Ys before the } k+1\text{th k}) - y)
$$

Also, it is possible that we have swapped more Es and Ys into the string than the number of Es and Ys before the K. Take for example the string `EEYYKKYYEE`, and the partial string `EEYYY`. There are 2 Ys and 2 Es before the first K, but there are already 3 Ys in the partial string - the K has been pushed back from its initial position. In this case, to swap in the last K we still need 0 swaps. The pushback of the K negates the swap done to position the Y. So if this is the case, the letter swaps we need to do must be 0:

$$
\begin{align*}s_{k+1} = &\max(((\text{\# of Es before the } k+1\text{th k}) - e), 0)\\&+\max(((\text{\# of Ys before the } k+1\text{th k}) - y), 0)\end{align*}
$$

How do we calculate the number of Es before the $(k + 1)$th K in the string? We can calculate this manually in $O(n)$ time by iterating through the string from 0 to the position of the $(k+1)$th K (which we'll notate as $p_{k+1}$). Or we can precalculate this and store the value in an array which we can notate as $n(E, p_{k+1})$ and $n(Y, p_{k+1})$ for the number of Es and Ys on the prefix $S[0:p_{k+1}]$. Thus we have:

$$
s_{k+1}=\max(n(E, p_{k+1}) - e, 0) + \max(n(Y, p_{k+1})-y, 0)
$$

A similar argument can be done for swapping in an E and a Y.

The number of strings $C$ that you can reach from at most $N$ swaps is then just the following:

$$
C=\sum_{s=0}^{N}c(s,|K|,|E|,|Y|)
$$

where $|K|,|E|,|Y|$ is the number of swaps. $N$ can be at most $10^9$ but the most swaps you need to do to transform a string is ${{30} \choose 2} = 435$ so you can get away with a much smaller DP table.

A note on the number of states: $s$ is a required state since we have to keep track of the number of swaps. The rest of the states simply describe the state of the incomplete string, which can be described by 3 of the 4 states:

- The length of the string $x$,
- The number of Ks $k$,
- The number of Es $e$, and
- The number of Ys $y$.

This solution uses the last 3, while the official editorial uses the first and the last two.

Another note: if pull-type DP is more natural for you, we can reframe the problem in terms of figuring out what was the last thing added:

$$
c(s, k, e, y) = c(s - s_k, k - 1, e, y) + c(s - s_e, k, e - 1, y) + c(s - s_y, k, e, y - 1)
$$

In either case, be careful about the conversion from indices to code, since $s_k$ refers to the calculation for the $k$th K (which might correspond to index `k - 1` in your code).
