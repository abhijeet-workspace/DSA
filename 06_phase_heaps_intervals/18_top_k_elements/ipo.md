# IPO

## Problem Statement
[LeetCode 502](https://leetcode.com/problems/ipo/) — start with capital `w`. Complete at most `k` distinct projects. Project `i` needs `capital[i]` and yields `profits[i]` (added to `w`). Maximize final capital.

- **Inputs:** `k`, `w`, `profits`, `capital`.
- **Output:** maximized capital after ≤ `k` projects.
- **Valid answer:** best greedy sequence under capital constraints.
- **Edges:** `k=0`; nothing affordable; all free capital 0; `k` larger than n.

## Intuition
Always take the highest-profit project currently affordable. Sort projects by capital; as `w` grows, unlock more into a max-heap of profits; pick top up to `k` times.

## Brute Force → Optimal
- **Brute:** try all subsets of size ≤ k with feasibility checks — exponential.
- **Optimal:** sort + two heaps / one heap — O(N log N).

## Data Structure / Approach Justification
**Chosen:** sort by capital + max-heap of unlocked profits.

- **vs DP knapsack:** capital values can be large; not suitable.
- **vs always scanning remaining projects:** O(kN).

## Logic Walkthrough
Sort `(capital, profit)`. For up to `k` rounds: push all projects with `capital <= w` into max-heap; if empty break; else add top profit to `w`.

## Dry Run
`k=2,w=0`, profits `[1,2,3]`, capital `[0,1,1]`: unlock profit 1 → take it → w=1; unlock 2 and 3 → take 3 → w=4.

## Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: sort + each project enters heap once (section 4).

## Trade-offs & Alternatives
Min-heap of locked projects by capital is equivalent to sorting then scanning with a pointer.

## Common Mistakes / Edge Cases
Requiring capital after profit incorrectly; doing more than k; picking by capital instead of profit among affordable.

## Interview Follow-ups / Variations
Maximum projects with deadline; task scheduling with profit; IPO with project reuse forbidden (already).

## Tags
`heap`, `greedy`, `sorting`, `leetcode-502`, `difficulty:hard`
