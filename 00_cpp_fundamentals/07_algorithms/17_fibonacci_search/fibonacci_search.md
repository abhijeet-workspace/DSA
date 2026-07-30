# Fibonacci Search

## Problem Statement

Find `target` in a **sorted** ascending array by splitting the search range using Fibonacci numbers instead of computing a midpoint via division.

## Intuition

Fibonacci splits (roughly golden-ratio proportions) discard a chunk of the array each step, similar to binary search, but comparisons use addition/subtraction of Fib indices.

## Brute Force → Optimal

Linear O(N). Fibonacci / binary O(log N). Historically useful when division is expensive; today binary search is the default.

## Data Structure / Approach Justification

**Chosen:** iterative Fibonacci-index narrowing on `vector<int>`.

- **vs binary:** same class of complexity; binary is simpler and preferred in interviews.
- Useful theoretically when avoiding division / relating to golden-ratio analysis.

## Logic Walkthrough

Find smallest `fibM = F(k) >= n`. While `fibM > 1`, probe index `min(offset + F(k-2), n-1)`. Shrink Fib triple left or right like binary search. Check last candidate when `F(k-1)` remains.

## Dry Run

`{10,22,35,40,45,50,80,82,85,90,100}`, target `85`: Fib window shrinks until probe hits 85 → return its index.

## Time & Space Complexity

Time O(log N). Space O(1).

## Trade-offs & Alternatives

Prefer binary search unless the prompt specifically asks for Fibonacci search.

## Common Mistakes / Edge Cases

- Forgetting the final `offset+1` check.
- Using on unsorted data.
- Empty array / single element.

## Interview Follow-ups / Variations

Jump search; golden-section search on unimodal functions; ternary search.

## Tags

`fibonacci-search`, `sorted-array`, `difficulty:medium`
