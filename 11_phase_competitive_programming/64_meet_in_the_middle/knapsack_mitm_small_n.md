# Knapsack via MITM (Small N)

## 1. Problem Statement
0/1 knapsack when `n≤40` but capacities/values are huge (DP on capacity impossible).

- **Inputs:** weights, values, capacity W.
- **Output:** max value with weight ≤ W.
- **Edges:** W=0; all overweight.

## 2. Intuition
Enum left (weight,value); for each right pair, binary-search best left weight ≤ W-wr.

## 3. Brute Force → Optimal
- **Brute:** 2^n.
- **MITM:** 2^(n/2) with sort/scan.

## 4. Data Structure / Approach Justification
**Chosen:** generate half lists; sort by weight keeping best value prefix maxima.

| Alternative | Note |
|-------------|------|
| Classic DP | Needs small W |

## 5. Logic Walkthrough
1. Enum halves as (w,v).
2. Sort left by w; prefix max v.
3. For each right, query best left.

## 6. Dry Run
weights `[2,3,4]`, values `[3,4,5]`, W=5 → 7 (2+3).

## 7. Time & Space Complexity
**O(2^(n/2) · n)**.

## 8. Trade-offs & Alternatives
Memory for 2^20 pairs.

## 9. Common Mistakes / Edge Cases
Not taking prefix maxima; overflow weights.

## 10. Interview Follow-ups / Variations
Bounded knapsack; count optima.

## 11. Tags
`knapsack`, `meet-in-the-middle`, `difficulty:hard`
