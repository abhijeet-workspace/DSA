# Video Stitching

## 1. Problem Statement
[LeetCode 1326](https://leetcode.com/problems/video-stitching/) — clips `[start,end]` of a video; return min clips to cover `[0,time]`, or -1.

- **Inputs:** `clips`, `time`.
- **Output:** min clips or -1.
- **Valid answer:** jump-game greedy on intervals.
- **Edges:** cannot cover; one clip covers all; gaps.

## 2. Intuition
Sort by start. From current covered end, among clips that start ≤ end, pick the one that extends farthest — like jump game II.

## 3. Brute Force → Optimal
- **Brute:** DP on coverage — O(T·N) or subset.
- **Optimal:** sort + greedy — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** sort + two pointers / farthest.

- **vs DP:** fine when time small; greedy is cleaner.

## 5. Logic Walkthrough
While end < time: extend farthest among clips with start≤end; if farthest unchanged return -1; else end=farthest, ++ans.

## 6. Dry Run
clips cover 0..10 with **3** pieces (e.g. [0,2],[1,9],[8,10]).

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(1)**. Why: sort dominates (section 4).

## 8. Trade-offs & Alternatives
Classic interval covering / jump hybrid.

## 9. Common Mistakes / Edge Cases
Not sorting; returning 0 when time=0 edge; accepting gaps.

## 10. Interview Follow-ups / Variations
Jump Game II; Minimum Number of Taps to Open to Water a Garden.

## 11. Tags
`intervals`, `greedy`, `sorting`, `leetcode-1326`, `difficulty:medium`
