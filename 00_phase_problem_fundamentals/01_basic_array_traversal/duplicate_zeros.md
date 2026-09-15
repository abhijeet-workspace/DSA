# Duplicate Zeros

## 1. Problem Statement
[LeetCode 1089](https://leetcode.com/problems/duplicate-zeros/) — Duplicate each zero in `arr` in-place, shifting the rest right. Elements beyond original length are dropped.

- **Inputs:** `vector<int>& arr` (modified in place).
- **Output:** None (array mutated).
- **Edges:** No zeros; all zeros; zero near the end (partial duplicate truncated).

## 2. Intuition
Forward insertion shifts repeatedly (O(N²)). Count zeros first, then write from the right so each value moves at most once into its final slot.

## 3. Brute Force → Optimal
- **Brute:** from left, on zero insert and `pop_back` — O(N²).
- **Optimal:** count zeros, then reverse write with expanded index `j` — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** two indices `i` (source) and `j` (destination in the virtual expanded array), scanning right → left.

| Alternative | Why we acknowledge but do not lead with it |
|-------------|-----------------------------------------------|
| Two-pointer “read/write heads” framed as a window | Same mechanics; vocabulary belongs to topic 7 |
| Extra `vector` copy then truncate | O(N) space; violates in-place constraint spirit |

A two-pointer solution also works and is often how people name this. We still present it as **direct index placement** (`i`/`j` as positions in an expanded layout) because this topic builds single-pass index fluency before two pointers are formally introduced in topic 7.

## 5. Logic Walkthrough
1. Count zeros in `arr`.
2. Set `i = n-1`, `j = n + zeros - 1`.
3. While `i ≥ 0`: copy `arr[i]` to `arr[j]` if `j` is in range; if `arr[i]` is zero, also write an extra zero one slot left (`--j`).
4. Decrement `i` and `j` each step.

## 6. Dry Run
`[1,0,2,3,0,4,5,0]`, `n=8`, `zeros=3` → `j` starts at 10; after reverse writes, visible prefix becomes `[1,0,0,2,3,0,0,4]`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) extra

## 8. Trade-offs & Alternatives
Extra-array decode is simpler to explain in interviews if in-place is not required. In-place reverse write is the classic constraint version.

## 9. Common Mistakes / Edge Cases
Writing left → right and overwriting unread values; forgetting truncated duplicate when `j >= n`; off-by-one on `j = n + zeros - 1`.

## 10. Interview Follow-ups / Variations
Duplicate a given value `k` times; remove zeros in-place (related to Move Zeroes — topic 7).

## 11. Tags
`array`, `in-place`, `indexing`, `leetcode-1089`, `difficulty:easy`
