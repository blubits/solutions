---
platform: "kattis"
code: "robotsonagrid"
title: "Robots on a Grid"

date-created: 2023-11-14
date-updated: 2025-01-28
status: complete

problem-link: "https://open.kattis.com/problems/robotsonagrid"
problem-description: "Count the number of paths a robot can take between two ends of a grid."
solution-summary: "DFS on a state DP graph."
running-time: "$O(n^2)$"
solution-link: ""
tags:
    - dp
    - dag
    - graph-theory
---

# Kattis `robotsonagrid` - Robots on a Grid

In pseudocode:

```python
if not path_exists():
	print("INCONCEIVABLE")
else:
	count_paths()
	if num_paths[n - 1][n - 1] == 0:
		print("THE GAME IS A LIE")
	else:
		print(num_paths[n - 1][n - 1])
```

`path_exists()` can be done by a simple depth-first search on a graph, while `count_paths()` is a straightforward implementation of the DP recurrence in counting paths on a DAG. Note:

- For DFS, treat the grid as a graph where each cell is connected to its non-wall neighbors on all edges of the graph.
- For the DP recurrence, only treat the bottom and right cells as the neighbors of a cell, because the robot can only go rightwards and downwards. No need to calculate the toposort: simply iterate between the cell from left to right, top to bottom.
