# Algorithm Design Techniques

## 1. Problem Statement
Demonstrate six core algorithmic paradigms on classic problems in one runnable file.

- **Input:** sample arrays / activities / knapsack items / board size N
- **Output:** max subarray sums; inversion count; selected activities; knapsack value; N-Queens solution counts; B&B knapsack value
- **Valid answer:** brute and Kadane agree; DP and B&B knapsack agree; N-Queens counts match known sequence for N=1..8
- **Edge cases:** all-negative max subarray; empty activity list; capacity 0; N=1 queens

## 2. Intuition
Almost every DSA problem is one (or a mix) of: try all, split-and-combine, local greedy choice, overlapping DP states, constraint backtrack, or bound-pruned search. Matching the problem’s structure to a paradigm is the design step before coding.

## 3. Brute Force → Optimal
| Problem | Brute | Better |
|---------|-------|--------|
| Max subarray | all pairs O(n²) | Kadane O(n) |
| Inversions | all pairs O(n²) | merge-count O(n log n) |
| Activity select | enumerate subsets | earliest-finish greedy |
| 0/1 knapsack | 2ⁿ subsets | DP O(nW) / B&B pruning |
| N-Queens | N! placements | backtracking with safety checks |

## 4. Data Structure / Approach Justification
**Chosen:** one minimal demo per paradigm (vectors, 1D DP, column array for queens, ratio-sorted items for B&B).

| Alternative | Why it loses here |
|-------------|-------------------|
| Only theory tables | No executable confirmation |
| Full production solvers | Too much code for paradigm contrast |
| Always DP for knapsack | Misses when B&B/greedy apply |

Trade-off: demos share globals (`nQueensCount`, `bestValue`) for brevity — fine for teaching, not for libraries.

## 5. Logic Walkthrough
1. **Brute / Kadane** — expand all endings vs keep `cur`/`best` running maxima.
2. **D&C inversions** — count left, right, then split inversions while merging.
3. **Greedy activities** — sort by end; take next that starts ≥ last end.
4. **DP knapsack** — reverse 1D update so each item is used at most once.
5. **Backtracking queens** — place row-by-row; prune column/diagonal conflicts; undo.
6. **Branch & bound** — fractional upper bound; skip branches that cannot beat `bestValue`.

## 6. Dry Run
Max subarray `{-2,1,-3,4,-1,2,1,-5,4}` → best `6` from `[4,-1,2,1]`.

Inversions `{5,4,3,2,1}` → `10`.

Knapsack `wt=[2,3,4,5]`, `val=[3,4,5,6]`, `W=8` → value `10`.

N-Queens N=4 → `2` solutions; N=8 → `92`.

## 7. Time & Space Complexity
| Technique | Demo | Time | Space |
|-----------|------|------|-------|
| Brute | max subarray | O(n²) | O(1) |
| Optimal scan | Kadane | O(n) | O(1) |
| D&C | inversions | O(n log n) | O(n) |
| Greedy | activities | O(n log n) sort | O(1) extra |
| DP | knapsack | O(nW) | O(W) |
| Backtracking | N-Queens | O(N!) worst | O(N) |
| B&B | knapsack | O(2ⁿ) worst, pruned | O(n) stack |

## 8. Trade-offs & Alternatives
- D&C when subproblems are independent; DP when they overlap.
- Greedy needs a proof (exchange / matroid); otherwise use DP.
- Backtracking for feasibility; B&B adds bounds for optimization.

## 9. Common Mistakes / Edge Cases
- Using greedy without correctness argument
- Forward 1D knapsack loop (reuses item — unbounded)
- Forgetting undo in backtracking
- Weak B&B bounds → no pruning

## 10. Interview Follow-ups / Variations
- When is greedy activity selection wrong if you sort by start instead of finish?
- Space-optimize 2D knapsack further; recover chosen items?
- How does α-β pruning relate to branch & bound?

## 11. Tags
`algorithm-paradigms`, `greedy`, `dp`, `backtracking`, `divide-conquer`, `branch-and-bound`, `difficulty:medium`
