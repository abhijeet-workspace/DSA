# Max Consecutive Ones

## 1. Problem Statement
[LeetCode 485](https://leetcode.com/problems/max-consecutive-ones/) — Given a binary array `nums`, return the maximum number of consecutive `1`s.

- **Inputs:** `vector<int> nums` with values in `{0,1}`.
- **Output:** Length of the longest run of ones.
- **Edges:** All zeros; all ones; single element; ones at both ends.

## 2. Intuition
Maintain a current streak that resets on `0`, and track the best streak seen.

## 3. Brute Force → Optimal
For each start index, extend while seeing ones — O(N²). One pass with a counter is O(N).

## 4. Data Structure / Approach Justification
**Chosen:** two integers `cur` / `best` while scanning left → right.

| Alternative | Why we skip it here |
|-------------|---------------------|
| Two pointers marking run endpoints | Valid window framing (topic 8); heavier than needed |
| Store all run lengths then max | Extra O(N) memory |

We use a plain single-pass counter on purpose — same answer as a window solution, without introducing the window vocabulary yet.

## 5. Logic Walkthrough
1. `cur = best = 0`.
2. For each `x`: if `1`, `++cur` and update `best`; else `cur = 0`.
3. Return `best`.

## 6. Dry Run
`[1,1,0,1,1,1]` → streaks 2 then 3 → answer `3`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Later, “Max Consecutive Ones III” (allow `k` flips) becomes a true sliding-window problem — different topic.

## 9. Common Mistakes / Edge Cases
Forgetting to update `best` inside the ones branch; not resetting on zero; empty array (constraints usually `n ≥ 1`).

## 10. Interview Follow-ups / Variations
Max consecutive zeros; longest run of any equal value; LC 1004 with flips.

## 11. Tags
`array`, `scan`, `leetcode-485`, `difficulty:easy`
