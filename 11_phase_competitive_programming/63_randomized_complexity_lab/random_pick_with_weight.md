# Random Pick with Weight (LC 528)

## 1. Problem Statement
Pick index i with probability `w[i]/sum(w)`.

- **Inputs:** weights array; repeated `pickIndex`.
- **Output:** indices distributed by weights.
- **Valid answer:** [LC 528](https://leetcode.com/problems/random-pick-with-weight/).
- **Edges:** single weight; large sums.
- **Link:** [LC 528](https://leetcode.com/problems/random-pick-with-weight/)

## 2. Intuition
Prefix sums + binary search on uniform random in `[1,total]`.

## 3. Brute Force → Optimal
- **Brute:** expand duplicates — memory heavy.
- **Prefix+bisect:** O(log N) pick.

## 4. Data Structure / Approach Justification
**Chosen:** prefix sums + `upper_bound`.

| Alternative | Note |
|-------------|------|
| Alias method | O(1) pick |
| Roulette wheel linear | O(N) |

## 5. Logic Walkthrough
1. Build prefix.
2. r = rand in 1..total.
3. lower_bound first prefix ≥ r.

## 6. Dry Run
weights `[1,3]` → index 1 about 75%.

## 7. Time & Space Complexity
Preprocess **O(N)**; pick **O(log N)**.

## 8. Trade-offs & Alternatives
Standard interview solution.

## 9. Common Mistakes / Edge Cases
0-based rand range; overflow on sums.

## 10. Interview Follow-ups / Variations
Alias method; updates to weights.

## 11. Tags
`prefix-sum`, `binary-search`, `lc-528`, `difficulty:medium`
