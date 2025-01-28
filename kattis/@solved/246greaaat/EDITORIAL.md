---
platform: "kattis"
code: "246greaaat"
title: "2, 4, 6, Greaaat"

date-created: 2023-11-10
date-updated: 2025-01-28
status: draft

problem_link: "https://open.kattis.com/problems/246greaaat"
problem_description: "Find an optimal sequence of cheers for a given enthusiasm level."
solution_summary: "Perform modified Djikstra's on a DP state graph."
running_time: "$O(|E| + |V|)$"
solution_link: "https://github.com/blubits/solutions/blob/main/kattis/@solved/246greaaat/246greaaat.cpp"
tags:
    - dp
    - graph-theory
---

# Kattis `246greaaat` - 2, 4, 6, Greaaat

If we remove the flavor text, this is a relatively simple problem: given a list of items (cheers) $1, \ldots, i$ each with "value" (enthusiasm level) $-200,000 \le V_i \le 200,000$ and "weight" (difficulty level) $1 \le D_i \le 10^9$, such that each item can be selected an unlimited amount of times, find an optimal configuration of items with minimum total difficulty that sum up exactly to a value $T$.

Note that the item with $s=1, d=1$ is always available to be selected as the first cheer. Thus, in the worst possible case, our best possible choice would just be to simply select this cheer $T$ times; this would have a total difficulty of $T$. Thus, (1) a solution always exists; and (2) any easier selection of cheers than the naive case (a "lighter" selection of items) would have total difficulty less than $T$.

### An easier variation

Let's deal with a slightly easier variation of the same problem, where we limit the enthusiasm level to strictly non-negative integers (i.e. $s_i > 0$ for all $i$) . We work with a simpler problem:

```cpp
Target T: 10
Cheers:
	* s = 1, d = 1
	* s = 2, d = 1
	* s = 3, d = 2
```

Again, we are minimizing $\sum d$ while ensuring that we get to the target $\sum s = T$. Notice that this is a straightforward DP recurrence, a bit of a hybrid between coin change and generalized knapsack. Let $C_S$ be the minimum total difficulty $\sum d$ given a target enthusiasm $S$. Then

$$
C_S = \min\{C_{S - s_i} + d_i \quad\forall i\}
$$

or `C[S] = min(C[S - e[i]] + d[i])` for all cheers from `1` to `i`. Since `s_i` is positive, smaller subproblems will necessarily make up bigger ones; that is, `C[i]` will be calculated after `C[j]` if `i > j`.

Note the straightforward base cases: `C[0] = 0` (no cheers needed), and `C[i, i < 0] = +INF` (no negative enthusiasm).

### DP as a DAG

To transition to the general version of the problem, let's start to visualize the DP recurrence in a tree. Like our visualizations before, each vertex in the tree represents a state, while each edge represents a bigger subproblem calling a smaller subproblem. We assign the weight of each edge as the difficulty level corresponding to making that respective cheer; for example, the edge between state `7` and state `10` would be `5`, since the cheer with enthusiasm level 3 has a difficulty of 5.

Like our discussion on DP problems represented with DAGs, let's assign a direction to each edge, from smaller to bigger state (or from called to caller).

%% TODO: DAG visualization. %%

Again, as per our discussion before, most DP minimization problems can be restated as shortest-path problems on an appropriately created DAG. The graph above is clearly a DAG, since all edges can be drawn forwards. In this case, the length of shortest path between the starting state 0 and the ending state 10 would give us the minimum total difficulty for the required enthusiasm level.

Let's now go back to the initial problem, where enthusiasm can decrease but difficulty is always positive, by adding the edge `s = -1, d = 1`. We highlight the relevant edges that this adds to the graph:

%% TODO: DAG visualization 2. %%

Notice that the presence of negative edges no longer makes the graph a DAG; we can now cycle infinitely between states. This does *not* add negative cycles. What this does add is the possibility that the shortest path requires you to go over the enthusiasm level $T$ or below the zero enthusiasm level, which makes the number of states (and thus number of vertices) theoretically infinite! We can't have this, so we have to reduce the number of states somehow.

We now cite two observations:

**The shortest path does not need to go through negative states.** Each time we change state, the enthusiasm level either goes up or goes down. Let $a$ be the total increase in enthusiasm and $b$ be the total decrease in enthusiasm for the shortest path. For example, for sample input 1, we can take the path `0 -> -2 -> 5 -> 12 -> 19 -> 20`, for a total increase of $a = 22$ and $b = 2$. Note that $a-b=T > 0$, or $a > b$. Since the order in which we take the cheers does not matter with respect to the end result (the net enthusiasm), we can choose to take all the increases in enthusiasm first, before the decreases in enthusiasm: `0 -> 7 -> 14 -> 21 -> 22 -> 20`. Since $a > b$ we never have to dip below 0 in this case.

**There is an upper bound to the greatest state that a shortest path can pass by**: it is $T - c$ where $c$ is the minimum of 0 and the least enthusiastic cheer. Assume there was a higher upper bound. Then we would need more than one edge to go back to our goal result $T$. Since difficulty is always positive, this would always result in a longer path.

Thus:

- Fix the number of states, or the number of vertices, to those in the bound $[0, T - c]$. Ignore any edge that takes you to a state outside these bounds.
- Only use the negative cheers when we are at a state greater than $T$; we have shown in the first observation that we can always take on all the positive cheers first, and only take the negative ones once we go overboard. This helps save on edges.

We can't rely on toposort to calculate the shortest path because the graph is no longer a DAG, so use something like Dijkstra's algorithm to calculate the shortest path. Any form of Dijkstra's should be okay, since there are no negative cycles and thus we only deal with increasing shortest path lengths.

Recall that Dijkstra's has running time $O(|E| + |V| log |V|)$. There are at most 400,000 vertices (see the upper bounds for $S_i$) and roughly $500$ edges per vertex (or $2 \times 10^8$ edges in all), which would account for a frightening 400,000,000+ operations. Naively implementing Dijkstra's would net us an AC for the first few test cases, but will get TLE around test case 10.

### Modifying the priority queue

The easiest speedup (and the one that will get you just below the threshold for AC) would be to remove the logarithmic factor from the priority queue. From earlier, we noted that any shortest path would have length at most $T$, because we can naively just run the first cheer over and over. Thus in Djikstra's algorithm, we only care about shortest path lengths from 0 up until $T$.

Create a vector of queues `q`, where `q[i]` contains the vertices `v` such that the path from `0->v` is equal to `i`. We start at `q[0]` which contains vertex `0`. We simply run through all of the queues, in order, moving from one queue to the next when our current queue is already empty.

- When relaxing an edge `(u, v)` such that `dist[v] = dist[u] + w_uv`, we set `q[dist[u] + w_uv]` to be equal to `v`.
- Like in modified Dijkstra's, we use lazy deletion; if we see a vertex, we only process it if its distance is smaller than what we have already seen.
- If we find that `dist[u] + w_uv` is outside the bounds of the states we know are part of the shortest paths, we do not enqueue it in the queue.

Using this modified data structure gets our running time to just under a second. There are additional optimizations we can do to cut our running time, but this is just enough for us to get AC.

### Things to remember

- This is an implicit graph. Do not actually store the graph that represents the states and edges between the states since this is far too large. It is better to store the actual cheers in a list. Every time we get the neighbors of a state, we simply run through this cheer list (ignoring the negative enthusiasm cheers depending on the state we are at).
- We need to actually trace the cheers, so keep vertices that remember the parent state (to trace which steps comprise the shortest path) as well as a state that remembers the edge type (or cheer) you took to get to that state via the shortest path.
- Find ways to optimize the code here and there (using arrays instead of vectors and using fast I/O, for example), since unoptimized code will run dangerously close to the TLE threshold.
- You can optimize the code even further by using a meet-in-the-middle technique.
