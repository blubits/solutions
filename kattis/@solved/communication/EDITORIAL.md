---
platform: "kattis"
code: "communicaton"
title: "Jumbled Communication"

date-created: 2023-09-27
date-updated: 2025-01-28
status: complete

problem-link: "https://open.kattis.com/problems/communication"
problem-description: "Unscramble sent messages."
solution-summary: "Complete search, or precomputation."
running-time: "$O(q)$"
solution-link: "https://github.com/blubits/solutions/blob/main/kattis/@solved/communication/communication.cpp"
tags:
    - complete-search
---

# Kattis `communication` - Jumbled Communication

The actual input and output space is very small - only 256 possible messages - so simply brute-forcing all 256 possible messages and scrambling them to see if they match the input works well.

Since there are only a handful of valid values in we the input-output space, we can precompute all the possible answers, store them in an array, and simply refer to that array as we get the input in. The solution code below employs this technique.

A short note: care must be taken to ensure that the bitwise scramble operation works as intended. Do not forget to drop everything but the 8 least significant bits when performing `x ^ (x << 1)`. This can be done by `AND`ing the result with `(1 << 8) - 1`. In any case, if we only want the `n` least significant bits of a number, we can `AND` it with `n` ones on the left, or `(1 << n) - 1`.
