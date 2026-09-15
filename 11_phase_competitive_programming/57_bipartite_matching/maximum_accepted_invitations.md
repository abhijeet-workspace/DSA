# Maximum Accepted Invitations

## 1. Problem Statement
[LeetCode 1820](https://leetcode.com/problems/maximum-number-of-accepted-invitations/) (premium) — `grid[i][j]=1` means boy `i` can invite girl `j`; max invitations with one each.

- **Inputs:** binary grid.
- **Output:** maximum matching size.
- **Edges:** empty grid; identity perfect.

## 2. Intuition
Classic bipartite matching left=boys, right=girls.

## 3. Brute Force → Optimal
- **Brute:** subsets.
- **Optimal:** Kuhn/Hopcroft.

## 4. Data Structure / Approach Justification
**Chosen:** Kuhn DFS augmenting paths.

| Alternative | Note |
|-------------|------|
| Hopcroft–Karp | Faster large |
| Max flow | Equivalent |

## 5. Logic Walkthrough
Build adj from grid; run Kuhn.

## 6. Dry Run
3×3 sample → matching `3`.

## 7. Time & Space Complexity
Time **O(VE)**. Space **O(V+E)**.

## 8. Trade-offs & Alternatives
Direct LC packaging of `kuhn_maximum_matching`.

## 9. Common Mistakes / Edge Cases
0-based vs 1-based mix; reusing girls.

## 10. Interview Follow-ups / Variations
Weighted invitations.

## 11. Tags
`leetcode-1820`, `bipartite-matching`, `kuhn`, `difficulty:medium`
