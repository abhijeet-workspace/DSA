# Circular Array Loop

## 1. Problem Statement
[LeetCode 457](https://leetcode.com/problems/circular-array-loop/) — given a circular array of non-zero integers (jump by `nums[i]` steps), return whether a cycle exists with length &gt; 1 and all moves in the same direction.

- **Inputs:** `vector<int> nums` (non-zero).
- **Output:** `bool`.
- **Valid answer:** `true` iff such a unidirectional cycle exists.
- **Edges:** self-loop (length 1 → false); direction change breaks cycle; negative jumps.

## 2. Intuition
Treat indices as an implicit linked list. Run Floyd from each start; reject if meet is a self-loop or signs disagree along the path.

## 3. Brute Force → Optimal
- **Brute:** simulate with a visited set per start — O(N²) time, O(N) space.
- **Optimal:** Floyd per component + mark visited starts — O(N) time, O(1) extra (mutate) or O(N) visited.

## 4. Data Structure / Approach Justification
**Chosen:** tortoise/hare on modular index jumps (same family as happy number / list cycle).

- **vs DFS color states:** also fine; Floyd emphasizes this topic’s pattern.
- **vs hash of path:** correct but heavier.

## 5. Logic Walkthrough
1. `next(i) = ((i + nums[i]) % n + n) % n`.
2. For each `i`, if not seen: slow/fast advance while same sign and not self-loop.
3. If slow == fast and not self-loop → true. Mark explored indices to skip.

## 6. Dry Run
`[2,-1,1,2,2]`: from index 0 → 2 → 3 → 0 cycle length 3, all positive → `true`.
`[-1,2]`: self-loops / length-1 → `false`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)** if marking in-place (or O(N) visited). Why: each index processed constantly often (section 4).

## 8. Trade-offs & Alternatives
Color DFS is clearer for “same direction” rules; Floyd transfers cycle-detection skill from lists.

## 9. Common Mistakes / Edge Cases
Accepting length-1 cycles; mixing forward/backward jumps; bad modular arithmetic on negatives.

## 10. Interview Follow-ups / Variations
Find duplicate number (Floyd on indices); linked list cycle II; happy number.

## 11. Tags
`array`, `fast-slow-pointers`, `cycle-detection`, `leetcode-457`, `difficulty:medium`
