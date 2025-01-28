---
platform: "kattis"
code: "3dprinter"
title: "3D Printed Statues"

date-created: 2024-06-29
date-updated: 2025-01-28
status: complete

problem_link: "https://open.kattis.com/problems/3dprinter"
problem_description: "Count the number of days required to print a certain amount of statues."
solution_summary: "Use a simple formula."
running_time: "$O(1)$"
solution_link: "https://github.com/blubits/solutions/blob/main/kattis/@solved/3dprinter/3dprinter.cpp"
tags:
    -
---

# Kattis `3dprinter` - 3D Printed Statues

If there is only one statue to print, we can just use the printer we already have to print, so it takes 1 day to print 1 statue.

Otherwise, note that we can make as much printers as we need in a short amount of time. In $d$ days, we can produce $2^d$ printers simply by having all existing printers print another printer everyday. So the best strategy is to produce printers until the number of printers meets or exceeds the number of statues, which takes $\left \lceil \log_2 n \right \rceil$ days. When we have enough printers, we spend the last day printing at least $n$ statues, which only takes 1 additional day.

Together, this means that the minimum number of days needed is $\left \lceil \log_2 n \right \rceil + 1$.
