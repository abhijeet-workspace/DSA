# Height Checker

## 1. Problem Statement
[LeetCode 1051](https://leetcode.com/problems/height-checker/) — students stand in a line with heights `heights[i]`. A nondecreasing rearrangement is the expected order. Return how many indices differ from that expected array.

- **Inputs:** `vector<int> heights`.
- **Output:** count of positions where `heights[i] != expected[i]`.
- **Valid answer:** integer in `[0, n]`.
- **Edges:** already sorted; reverse sorted; all equal; duplicates.

## 2. Intuition
Expected order is just `heights` sorted ascending. Compare original vs sorted elementwise and count mismatches.

## 3. Brute Force → Optimal
- **Brute:** generate all permutations, pick the sorted one — absurd.
- **Optimal:** copy + `sort` + single compare pass — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** auxiliary sorted copy `expected`.

| Alternative | Why we skip it here |
|-------------|---------------------|
| Counting sort (heights in `[1..100]`) | Faster O(N+K) and valid; `std::sort` is clearer for the teaching point |
| In-place sort then compare | Destroys original unless copied anyway |

## 5. Logic Walkthrough
1. Copy `heights` → `expected`.
2. Sort `expected` ascending.
3. Count indices where values differ.
4. Return the count.

## 6. Dry Run
`[1,1,4,2,1,3]` → expected `[1,1,1,2,3,4]` → mismatches at indices 2,4,5 → `3`.

## 7. Time & Space Complexity
- **Time:** O(N log N) from sort; compare is O(N).
- **Space:** O(N) for the copy (or O(K) with counting sort).

## 8. Trade-offs & Alternatives
Constraints allow counting sort for O(N). Interview often accepts `sort` + compare; mention counting as a follow-up optimization.

## 9. Common Mistakes / Edge Cases
Sorting in place then comparing to itself (always 0); off-by-one on duplicate heights; assuming unique heights.

## 10. Interview Follow-ups / Variations
Return the expected array; minimum moves to sort; counting-sort version under small range.

## 11. Tags
`sorting`, `array`, `leetcode-1051`, `difficulty:easy`
