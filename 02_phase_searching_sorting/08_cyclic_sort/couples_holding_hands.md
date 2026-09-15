# Couples Holding Hands

## 1. Problem Statement
[LeetCode 765](https://leetcode.com/problems/couples-holding-hands/) — `2N` people in a row; person `x`’s partner is `x XOR 1` (pairs `(0,1),(2,3),...`). A couple is together if they occupy seats `(2i, 2i+1)`. Return minimum swaps so every couple sits together.

- **Inputs:** `vector<int> row` — permutation of `0..2N-1`.
- **Output:** minimum swap count.
- **Edges:** already paired; `N = 1`.

## 2. Intuition
Each seat-pair slot should hold one couple. If `row[2i]`’s partner is not at `2i+1`, swap the partner into place. Couples form cycles of misplaced pairs; each swap reduces disorder by one — answer equals total couples minus number of couple-cycles (union-find view), or greedy seat fixes.

## 3. Brute Force → Optimal
- **Brute:** search all swap sequences — factorial.
- **Optimal:** greedy partner swap or union-find on couple cycles — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** position map + greedy swap partner into odd seat of each couple slot.

- **vs union-find:** same O(N) answer (`N - components`); swaps are more concrete.
- Pure cyclic-sort cousin: place partner at the “home” seat beside its match.

## 5. Logic Walkthrough
1. Build `pos[person] = index`.
2. For `i = 0,2,4,...`: partner = `row[i] XOR 1`.
3. If `row[i+1] != partner`, swap `row[i+1]` with `row[pos[partner]]`, update `pos`, `++swaps`.

## 6. Dry Run
`[0,2,1,3]`:
- slot 0: person 0 wants 1; swap index 1 (`2`) with index 2 (`1`) → `[0,1,2,3]`; 1 swap.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(N) for position array

## 8. Trade-offs & Alternatives
Union-find counts cycles without simulating swaps. Greedy is easier to verify on examples.

## 9. Common Mistakes / Edge Cases
Partner formula `x^1` vs `(x/2)*2` pair; swapping both seats unnecessarily; forgetting to update `pos` after swap.

## 10. Interview Follow-ups / Variations
Min swaps to sort a permutation (cycle count); Array Nesting (565); First Missing Positive placement.

## 11. Tags
`cyclic-sort`, `greedy`, `union-find`, `leetcode-765`, `difficulty:hard`
