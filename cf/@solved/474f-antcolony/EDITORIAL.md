---
platform: "cf"
code: "474f-antcolony"
title: "Ant Colony"

date-created: 2023-08-04
date-updated: 2025-01-28
status: incomplete

problem-link: "https://codeforces.com/contest/474/problem/F"
problem-description: "Count the number of ants to be eaten by a mole, given special conditions."
solution-summary: "Create a range GCD tree and a range minimum tree."
running-time: "$O(q \\log n)$"
solution-link: "https://github.com/blubits/solutions/blob/main/cf/%40solved/474f-antcolony/antcolony.cpp"
tags:
    - range-query
---

# Codeforces `474F` - Ant Colony

A few initial observations regarding the "battle" and "eating" routines:

- Given a set of ants with strengths $S$, the ant with the maximum possible number of battle points has strength equal to the GCD of $S$.
- We don't actually need to calculate the number of "battle points" for each ant in $S$. From above, we only need to count the number of ants whose strength is not equal to the GCD of $S$.
- Since the array is actually static, we could iterate through each ant and simply compare each's strength to the GCD of the entire set $S$. We can calculate the GCD of a subsequence in logarithmic time using a segment tree. Take note of the modifications needed to support the GCD in the segment tree.

A rough pseudocode of the solution is found below:

```python
input(n, s, t)
st = SegTreeGCD(s)
for i in range(t):
	input(l, r)
	g = st.range_query(l - 1, r - 1)
	num_ants = r - l + 1
	num_max_strength = count(s, l, r, lambda i: i == g)
	print(num_ants - count)
```

%% TODO range min mst %%
