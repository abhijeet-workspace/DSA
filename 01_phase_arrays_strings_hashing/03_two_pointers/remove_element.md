# Remove Element

## Problem Statement
[LeetCode 27](https://leetcode.com/problems/remove-element/) — remove all occurrences of `val` in-place; return new length `k`. First `k` elements may be any order of the kept values.

- **Inputs:** `vector<int>& nums`, `int val`.
- **Output:** `k`; `nums[0..k)` contains non-`val` elements.
- **Edges:** empty; all `val`; no `val`.

## Intuition
Same-direction write pointer: copy each non-`val` forward.

## Brute Force → Optimal
- **Brute:** build new vector — O(N) space.
- **Optimal:** overwrite in place — O(1) extra.

## Data Structure / Approach Justification
**Chosen:** two pointers (write/read) — sibling of Remove Duplicates (26) and Move Zeroes (283).

| Alternative | Why it loses here |
|-------------|-------------------|
| Erase while iterating | O(N²) shifts |
| Partition / `remove` | Same idea; hide the pointer lesson |

## Logic Walkthrough
`write=0`; for each `x`, if `x != val` write and `++write`. Return `write`.

## Dry Run
`nums=[3,2,2,3]`, `val=3` → write `2,2` → **k=2**.

## Time & Space Complexity
Time **O(N)**. Space **O(1)** auxiliary.

## Trade-offs & Alternatives
Two-pointer from ends can reduce writes when `val` is rare (swap with end).

## Common Mistakes / Edge Cases
Returning index of last write instead of count; assuming order must be preserved beyond “any order of survivors”.

## Interview Follow-ups / Variations
Remove Duplicates (26); Move Zeroes (283).

## Tags
`two-pointers`, `in-place`, `leetcode-27`, `difficulty:easy`
