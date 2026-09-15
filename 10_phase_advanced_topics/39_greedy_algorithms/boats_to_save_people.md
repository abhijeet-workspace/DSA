# Boats to Save People

## 1. Problem Statement
[LeetCode 881](https://leetcode.com/problems/boats-to-save-people/) — each boat carries at most two people and weight ≤ `limit`; minimize boats to rescue everyone.

- **Inputs:** `people[i]` weights, `int limit`.
- **Output:** minimum number of boats.
- **Valid answer:** greedy pairing count.
- **Edges:** all alone (heavy); all pair; single person; `people[i]==limit`.

## 2. Intuition
Heaviest person always boards; pair with lightest if room remains — otherwise alone. Sorting enables two pointers.

## 3. Brute Force → Optimal
- **Brute:** try all pairings — exponential.
- **Optimal:** sort + two pointers — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** sorted array, `lo`/`hi` pointers.

- **vs multiset:** same greedy, heavier constants.
- **vs DP knapsack:** overkill; at most two per boat.

## 5. Logic Walkthrough
Sort ascending. While `lo<=hi`: if `people[lo]+people[hi]<=limit`, `++lo`. Always `--hi`, `++boats`.

## 6. Dry Run
`[3,2,2,1]`, limit 3: pair 1+2, then 2 alone, then 3 alone → **3** boats.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(1)** extra (sort). Why: sort dominates; each person boarded once (section 4).

## 8. Trade-offs & Alternatives
If already sorted, linear scan. Three-per-boat would need different packing.

## 9. Common Mistakes / Edge Cases
Forgetting `lo==hi` still needs a boat; pairing two heavies first; assuming three fit.

## 10. Interview Follow-ups / Variations
Boats of capacity `k`; variable boat limits.

## 11. Tags
`greedy`, `two-pointers`, `sorting`, `leetcode-881`, `difficulty:medium`
