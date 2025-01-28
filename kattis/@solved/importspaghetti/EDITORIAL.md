---
platform: "kattis"
code: "importspaghetti"
title: "Import Spaghetti"

date-created: 2023-10-25
date-updated: 2025-01-28
status: complete

problem_link: "https://open.kattis.com/problems/importspaghetti"
problem_description: "Find the shortest circular dependency in a program, if one exists."
solution_summary: "Use Floyd-Warshall to check for cycles."
running_time: "$O(n^3)$"
solution_link: "https://github.com/blubits/solutions/blob/main/kattis/@solved/importspaghetti/importspaghetti.cpp"
tags:
    - graph-theory
    - shortest-paths
---

# Kattis `importspaghetti` - Import Spaghetti

Define the adjacency matrix for the graph as follows: `A[i][j]` is $1$ if `import j` is present in file `i.py`, and `INF` otherwise. `A[i][i]` is only 1 if a file imports itself, like `c.py` in sample input 1, and `INF` otherwise.

Running Floyd-Warshall on the adjacency matrix would trace all dependency chains. The dependency cycles can be found on the diagonal of the matrix. If `A[i][i]` is not infinity, then there exists a path such that `i.py` eventually imports itself, and thus a circular dependency exists. Thus if the minimum value on the diagonal is infinity, there are no circular dependencies and we can ship; otherwise, we take the shortest cycle (the lowest value among the diagonal).

Note that, like an actual Python file, the import statements can span multiple lines. We get the import statements line per line, cut the first 7 characters (which we always expect to be `import `), and feed the rest of the string to a `stringstream`.

To split the string by the commas, simply call `getline(ss, filename, ',')` which gets the string up until the next comma and stores it in the variable `filename`. We trim the left space if it ends up in `filename`. Storing all the imports in a set or vector, we can process all the imports at the end of a single file.

To print the path, recall that we can create a `parent` array to store the parent of a path; `parent[i][j]` is the vertex right before `j`, in the shortest path from `i` to `j`. Start from `v = parent[i][i]`, i.e. the vertex right before `i` in the cycle containing `i`. Repeatedly call `v = parent[i][v]` until `v = i` again, storing vertices in a stack. The path is simply the edges that are in the stack.
