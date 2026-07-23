# Bloom vs Hash Set Demo

## 1. Problem Statement
Insert N strings into both a Bloom filter and an `unordered_set`; compare positive checks and count false positives.

- **Inputs:** N inserts, query mix of present/absent keys.
- **Output:** exact hits, Bloom positives, false-positive count.
- **Valid answer:** Bloom never false-negatives on inserted keys; FP ≥ 0 on absent keys.
- **Edges:** empty; saturated filter.

## 2. Intuition
Same membership workload. Set is exact; Bloom uses fixed bits and may say “maybe” for absent keys.

## 3. Brute Force → Optimal
Illustrative only — not a rigorous benchmark harness.

## 4. Data Structure / Approach Justification
**Chosen:** side-by-side Bloom (`m=1024`,`k=4`) vs `unordered_set` for teaching the tradeoff.

## 5. Logic Walkthrough
1. Insert `key0..key99` into both.
2. Query `key0..key199`.
3. Tally exact membership, Bloom maybe, and FP = maybe ∧ ¬exact.

## 6. Dry Run
Expect `exact_hits=100`; `bloom_pos ≥ 100`; `false_pos` small/nonzero depending on load.

## 7. Time & Space Complexity
Demo **O(N k)** Bloom work + **O(N)** set; space **O(m + N)**. Why: fixed bits vs storing keys (section 4).

## 8. Trade-offs & Alternatives
Use a set when exactness and memory allow. Bloom shines as a cheap negative filter in front of disk/DB.

## 9. Common Mistakes / Edge Cases
Treating Bloom maybe as certainty; comparing wall times without controlling hashes/alloc.

## 10. Interview Follow-ups / Variations
Estimate FP rate formula; sizing `m,k` for target error.

## 11. Tags
`bloom-filter`, `hash-set`, `comparison`, `lab`, `difficulty:easy`
