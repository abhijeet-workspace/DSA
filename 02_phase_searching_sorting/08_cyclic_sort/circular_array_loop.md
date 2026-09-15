# Circular Array Loop

## 1. Problem Statement
[LeetCode 457](https://leetcode.com/problems/circular-array-loop/) — circular array; from `i` jump `nums[i]` steps (forward if positive, backward if negative). Return whether a cycle exists with length `> 1` and all jumps in the **same direction**.

- **Inputs:** `vector<int> nums` (nonzero).
- **Output:** `true` if a valid cycle exists.
- **Edges:** self-loop length 1; mixed directions; single element.

## 2. Intuition
Each index has out-degree 1 → functional graph of cycles with trees feeding in. Detect cycles via Floyd (slow/fast) per start, rejecting length-1 and direction changes. Mark failed paths visited.

## 3. Brute Force → Optimal
- **Brute:** simulate from every index with a set — O(N²).
- **Optimal:** Floyd + path marking — O(N) time, O(1) extra (mutate) or O(N) visited.

## 4. Data Structure / Approach Justification
**Chosen:** slow/fast cycle detection on the jump graph with same-sign constraint.

- **vs DFS coloring:** also O(N); Floyd stays closer to “follow the cycle” pedagogy.
- Fits this folder as **index cycle following**, not value-to-home swaps.

## 5. Logic Walkthrough
1. Define `next(i) = ((i + nums[i]) % n + n) % n`.
2. From each unvisited `i`, run slow/fast while jumps keep the sign of `nums[i]`.
3. If `slow == fast` and `next(slow) != slow`, valid cycle → true.
4. Mark the path as dead (e.g. set jumps to 0) so later starts skip it.

## 6. Dry Run
`[2,-1,1,2,2]`: start at 0 → `0→2→3→0` same direction, length 3 → true.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) if mutating / O(N) with visited

## 8. Trade-offs & Alternatives
DFS with path stack is often clearer in interviews. Floyd saves space but needs careful rejection of length-1 loops.

## 9. Common Mistakes / Edge Cases
Accepting self-loops; allowing sign flips mid-cycle; wrong modular arithmetic for negative jumps.

## 10. Interview Follow-ups / Variations
Array Nesting (565); Linked List Cycle (141); Happy Number (202) — Floyd without direction rules.

## 11. Tags
`cyclic-sort`, `array`, `floyd`, `cycle-following`, `leetcode-457`, `difficulty:medium`
