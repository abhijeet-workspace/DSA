# Max Chunks To Make Sorted II

## 1. Problem Statement
[LeetCode 768](https://leetcode.com/problems/max-chunks-to-make-sorted-ii/) — same as Max Chunks I, but `arr` may contain **duplicates** (not necessarily a permutation).

- **Inputs:** `vector<int> arr`.
- **Output:** maximum number of chunks.
- **Edges:** all equal → `n` chunks; strictly decreasing → 1.

## 2. Intuition
A cut after index `i` is valid iff every value in the left prefix is `≤` every value in the right suffix — i.e. `max(left) ≤ min(right)`. Equivalently maintain monotone chunk maxima: new value merges leftward until the chunk-max stack is nondecreasing.

## 3. Brute Force → Optimal
- **Brute:** try all partitions / compare to sorted — O(N²).
- **Optimal:** stack of chunk maxima — O(N) time, O(N) space.

## 4. Data Structure / Approach Justification
**Chosen:** decreasing-merge stack of running chunk maxes.

- **vs LC 769 running-max:** fails when duplicates / non-permutation break `max == i`.
- Still “home placement” in spirit: each value must not cross a cut into a region of smaller homes.

## 5. Logic Walkthrough
1. Empty stack of chunk maxima.
2. For each `x`: if `x ≥` top, push `x` as a new chunk max.
3. Else pop while top `> x`, remembering the largest popped max; push that max back (merged chunk).
4. Answer = stack size.

## 6. Dry Run
`[2,1,3,4,4]`:
- push 2; 1 merges → max 2; push 3; push 4; push 4 → 4 chunks.

## 7. Time & Space Complexity
- **Time:** O(N) amortized stack ops.
- **Space:** O(N) stack.

## 8. Trade-offs & Alternatives
Left-max / right-min arrays also O(N)/O(N) and may be clearer. Prefer stack when teaching merge of intervals.

## 9. Common Mistakes / Edge Cases
Using Max Chunks I’s `max == i` on non-permutations; forgetting to re-push the merged max; off-by-one on equal values (`≥` vs `>`).

## 10. Interview Follow-ups / Variations
Max Chunks I (769); pancake sorting; min swaps to sort with duplicates.

## 11. Tags
`cyclic-sort`, `stack`, `array`, `leetcode-768`, `difficulty:hard`
