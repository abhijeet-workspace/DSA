# Advanced Stack Applications

## Problem Statement
Two monotonic-stack classics: (1) next greater element to the right (−1 if none); (2) stock span = consecutive prior days with price ≤ today (including today).

- **Inputs:** integer arrays `arr` / `prices`.
- **Output:** same-length result arrays.
- **Valid answer:** nearest greater on right; span lengths as defined.
- **Edges:** strictly decreasing (all −1 / all span 1); duplicates; single element.

## Intuition
Candidates that can never be “next greater” or span blockers are smaller/equal and can be discarded — maintain a monotonic stack.

## Brute Force → Optimal
- **Brute:** for each index scan right/left — O(N²).
- **Optimal:** monotonic stack — O(N) time, O(N) space.

## Data Structure / Approach Justification
**Chosen:** decreasing stack of values (NGE) / indices (span).

- **vs nested loops:** same answer, quadratic.
- **vs segment tree / sparse table:** overkill for nearest greater.

## Logic Walkthrough
**NGE (right→left):** pop ≤ current; top is next greater; push current.  
**Span (left→right):** pop indices with price ≤ today; span = `i+1` or `i - prev`.

## Dry Run
`[1,5,0,3,4,5]` → `[5,-1,3,4,5,-1]`. Prices `[100,80,60,70,60,75,85]` → spans `[1,1,1,2,1,4,6]`.

## Time & Space Complexity
Time **O(N)** (each index pushed/popped ≤ once). Space **O(N)**. Why: monotonic stack amortization (section 4).

## Trade-offs & Alternatives
Store indices vs values depending on whether width/distance is needed. Related: daily temperatures, next smaller.

## Common Mistakes / Edge Cases
Using `<` vs `<=` incorrectly; forgetting −1 default; off-by-one in span when stack empty.

## Interview Follow-ups / Variations
Next greater to the left; circular NGE; largest rectangle in histogram.

## Tags
`stack`, `monotonic-stack`, `next-greater`, `stock-span`, `difficulty:medium`
