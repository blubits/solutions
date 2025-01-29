---
platform: "cses"
code: "1137-subtree"
title: "Subtree Queries"

date-created: 2024-07-28
date-updated: 2025-01-28
status: complete

problem-link: "https://cses.fi/problemset/task/1137/"
problem-description: "Get the subtree sum in a changing tree."
solution-summary: "Create a tree traversal array with a PURQ data structure."
running-time: "$O(q \\log n)$"
solution-link: "https://github.com/blubits/solutions/blob/main/cses/@solved/1137-subtree/subtree.cpp"
tags:
    - range-query
    - tree
---

# CSES `1137` - Subtree Queries

Create a tree traversal array for the input tree, and then pass it onto a PURQ data structure, like a binary indexed tree or a segment tree. Define the point update and range query as a point change and a range sum query, respectively.

If you implemented the `idx` array and the `subtree_at(v)` function as in 23.03, then with `s` appropriately decremented:

- Queries of type 1 (vertex updates) can be implemented as `{cpp} PURQTree.update(idx[s], x)`.
- Queries of type 2 (subtree queries) can be retrieved from `{cpp} auto [a, b] = subtree_at(s); PURQTree.query(a, b)`.

The code in the link uses a pointer-based RSQ segment tree and runs in about 0.81s.
