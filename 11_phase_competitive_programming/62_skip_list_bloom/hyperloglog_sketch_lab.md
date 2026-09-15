# HyperLogLog Sketch Lab (Simplified)

## 1. Problem Statement
Estimate cardinality of a multiset with a simplified HyperLogLog-style sketch (few registers, max leading zeros).

- **Inputs:** stream of items (with duplicates).
- **Output:** approximate distinct count.
- **Edges:** empty stream; all duplicates.
- **Note:** teaching simplification — not full HLL (no α bias correction tables).

## 2. Intuition
Hash → bucket by prefix; track max runs of leading zeros; harmonic-like mean ≈ cardinality.

## 3. Brute Force → Optimal
- **Exact set.**
- **Sketch:** tiny memory approximate.

## 4. Data Structure / Approach Justification
**Chosen:** 16 registers; estimate `const * m² / Σ 2^{-M[j]}`.

| Alternative | Note |
|-------------|------|
| MinHash | Similarity not cardinality |
| Exact hash set | Baseline |

## 5. Logic Walkthrough
1. Hash item.
2. Update register with leading-zero rank.
3. Aggregate estimate.

## 6. Dry Run
Insert 100 distinct → estimate in same ballpark (rough).

## 7. Time & Space Complexity
**O(1)** per item; space **O(m)** registers.

## 8. Trade-offs & Alternatives
High variance at tiny m — lab only.

## 9. Common Mistakes / Edge Cases
Using signed hash; wrong leading-zero count.

## 10. Interview Follow-ups / Variations
Merge sketches; compare to exact.

## 11. Tags
`hyperloglog`, `sketch`, `lab`, `difficulty:hard`
