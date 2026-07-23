# Counting Sort

## Problem Statement

Sort integers when values lie in a modest range `[min,max]` by counting occurrences and emitting in order.

## Intuition

If you know how many values are `< x`, you know where `x` belongs without comparisons.

## Brute Force → Optimal

Comparison sorts need Ω(N log N). Counting is O(N+K) when range K is small.

## Data Structure / Approach Justification

**Chosen:** offset count array sized `max-min+1` + output buffer (stable reverse fill).

- **vs comparison sorts:** wins when K = O(N) or better.
- **vs radix:** counting is the digit subroutine inside radix.
- Fails / wastes memory when K ≫ N.

## Logic Walkthrough

Find min/max; tally `count[x-min]`; prefix sums; place from right for stability; copy `output` back.

## Dry Run

`{4,2,2,8,3,3,1}` → min1 max8 → frequencies → stable emit → `{1,2,2,3,3,4,8}`.

## Time & Space Complexity

Time O(N+K). Space O(N+K).

## Trade-offs & Alternatives

Linear-time for small ranges; not comparison-based; needs integer keys (or mapped keys).

## Common Mistakes / Edge Cases

- Ignoring negative numbers (offset by `min_val`).
- Forward placement breaking stability.
- Huge K causing memory blowups.

## Interview Follow-ups / Variations

Counting sort for radix digit; map enum/char keys.

## Tags

`sorting`, `counting-sort`, `non-comparison`, `difficulty:medium`
