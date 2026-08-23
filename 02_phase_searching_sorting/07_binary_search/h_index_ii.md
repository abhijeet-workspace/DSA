# H-Index II

## Problem Statement
[LeetCode 275](https://leetcode.com/problems/h-index-ii/) — citations already sorted ascending; return the h-index (max h with ≥ h papers having ≥ h citations).

- **Inputs:** `vector<int> citations` sorted.
- **Output:** `int` h.
- **Valid answer:** largest h in `[0, n]` satisfying the definition.
- **Edges:** all zeros; all huge; n=1.

## Intuition
At index `mid`, there are `h = n-mid` papers with at least `citations[mid]` citations. Search the leftmost mid where `citations[mid] >= n-mid`.

## Brute Force → Optimal
- **Brute:** linear from the left — O(N).
- **Optimal:** binary search — O(log N).

## Data Structure / Approach Justification
**Chosen:** monotone predicate on sorted citations.

- **vs unsorted h-index (274):** would need sort or counting first
- **vs scanning from the right:** O(N)

## Logic Walkthrough
If `citations[mid] >= n-mid`, record h and move left to increase h.

## Dry Run
`[0,1,3,5,6]`, n=5: mid at 3 (value 5) gives h=2; mid at 2 (value 3) gives h=3.

## Time & Space Complexity
Time **O(log N)**. Space **O(1)**. Why: search indices.

## Trade-offs & Alternatives
Counting sort for unsorted input is O(N).

## Common Mistakes / Edge Cases
Using `citations[mid] >= mid`; mixing 0-based papers.

## Interview Follow-ups / Variations
H-Index I; peak index.

## Tags
`binary-search`, `leetcode-275`, `difficulty:medium`
