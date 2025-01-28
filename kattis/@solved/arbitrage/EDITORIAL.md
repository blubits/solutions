---
platform: "kattis"
code: "arbitrage"
title: "Arbitrage?"

date-created: 2023-10-26
date-updated: 2025-01-28
status: complete

problem_link: "https://open.kattis.com/problems/arbitrage>"
problem_description: "Detect arbitrage given a sequence of exchange rates."
solution_summary: "Modify Floyd-Warshall's algorithm."
running_time: "$O(n^3)$"
solution_link: "https://github.com/blubits/solutions/blob/main/kattis/@solved/arbitrage/arbitrage.cpp"
tags:
    - graph-theory
    - shortest-paths
---

# Kattis `arbitrage` - Arbitrage?

> [!info]- Sidenote: What is arbitrage?
> **Arbitrage** is the practice of profiting from a series of exchanges or transactions through repeated conversion.
>
> In the particular context of world currencies, the existence of arbitrage opportunities can mean that any individual or organization can make profits simply by exchanging a specific sequence of currencies. This can be done within milliseconds through computers and can also be repeated over and over, essentially creating money out of thin air. Currency exchanges seek to detect and remove arbitrage opportunities to avoid this possibility.

We can model the currency exchange market as a graph, where each vertex is a currency and an edge between two currencies represents an exchange opportunity. Note that for this particular problem, edges are directed, since the exchange rate is defined in the input as going in a single direction. Define the weight of the vertex as the exchange rate; i.e. $w(a, b)$ is how many $b$s can be recieved by exchanging a single unit of $a$. For example, `CZK EUR 25:1` means that $w(CZK, EUR) = \frac{1}{25} = 0.04$, since one CZK can be exchanged for 0.04 EUR based on the input. Note that $w(a, a) = 1$ by default, while $w(a, b)$ is zero if we cannot change currency $a$ for currency $b$.

Express this graph as an adjacency matrix. We can run Floyd-Warshall on the graph, noting that the distance is multiplicative, not additive, since we are dealing with exchange rates. We are seeking profit, so we try to find the *maximum* "distance" between any two nodes $a, b$, or the maximum number of $b$s we can get by exchanging a single unit of $a$.

An arbitrage opportunity is thus defined as an instance where $w(a, a) > 1$, that is, we can exchange 1 unit of $a$ for $>1$ unit of $a$ simply by going through a sequence of currency exchanges.
