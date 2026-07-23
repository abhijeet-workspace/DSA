# Amortized Analysis

## 1. Problem Statement
Simulate a doubling dynamic array and show why `n` pushes cost O(n) total time (O(1) amortized per push) via aggregate, accounting, and potential views.

- **Input:** sequence of 16 `push` operations on an empty array starting at capacity 1
- **Output:** per-push actual cost, token bank, potential `Φ`; total actual cost; aggregate average; final bank ≥ 0
- **Valid answer:** sum of actual costs over n pushes is O(n); accounting bank never relies on a negative balance in the end
- **Edge cases:** first push (no resize); push exactly when `size==capacity` (expensive copy)

## 2. Intuition
Occasional O(n) resizes look scary, but they happen only at sizes 1,2,4,8,… so total copy work is `1+2+4+…+n/2 < n`. Spreading that cost across all pushes yields constant amortized time — without assuming random inputs.

## 3. Brute Force → Optimal
- **Naive mental model:** “resize is O(n), so each push is O(n).”
- **Amortized view:** rare expensive ops + many cheap ops → average O(1) per op in any sequence (worst-case sequence analysis, not probabilistic average-case).

## 4. Data Structure / Approach Justification
**Chosen:** owning `int*` buffer that doubles on full; charge metrics for three analysis methods.

| Alternative | Why it loses here |
|-------------|-------------------|
| Only `std::vector` | Hides resize accounting |
| Grow by +1 each time | Amortized becomes Θ(n) — wrong teaching example |
| Halve at 50% full | Risk thrashing on insert/delete churn |

Trade-off: demo omits shrink; production vectors often shrink at 1/4 full to keep O(1) amortized.

## 5. Logic Walkthrough
1. **Actual cost:** 1 for the write; plus `size` when copying on double.
2. **Aggregate:** `total_actual / n` → approaches a small constant.
3. **Accounting:** charge $3 per push ($1 write + $2 saved); pay copies from bank; bank stays ≥ 0.
4. **Potential:** `Φ = 2·size − capacity`; amortized = actual + ΔΦ stays O(1).

## 6. Dry Run
Pushes 1..8 (capacities after ops: 1,2,4,4,8,8,8,8):

| Push # | size | capacity | actual | notes |
|--------|------|----------|--------|-------|
| 1 | 1 | 1 | 1 | no copy |
| 2 | 2 | 2 | 1+1=2 | double 1→2 |
| 3 | 3 | 4 | 1+2=3 | double 2→4 |
| 4 | 4 | 4 | 1 | |
| 5 | 5 | 8 | 1+4=5 | double 4→8 |
| … | … | … | … | geometric copies |

Sum of copy sizes `1+2+4+…` is &lt; n.

## 7. Time & Space Complexity
- **Single push:** O(1) typical, O(n) on resize
- **n pushes:** O(n) total actual → **O(1) amortized**
- **Space:** O(n) for elements; capacity &lt; 2n after doubling

Why: geometric series of copy costs (section 4).

## 8. Trade-offs & Alternatives
- Aggregate: simplest when all ops are similar.
- Accounting: good when you can assign credits to objects.
- Potential: clean for proofs with a state function Φ.
- Same idea appears in two-stack queues, binary counters, splay trees, Fibonacci heaps.

## 9. Common Mistakes / Edge Cases
- Confusing amortized with average-case (probability)
- Growing capacity by a constant → destroys O(1) amortized
- Halving at 1/2 capacity → insert/delete thrashing
- Potential that goes negative relative to Φ(D₀) invalidates the bound

## 10. Interview Follow-ups / Variations
- Prove two-stack queue dequeue is O(1) amortized
- Binary counter: n increments from 0 cost O(n) bit flips
- Dynamic array that doubles *and* halves at 1/4 — prove both insert/delete O(1) amortized

## 11. Tags
`amortized-analysis`, `dynamic-array`, `aggregate`, `accounting`, `potential`, `difficulty:medium`
