---
platform: "cf"
code: "1513d-gcdmst"
title: "GCD and MST"

date-created: 2024-06-29
date-updated: 2025-01-30
status: complete

problem-link: "https://codeforces.com/contest/1513/problem/D"
problem-description: "Find the MST of an implicit graph based on the GCD of subarrays of a list."
solution-summary: "Generate the implicit graph and use Kruskal's algorithm."
running-time: "$O(n \\log n)$"
solution-link: "https://github.com/blubits/solutions/blob/main/cf/@solved/1513d-gcdmst/gcdmst.cpp"
tags:
    - mst
    - number-theory
---

# Codeforces `1513D` - GCD and MST

Let $n$ be the number of nodes in the tree, which is also the length of the list $A$. Consider the edges of the implicit graph in the problem. We can classify them into two types:

1. Type 1 edges that connect nodes $i$ to $i + 1$ with weight $p$.
2. Type 2 edges that connect two nodes $[i, j]$ with weight $\min(A[i:j])$ if $\gcd(A[i:j]) = \min(A[i:j])$.

First, note that an MST always exists simply by considering all Type 1 edges. Thus, the worst possible weight for this MST would be $p(n - 1)$. We can improve the MST by considering edges of type 2 with weight less than $p$.

What nodes are these? First, consider that an edge between $i$ and $j$ must have weight equal to a specific value $v \in A[i:j]$. That is, the only possible edge weights in type 2 are the values in $A$.

Now consider running Kruskal's algorithm on this graph, which considers edges in increasing order. A natural order in which we should process the graph would be to consider Type 2 edges in increasing order, which is equivalent to considering the elements in $A$ in increasing order. We stop considering type 2 edges once their weight runs past $p$, since in this case it would be better to add a type 1 edge to the graph instead.

Fix a certain $v \in A$ such that $v = A[k]$. Which edges $(i, j)$ have weight $v$?
1. First off, if $w(i, j) = v$, then $\min(A[i:j]) =\gcd(A[i:j]) = v$, by definition. This means $i \le k \le j$, i.e. $k$ is somewhere between $i$ and $j$.
2. Since $v$ is the GCD in $A[i:j]$, that means it divides all elements in $A[i:j]$.
3. Since $v$ also exists (and is the minimum) in $A[i:j]$, by definition of the GCD, this means that $A[l] = 0 \pmod{A[k]}$ for all $i \le l \le j$.

Therefore, we can generate the appropriate edges as follows. Fix $v = A[k]$ and consider elements to the right of $A[k]$ first.
1. Let $k < j$. If $A[j] = 0 \pmod{A[k]}$, then the edge $(k, j)$ exists and we can join $(k, j)$.
2. We can repeatedly increment $j$ until the end of the list because of the transitivity of the GCD. Consider $k < j_1 < j_2$. If $A[j_1] = 0 \pmod{A[k]}$ and $A[j_2] = 0 \pmod{A[k]}$ then $\gcd(k, j_1, j_2) = k$.
Therefore, we connect $A[k]$ to every node in the range $A[j_1:j_2]$, since an edge exists between $A[k]$ and these nodes.

A similar argument can be made if we consider elements to the left of $v$.

Increase $v$ and build up the tree until we reach $v \ge p$. At this point, we connect the tree to all unconnected notes via type 2 edges. If there are $c$ connected components, we need to add $c - 1$ edges with weight $p$ to the MST, one to bridge each connected component.

An optimization: As we build the MST, connected components always correspond to contiguous segments of the array. That is, if $i$ and $j$ belong to the same CC then every node between $i$ and $j$ must also be part of the CC; this is a natural consequence of what we found above. [^1] Therefore, instead of a DSU, keep a `connected` array, where `connected[i] = True` iff `(i, i + 1)` belong to the same CC.

---
[^1]: Proof: Let $A[k]$ be the minimum in $A[i:j]$. $i$ and $j$ belonging to the same CC implies that there exists an edge from $(i, k)$ and from $(k, j)$. The existence of the edge $(i, k)$ implies that $\gcd(A[i:k])=\min(A[i:k])=A[k]$. But this must mean that $\gcd(A[i+1:k])=\min(A[i+1:k])=A[k]$ and so on. Thus $i + 1, \ldots, k - 1$ must also be part of the CC. A similar argument can be made for the edge $(k, j)$.
