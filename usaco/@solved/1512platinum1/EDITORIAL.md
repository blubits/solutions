---
platform: "usaco"
code: "1512platinum1"
title: "Max Flow"

date-created: 2024-08-21
date-updated: 2025-01-28
status: complete

problem-link: "https://usaco.org/index.php?page=viewproblem2&cpid=576"
problem-description: "Find the maximum flow of milk along any stall."
solution-summary: "Counting paths via DP through the LCA."
running-time: "Roughly $O(n \\log n)$"
solution-link: "https://github.com/blubits/solutions/blob/main/usaco/%40solved/1512platinum1/1512platinum1.cpp"
tags:
    - dp
    - tree
---

# # USACO `2015-12 Plat 1` - Max Flow

Without the flavor text, the problem can be stated as the following:

> Given $n$ vertices in a tree and $k$ active paths along that tree, give the maximum number of paths passing along any one vertex.

Create a `num_paths` array to count the number of paths for each vertex $v$. We can use DFS over each given path from $u$ to $v$ to fill this array, and then get the maximum of the array. This will run in quadratic time, too slow for the problem.

WLOG, we know that every path from $u$ to $v$ must pass through $\text{LCA}(u, v)$. Break down the path from $u$ to $v$ into two paths: one from $u$ to $\text{LCA}(u, v)$, and one from $v$ to $\text{LCA}(u, v)$. We'll deal with double-counting later.

For each vertex, let's keep track of the number of vertices that start at $v$ and the number of vertices that end at $v$. Let's store this in `start[v]` and `end[v]` as well. This can easily be computed as we get the list of paths in.

Our problem now: given `start[v]` and `end[v]`, how can we compute the number of paths that pass by $v$?

Let's characterize the paths that pass by $v$:

- Paths that start at $v$. This is given by `start[v]`.
- Paths that originate from any of $v$'s children, and happen to pass by $v$. Let's call this quantity $A$.

$A$ can be calculated by traversing $A$'s immediate children. What we want for each child $n$ is to calculate `start[n] + A` (for its own calculation of $A$) but then subtract `end[n]`, since paths that end at $n$ do not pass by $v$.

Now for our given vertex $v$, the number of paths that pass by it would be `start[v] + A`. Now we don't subtract `end[v]` because if it ends at $v$, it still passes by $v$. Instead, we subtract to account for double-counting in $A$. `end[v]` only has a value if $v$ is an LCA, and for a path given in the input we stored it as two paths that end at an LCA. So we need to subtract `end[v] / 2` to take into account this double-counting.

Although the solution code is above, we'll be highlighting `process_answer` here to see how we execute that in action.

```cpp
int process_answer(int v) {
    int num_paths_v = 0;
    visited[v] = true;
    for (auto n : graph[v]) {
        if (!visited[n]) {
            num_paths_v += process_answer(n);
        }
    }
    num_paths[v] = num_paths_v + starts_at[v] - ends_at[v] / 2;
    return num_paths_v + starts_at[v] - ends_at[v];
}
```

Lines 2, 6, and 10 are responsible for calculating $A$. $A$ is calculated by getting `process_answer` for each vertex $n$ that is a child of $v$. The actual calculation being requested is whatever is in line 10. Notice how the tree is being traversed in postorder.

```cpp hl=2,6,10
int process_answer(int v) {
    int num_paths_v = 0;
    visited[v] = true;
    for (auto n : graph[v]) {
        if (!visited[n]) {
            num_paths_v += process_answer(n);
        }
    }
    num_paths[v] = num_paths_v + starts_at[v] - ends_at[v] / 2;
    return num_paths_v + starts_at[v] - ends_at[v];
}
```

Line 9 is what actually calculates the answer, which we store in `num_paths[v]`. We can almost treat it like it's "separate" from the actual DFS that calculates $A$ but we include it here so we can calculate everything in one pass.

```cpp hl=9
int process_answer(int v) {
    int num_paths_v = 0;
    visited[v] = true;
    for (auto n : graph[v]) {
        if (!visited[n]) {
            num_paths_v += process_answer(n);
        }
    }
    num_paths[v] = num_paths_v + starts_at[v] - ends_at[v] / 2;
    return num_paths_v + starts_at[v] - ends_at[v];
}
```

The following code is equally valid and illustrates how both calculations are separate more clearly:

```cpp
int process_answer(int v) {
    int num_paths_passing_by_v = 0;
    visited[v] = true;
    for (auto n : graph[v]) {
        if (!visited[n]) {
            num_paths_passing_by_v += process_answer(n);
        }
    }
    A[v] = num_paths_passing_by_v;
    return num_paths_passing_by_v + starts_at[v] - ends_at[v];
}

// in main()
process_answer(0);
for (int i = 0; i < n; i++) {
	num_paths[v] = A[v] + starts_at[v] - ends_at[v] / 2;
}
```
