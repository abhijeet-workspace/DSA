# Merge Triplets to Form Target Triplet

## 1. Problem Statement
[LeetCode 1899](https://leetcode.com/problems/merge-triplets-to-form-target-triplet/) — merge allowed triplets via component-wise max to reach `target`.

- **Inputs:** list of triplets; target `[x,y,z]`.
- **Output:** true iff `target` is achievable.
- **Valid answer:** any sequence of merges that yields target.
- **Edges:** triplets that overshoot one coordinate (must discard); exact match already present.

## 2. Intuition
Any triplet exceeding `target` in any coordinate can never help (max would permanently overshoot). Among the rest, take the max of each coordinate independently.

## 3. Brute Force → Optimal
- **Brute:** explore merge subsets — exponential.
- **Optimal:** one filter + three running maxima — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** skip invalid triplets; track `a,b,c` maxima.

- **vs simulation of merges:** unnecessary once independence is clear.
- **vs sorting:** no benefit.

## 5. Logic Walkthrough
For each triplet: if any coord `> target`, skip. Else update `a,b,c`. Succeed iff finals equal target.

## 6. Dry Run
`triplets=[[2,5,3],[1,8,4],[1,7,5]]`, `target=[2,7,5]`: skip `[1,8,4]` (8>7); max from others → `[2,7,5]` → true.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: coordinates merge independently under max (section 4).

## 8. Trade-offs & Alternatives
Proof that greedy filter is complete is the interview point; no real alternate structure needed.

## 9. Common Mistakes / Edge Cases
Keeping a triplet that exceeds one coord; requiring a single triplet to equal target.

## 10. Interview Follow-ups / Variations
Min merges count? Higher-dimensional vectors?

## 11. Tags
`greedy`, `array`, `difficulty:medium`
