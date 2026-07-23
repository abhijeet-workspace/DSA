# Counting Sort

## Problem Statement
Classic algorithm — sort non-negative integers whose keys lie in a small range `[0..K]`.

- **Inputs:** `vector<int> arr`, `int maxVal` (= K).
- **Output:** `arr` sorted ascending (stable).
- **Valid answer:** non-decreasing; equal keys keep input order.
- **Edges:** empty; all equal; `K=0`; `maxVal ≫ N`.

## Intuition
Count occurrences, convert counts to ending positions via prefix sums, place elements from the back so equal keys stay stable.

## Brute Force → Optimal
- **Brute:** any comparison sort — O(N log N) ignoring small K.
- **Optimal:** O(N+K) when K is small — not comparison-based.

## Data Structure / Approach Justification
**Chosen:** count array of size K+1 + output buffer.

- **vs radix:** counting alone if K small; radix for multi-digit / large range.
- **vs comparison sorts:** wins only when K = O(N) or better.

## Logic Walkthrough
Increment `count[x]`. Prefix-sum `count`. Walk input right-to-left: `--count[arr[i]]` indexes the stable slot in `output`.

## Dry Run
`[2,0,2,1]` → counts `[1,1,2]` → prefix `[1,2,4]` → place back-to-front → `[0,1,2,2]`.

## Time & Space Complexity
Time **O(N+K)**. Space **O(N+K)**. Why: one pass count + one pass place + K-sized table (section 4).

## Trade-offs & Alternatives
Fast for small K; wasteful for huge or negative ranges without remapping. Prefer radix for wide integer keys.

## Common Mistakes / Edge Cases
Forward placement (breaks stability); off-by-one on count size; negatives without offset.

## Interview Follow-ups / Variations
Handle negatives via `min` offset. Stable vs unstable variants. Use as digit sort inside radix.

## Tags
`sorting`, `counting-sort`, `non-comparison`, `stable`, `difficulty:medium`
