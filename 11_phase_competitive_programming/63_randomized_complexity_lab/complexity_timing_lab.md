# Complexity Timing Lab

## 1. Problem Statement
Observe how runtime scales with N for classic O(N), O(N log N), and O(N²) loops.

- **Inputs:** sizes like 2e3, 4e3, 8e3.
- **Output:** milliseconds per family (noisy; trends matter).
- **Valid answer:** quadratic grows much faster than n log n / linear.
- **Edges:** compiler DCE — keep side effects (`sink`).

## 2. Intuition
Measure wall time with `steady_clock`. Ratios across doubled N approximate asymptotic growth despite noise.

## 3. Brute Force → Optimal
- **Trust Big-O only** vs **measure** controlled micro-benchmarks.

## 4. Data Structure / Approach Justification
**Chosen:** simple chrono harness + `sink` XOR to defeat dead-code elimination. Not a scientific benchmark suite.

## 5. Logic Walkthrough
1. Build `a = 1..N`.
2. Time linear sum, copy-sort, and O(N²) nested XOR sum.
3. Print ms; print `sink` so work is observable.

## 6. Dry Run
As N doubles, O(N²) time roughly ×4; O(N) roughly ×2; O(N log N) slightly above ×2.

## 7. Time & Space Complexity
Harness space **O(N)**. Observed times should reflect the labeled classes (section 4).

## 8. Trade-offs & Alternatives
Instruction counters / profilers are more rigorous. Cache effects blur constants.

## 9. Common Mistakes / Edge Cases
Single tiny N → noise; optimizing away empty loops; comparing unfair copies.

## 10. Interview Follow-ups / Variations
How does cache affect observed complexity? Amortized vs worst-case measurement.

## 11. Tags
`complexity`, `benchmark`, `big-o`, `lab`, `difficulty:easy`
