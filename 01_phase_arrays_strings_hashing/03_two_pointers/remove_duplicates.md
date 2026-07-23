# Remove Duplicates from Sorted Array

## 1. Problem Statement
In-place compact a sorted array so the first `k` slots are unique values in order; return `k`.

- **Input:** sorted non-decreasing `nums`
- **Output:** `k`; `nums[0..k)` unique
- **Edges:** empty; all unique; all equal

## 2. Intuition
Same-direction pointers: `slow` is last written unique; `fast` scans ahead.

## 3. Brute Force → Optimal
- **Brute:** copy uniques to new vector — O(N) space.
- **Optimal:** overwrite in place — O(1) extra.

## 4. Data Structure / Approach Justification
Two indices on sorted array (order guarantees duplicates are adjacent).

| Alternative | Why it loses here |
|-------------|-------------------|
| `std::unique` + erase | Same idea; hide the pointer lesson |
| Hash set | Unneeded; breaks “sorted + O(1) space” |

## 5. Logic Walkthrough
1. `slow=0`; scan `fast` from 1.
2. On mismatch, `++slow` and copy `nums[fast]`.
3. Return `slow+1`.

## 6. Dry Run
`[1,1,2,2,3]`: write at 1→2, at 2→3 → prefix `[1,2,3]`, k=3.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) auxiliary

## 8. Trade-offs & Alternatives
LC 80 allows each value at most twice — same pattern with a count.

## 9. Common Mistakes / Edge Cases
Forgetting empty check; returning `slow` instead of `slow+1`; assuming unsorted input.

## 10. Interview Follow-ups / Variations
Remove element (LC 27); allow ≤2 copies (LC 80).

## 11. Tags
`two-pointers`, `in-place`, `sorted-array`, `leetcode-26`
