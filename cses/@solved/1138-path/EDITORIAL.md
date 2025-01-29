---
platform: "cses"
code: "1138-path"
title: "Path Queries"

date-created: 2024-07-30
date-updated: 2025-01-28
status: complete

problem-link: "https://cses.fi/problemset/task/1138/"
problem-description: "Get the path sum in a changing tree."
solution-summary: "Create a tree traversal array with an RUPQ data structure."
running-time: "$O(q \\log n)$"
solution-link: "https://github.com/blubits/solutions/blob/main/cses/@solved/1138-path/path.cpp"
tags:
    - range-query
    - tree
---

# CSES `1138` - Path Queries

Create a tree traversal array for the input tree, and then feed it onto a RUPQ data structure, like a difference array binary indexed tree or a segment tree with lazy propagation. Define the range update as a range increment update.

If you implemented the `idx` array and the `subtree_at(v)` function as in 23.03, then with `s` appropriately decremented:

- Queries of type 1 (vertex updates) can be implemented as `{cpp} auto [a, b] = subtree_at(s); RUPQTree.update(a, b, dx)`, with `{cpp} dx = x_new - x_old`.
- Queries of type 2 (subtree queries) can be retrieved from `{cpp}  PURQTree.query(a, b)`.

The code in the link uses a pointer-based RSQ segment tree and runs in about 0.84s.
