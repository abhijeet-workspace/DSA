# Linear Search (Interactive)

## Problem Statement
Find whether a user-entered key exists in a fixed array and report its index.

- **Input:** integer `searchKey`
- **Array:** `{10,20,30,40,50}`
- **Output:** index or not-found message
- **Edge cases:** missing key → `-1` path; duplicates would return first (none here)

## Intuition
Unsorted array ⇒ no binary search; must examine elements until a match.

## Brute Force → Optimal
This *is* the brute-force search. Optimal for unsorted data without auxiliary indexes; sorting first would be O(N log N) prep — worse for one query.

## Data Structure / Approach Justification
Raw C array is fine for a fixed demo. `std::vector` if size were dynamic. `std::unordered_set` wins for many membership queries, not for teaching index-of in an array.

## Logic Walkthrough
1. Read `searchKey`.
2. Loop `i` over `[0,n)`.
3. On match set `onIndex=i` and `break`.
4. Print based on sentinel.

## Dry Run
Key `30` → hit at `i=2`. Key `99` → `onIndex` stays `-1`.

## Time & Space Complexity
**Time:** O(N) worst. **Space:** O(1).

## Trade-offs & Alternatives
Binary search if sorted; hashing for pure membership.

## Common Mistakes / Edge Cases
Continuing after a hit (returns last duplicate); forgetting sentinel init.

## Interview Follow-ups / Variations
Return all matching indices; early exit vs full scan metrics.

## Tags
`topic: searching` · `pattern: linear-scan` · `difficulty: easy`
