# Bubble Sort

## Problem Statement
Classic algorithm — sort an array by repeatedly swapping adjacent out-of-order pairs.

- **Inputs:** `vector<int> arr` (mutated in place).
- **Output:** `arr` sorted ascending.
- **Valid answer:** non-decreasing order of all elements.
- **Edges:** empty; single element; already sorted; reverse sorted.

## Intuition
Each pass pushes the largest remaining element to the end ("bubbles up"). After `i` passes, the last `i` positions are final.

## Brute Force → Optimal
- **Brute:** nested adjacent compares every pass — always O(N²).
- **Optimal (for this algo):** early-exit when a pass makes no swaps — O(N) best on sorted input.

## Data Structure / Approach Justification
**Chosen:** in-place adjacent swaps with a `swapped` flag.

- **vs insertion sort:** fewer moves on nearly sorted data; insertion preferred in practice.
- **vs `std::sort`:** bubble is pedagogical only; never chosen for production.

## Logic Walkthrough
Outer loop runs up to `n-1` passes. Inner loop compares `j` with `j+1` up to the unsorted frontier. Swap if out of order; break outer when a full pass is clean.

## Dry Run
`[3,1,2]`:
- pass 0: swap `3,1` → `[1,3,2]`; swap `3,2` → `[1,2,3]`
- pass 1: no swaps → done

## Time & Space Complexity
Time **O(N²)** avg/worst, **O(N)** best with early-exit. Space **O(1)**. Why: up to N passes × O(N) compares (section 4).

## Trade-offs & Alternatives
Simple and stable teaching tool; many swaps make it slow. Prefer insertion for nearly sorted, `std::sort` otherwise.

## Common Mistakes / Edge Cases
Forgetting early-exit; writing `>=` and breaking stability; off-by-one on inner bound `n-i-1`.

## Interview Follow-ups / Variations
Is it stable? (Yes with `<`.) Cocktail shaker / odd-even variants.

## Tags
`sorting`, `bubble-sort`, `in-place`, `stable`, `difficulty:easy`
