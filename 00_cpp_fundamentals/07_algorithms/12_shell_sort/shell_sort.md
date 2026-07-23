# Shell Sort

## Problem Statement

Sort an array by insertion-sorting interleaved subarrays defined by a shrinking gap (`n/2, n/4, …, 1`).

## Intuition

Early large gaps move elements close to home quickly; final gap=1 is ordinary insertion on a nearly sorted array.

## Brute Force → Optimal

Plain insertion is O(N²). Shell’s gaps improve practical performance; exact bound depends on gap sequence (here ~O(N²) worst).

## Data Structure / Approach Justification

**Chosen:** Knuth-style halving gaps on `vector`.

- **vs insertion:** better on medium arrays.
- **vs O(N log N) sorts:** shell is simpler/in-place but weaker guarantees with this gap sequence.
- Ciura / Pratt sequences can improve asymptotics.

## Logic Walkthrough

For each `gap`, for `i=gap..n-1`, insertion-sort `temp=arr[i]` against positions `i-gap,i-2gap,…`.

## Dry Run

`{12,34,54,2,3}`, gap=2 sorts pairs; gap=1 finishes → `{2,3,12,34,54}`.

## Time & Space Complexity

With `gap/=2`, worst often cited O(N²); average better in practice. Space O(1).

## Trade-offs & Alternatives

In-place, not obviously stable with swaps/shifts across gaps. Good educational bridge from insertion to advanced sorts.

## Common Mistakes / Edge Cases

- Forgetting final `gap=1`.
- Wrong `j >= gap` condition.
- Assuming O(N log N) for every gap sequence.

## Interview Follow-ups / Variations

Compare gap sequences; Hibbard increments; when to prefer TimSort.

## Tags

`sorting`, `shell-sort`, `insertion`, `difficulty:medium`
