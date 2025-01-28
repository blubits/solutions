---
platform: "kattis"
code: "dreamer"
title: "Dreamer"

date-created: 2023-09-27
date-updated: 2025-01-28
status: complete

problem_link: "https://open.kattis.com/problems/dreamer"
problem_description: "Count valid dates containing all digits."
solution_summary: "Complete search."
running_time: "$O(8! \\cdot n)$"
solution_link: "https://github.com/blubits/solutions/blob/main/kattis/@solved/dreamer/dreamer.cpp"
tags:
    - complete-search
---

# Kattis `dreamer` - Dreamer

The problem is fairly straightforward: simply run through every possible permutation of digits and count the number of valid dates on or after `2000-01-01`. `next_permutation` on a `vector<int>` of digits would be the easiest way to do this. Each date has eight digits, so there are at most $8!=40320$ permutations we would need to run through; there are at most 50 sets of digits, so complete search would be an acceptable solution to a problem.

To ensure that we iterate through each permutation lexicographically - in order from earlier to later dates - we assure the following: first, the permutation should be sorted for `next_permutation` to work fully, and second, the permutation must be read not as a `DD-MM-YYYY` date, but an `YYYY-MM-DD` date. This way, the first valid date is also the earliest valid date, which makes the required output a lot easier to achieve.

The most likely source of error would be the valid date checker. Date checkers, while useful in practical applications, is typically a time-waster in competitive programming contests. One may take inspiration from the code below for ways on how to implement a date validator in a fast, debuggable manner.
