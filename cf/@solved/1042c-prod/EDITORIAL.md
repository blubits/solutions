---
platform: "cf"
code: "1042c-prod"
title: "Array Product"

date-created: 2025-01-29
date-updated: 2025-01-29
status: complete

problem-link: "https://codeforces.com/problemset/problem/1042/C"
problem-description: "Determine an optimal set of operations to get the maximum product."
solution-summary: "Merge all undesirable elements, delete the merge, then merge the rest."
running-time: "$O(n)$"
solution-link: "https://github.com/blubits/solutions/blob/main/cf/%40solved/1042c-prod/prod.cpp"
tags:
    - constructive-algorithm
---

# Codeforces `1042C` - Array Product

Let's deal with a simpler problem than what is asked for.

> Given an list $L$, determine the subset $L'$ of $L$ that will give the maximum product.

Obviously, $L'$ must contain all positive elements of $L$. Since the product of two negative numbers is positive, then $L'$ must contain an even number of negative numbers. If there are an odd number of negative numbers, we exclude the one least in magnitude, i.e. the largest negative number.

Thus, to get the maximum product of $L$, we have to delete everything in $L$ that is zero; if $L$ has an odd number of negative numbers, we must delete that too.

Since we only have a single delete operation available to us, we have to merge everything in $L \setminus L'$, then delete the merged element. We can then proceed to merge everything in $L$.

Depending on the method you choose to implement this, pay attention to some edge cases:
1. all positive values or all negative values, with $n$ being even - in both cases, nothing should be deleted;
2. all negative values with $n$ being odd;
3. all zero values;
4. a mix of negatives and positives but with no zero-value.
