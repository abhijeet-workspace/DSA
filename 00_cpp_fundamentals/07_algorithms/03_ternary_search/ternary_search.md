# Ternary Search

## Problem Statement

Search `target` in a sorted array by splitting the window into three segments via two midpoints.

## Intuition

Same discard idea as binary search, but two probes per step shrink toward ~2/3 of the range.

## Brute Force → Optimal

Linear O(N). Binary O(log₂ N) usually fewer comparisons in practice. Ternary is O(log₃ N) steps but **two** comparisons each step.

## Data Structure / Approach Justification

**Chosen:** iterative ternary partition on sorted `vector`.

- **vs binary search:** typically slower in practice due to extra comparison/cache miss.
- Ternary shines more for unimodal function optimization than discrete array search.

## Logic Walkthrough

Compute `mid1`, `mid2`. Match either. If target `< arr[mid1]` take left third; if `> arr[mid2]` take right third; else middle third.

## Dry Run

`{10..70}`, target `60`: midpoints hit 30 and 50 → go right of 50 → find 60.

## Time & Space Complexity

Time O(log N) (base 3 steps, 2 probes each). Space O(1).

## Trade-offs & Alternatives

Pedagogically useful; prefer binary search for arrays. Use ternary on unimodal continuous/discrete optimization.

## Common Mistakes / Edge Cases

- Wrong midpoint formulas causing infinite loops.
- Applying to unsorted data.
- Off-by-one when shrinking past `mid1`/`mid2`.

## Interview Follow-ups / Variations

Ternary search on unimodal function; compare constant factors vs binary.

## Tags

`ternary-search`, `divide-and-conquer`, `difficulty:medium`
