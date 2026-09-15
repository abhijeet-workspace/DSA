# Random Pick Index (LC 398)

## 1. Problem Statement
Given array with duplicates, `pick(target)` returns a random index where `a[i]==target` uniformly.

- **Inputs:** array; multiple pick queries.
- **Output:** valid index distribution.
- **Valid answer:** [LC 398](https://leetcode.com/problems/random-pick-index/).
- **Edges:** unique target; all equal.
- **Link:** [LC 398](https://leetcode.com/problems/random-pick-index/)

## 2. Intuition
Reservoir on matching indices: count matches, replace with prob 1/count.

## 3. Brute Force → Optimal
- **Brute:** collect indices then pick.
- **Reservoir:** O(1) extra memory per pick if scanning.

## 4. Data Structure / Approach Justification
**Chosen:** linear scan reservoir for each pick (LC allows).

| Alternative | Note |
|-------------|------|
| Precompute map to indices | Faster picks, more memory |

## 5. Logic Walkthrough
1. Walk array; when value==target, ++cnt; with prob 1/cnt keep index.

## 6. Dry Run
`[1,2,3,3,3]`, pick(3) ∈ {2,3,4}.

## 7. Time & Space Complexity
**O(N)** per pick.

## 8. Trade-offs & Alternatives
Simple and space-light.

## 9. Common Mistakes / Edge Cases
Bias from wrong replacement prob.

## 10. Interview Follow-ups / Variations
Weighted indices; immutable precompute.

## 11. Tags
`reservoir`, `lc-398`, `randomized`, `difficulty:medium`
