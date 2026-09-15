# Probabilistic Height Analysis Lab

## 1. Problem Statement
Empirically measure skip-list tower height distribution under geometric height sampling.

- **Inputs:** N inserts; coin probability 1/2.
- **Output:** histogram of heights; max height.
- **Edges:** N=1; theoretical E[height] ≈ log2 N.

## 2. Intuition
P(height ≥ h) = 2^{1-h}; expected max height ~ log2 N.

## 3. Brute Force → Optimal
- **Theory:** geometric distribution.
- **Lab:** simulate and count.

## 4. Data Structure / Approach Justification
**Chosen:** sample heights without building full list structure.

| Alternative | Note |
|-------------|------|
| Analyze treap depths | Different RNG model |

## 5. Logic Walkthrough
1. For i in 1..N sample height.
2. Histogram buckets.
3. Print counts and max.

## 6. Dry Run
N=1024 → max height often around 10–15.

## 7. Time & Space Complexity
**O(N · H)** sampling.

## 8. Trade-offs & Alternatives
Teaching only; not a contest problem.

## 9. Common Mistakes / Edge Cases
Biased RNG; off-by-one in geometric.

## 10. Interview Follow-ups / Variations
Vary p; compare to theoretical CDF.

## 11. Tags
`skip-list`, `probability`, `lab`, `difficulty:easy`
