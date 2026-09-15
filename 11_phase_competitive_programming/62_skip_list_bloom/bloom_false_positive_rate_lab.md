# Bloom False Positive Rate Lab

## 1. Problem Statement
Measure empirical false-positive rate of a Bloom filter vs formula `(1-e^(-kn/m))^k`.

- **Inputs:** `m` bits, `k` hashes, `n` inserts; probe `t` absent keys.
- **Output:** empirical FP rate and theoretical estimate.
- **Edges:** saturated filter; k=1.

## 2. Intuition
More inserts raise collision probability; formula assumes ideal hashes.

## 3. Brute Force → Optimal
- **Exact set:** FP=0.
- **Bloom:** tunable FP.

## 4. Data Structure / Approach Justification
**Chosen:** bitset + salted std::hash; compare rates.

| Alternative | Note |
|-------------|------|
| Double hashing | Better independence |
| Counting Bloom | Deletes |

## 5. Logic Walkthrough
1. Insert n keys.
2. Query t fresh keys; count maybe-true.
3. Print empirical vs formula.

## 6. Dry Run
Small m relative to n → high FP.

## 7. Time & Space Complexity
**O((n+t)·k)**.

## 8. Trade-offs & Alternatives
Teaching hashes ≠ crypto; formula is approximate.

## 9. Common Mistakes / Edge Cases
Probing inserted keys as FP; integer overflow in formula.

## 10. Interview Follow-ups / Variations
Sweep k; plot optimal k≈(m/n)ln2.

## 11. Tags
`bloom-filter`, `false-positive`, `lab`, `difficulty:medium`
