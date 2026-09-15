# Find All Duplicates in an Array

## 1. Problem Statement
[LeetCode 442](https://leetcode.com/problems/find-all-duplicates-in-an-array/) — `nums` length `n` with values in `[1, n]`. Each appears once or twice. Return every value that appears twice. Prefer O(N) time and O(1) extra space.

- **Inputs:** `vector<int>& nums`.
- **Output:** `vector<int>` of duplicates (any order).
- **Edges:** no duplicates; all pairs; `n = 1`.

## 2. Intuition
Cyclic sort: value `v` belongs at index `v - 1`. While swapping into homes, if the home already holds `v`, that `v` is a duplicate — record it and advance.

## 3. Brute Force → Optimal
- **Brute:** hash frequency — O(N) time, O(N) space.
- **Sort:** adjacent equals — O(N log N).
- **Optimal (cyclic):** place-then-collect or swap-detect — O(N) time, O(1) extra.

## 4. Data Structure / Approach Justification
**Chosen:** cyclic placement — swap until `nums[i] == nums[nums[i]-1]`, then advance; after placement, collect `nums[i]` where `nums[i] != i + 1`.

| Alternative | Why not lead |
|-------------|--------------|
| Sign marking (topic 1 framing) | Same asymptotics; this folder teaches swap-to-home |
| Hash set | Extra O(N) space |

Same problem appears in fundamentals with negation marking; here the pedagogy is **index placement**.

## 5. Logic Walkthrough
1. For each `i`, while `nums[i] != nums[nums[i]-1]`, swap into home.
2. Else `++i`.
3. Scan: if `nums[i] != i + 1`, push `nums[i]` (the duplicate sitting in a wrong slot).

## 6. Dry Run
`[4,3,2,7,8,2,3,1]` → after placement, slots for 5 and 6 hold extras `2` and `3` → answer `{2,3}`.

## 7. Time & Space Complexity
- **Time:** O(N) — each index visited; each swap moves a value closer to home.
- **Space:** O(1) extra (plus output).

## 8. Trade-offs & Alternatives
Mutates input. Sign-marking also O(1) space without full placement. Use hash if mutation forbidden.

## 9. Common Mistakes / Edge Cases
Infinite swap when `nums[i] == nums[correct]` but still looping; collecting index instead of value; assuming sorted output.

## 10. Interview Follow-ups / Variations
Single duplicate (287); disappeared numbers (448); set mismatch (645). Contrast with topic-1 negation solution.

## 11. Tags
`cyclic-sort`, `array`, `duplicate`, `leetcode-442`, `difficulty:medium`
