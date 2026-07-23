# Longest Substring Without Repeating Characters

## 1. Problem Statement
Return the length of the longest substring with all unique characters.

- **Input:** string `s`
- **Output:** int length
- **Valid answer:** max length of any contiguous unique window
- **Edges:** empty; all same; all unique; spaces/symbols

## 2. Intuition
Expand right; when a duplicate is inside the current window, move left past its previous index.

## 3. Brute Force → Optimal
- **Brute:** check all substrings — O(N²)/O(N³).
- **Optimal:** sliding window + last-seen index map — O(N).

## 4. Data Structure / Approach Justification
`unordered_map<char,int>` last index; two pointers `left`/`right`.

| Alternative | Why it loses here |
|-------------|-------------------|
| Set + while-erase | Correct but more ops per shrink |
| Nested uniqueness checks | Quadratic |

## 5. Logic Walkthrough
1. For each `right`, if `c` seen at `≥ left`, set `left = last[c]+1`.
2. Update `last[c] = right`.
3. Track `best = max(best, right−left+1)`.

## 6. Dry Run
`"abcabcbb"` — window grows `abc` (3); next `a` jumps left → best stays **3**.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(min(N, alphabet))
- Why: each index visited once; map stores distinct chars in window history.

## 8. Trade-offs & Alternatives
Index map jumps left in O(1). Set version is slightly simpler to write.

## 9. Common Mistakes / Edge Cases
Moving left by 1 instead of `last+1`; updating `last` before checking; empty → 0.

## 10. Interview Follow-ups / Variations
Return the substring; at most k distinct (LC 340)?

## 11. Tags
`sliding-window`, `hash-map`, `leetcode-3`, `medium`
