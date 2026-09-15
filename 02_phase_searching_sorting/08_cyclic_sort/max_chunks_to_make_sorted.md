# Max Chunks To Make Sorted

## 1. Problem Statement
[LeetCode 769](https://leetcode.com/problems/max-chunks-to-make-sorted/) — `arr` is a permutation of `0..n-1`. Split into maximum chunks so that sorting each chunk independently sorts the whole array.

- **Inputs:** `vector<int> arr` permutation of `0..n-1`.
- **Output:** maximum chunk count.
- **Edges:** identity → `n` chunks; reverse order → 1 chunk.

## 2. Intuition
Value `v` must end at index `v`. A chunk ending at `i` is valid only if every value `≤ i` has appeared in `0..i` — equivalently, `max(arr[0..i]) == i`. Each such cut is a “sorted prefix closed under home indices.”

## 3. Brute Force → Optimal
- **Brute:** try all partitions — exponential.
- **Optimal:** single pass tracking running max — O(N)/O(1).

## 4. Data Structure / Approach Justification
**Chosen:** running-max cut rule — cyclic-sort’s “value equals home index” applied to prefixes.

- **vs sorting each candidate chunk:** slower and unnecessary for permutations.
- Related to placement: after cyclic sort, homes are fixed; chunks must not leave homes outside.

## 5. Logic Walkthrough
1. `mx = 0`, `chunks = 0`.
2. For each `i`, `mx = max(mx, arr[i])`; if `mx == i`, `++chunks`.
3. Return `chunks`.

## 6. Dry Run
`[1,0,2,3,4]`:
- `i=0` mx=1 ≠ 0
- `i=1` mx=1 == 1 → chunk
- `i=2,3,4` each mx==i → 4 chunks total.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Fails for duplicates — need Max Chunks II (768). Stack-based “next greater” also works but is heavier.

## 9. Common Mistakes / Edge Cases
Using `min` instead of `max`; applying to non-permutations; off-by-one on `mx == i`.

## 10. Interview Follow-ups / Variations
Max Chunks II (768); pancake sorting; min swaps to sort a permutation (cycle count).

## 11. Tags
`cyclic-sort`, `array`, `permutation`, `leetcode-769`, `difficulty:medium`
