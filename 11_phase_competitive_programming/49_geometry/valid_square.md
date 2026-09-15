# Valid Square (LC 593)

## 1. Problem Statement
[LeetCode 593 — Valid Square](https://leetcode.com/problems/valid-square/): decide if four points form a square.

- **Inputs:** four points.
- **Output:** bool.
- **Edges:** degenerate zero distances.

## 2. Intuition
Among 6 distances: 4 equal sides + 2 equal longer diagonals (or sort unique distances).

## 3. Brute Force → Optimal
- **Brute:** check all permutations angles.
- **Optimal:** O(1) distance multiset.

## 4. Data Structure / Approach Justification
**Chosen:** compute 6 squared distances; validate pattern.

**Pedagogy:** metric geometry without floats.

## 5. Logic Walkthrough
Collect dist²; must have nonzero; exactly two diagonals equal and larger; four sides equal.

## 6. Dry Run
Unit square corners → true.

## 7. Time & Space Complexity
Time **O(1)**.

## 8. Trade-offs & Alternatives
Rhombus not square if diagonals unequal.

## 9. Common Mistakes / Edge Cases
Zero-length; float sqrt unnecessary.

## 10. Interview Follow-ups / Variations
Regular polygon checks.

## 11. Tags
`geometry`, `leetcode-593`, `difficulty:medium`
