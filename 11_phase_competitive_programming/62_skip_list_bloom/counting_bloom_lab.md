# Counting Bloom Filter Lab

## 1. Problem Statement
Implement a tiny counting Bloom filter supporting `add`, `remove`, and `maybeContains`.

- **Inputs:** keys to add/remove; queries.
- **Output:** membership maybes; demonstrate delete.
- **Edges:** remove too many (counter underflow); saturation.

## 2. Intuition
Replace bits with small counters; decrement on delete.

## 3. Brute Force → Optimal
- **Exact set.**
- **Counting Bloom:** approximate with deletes.

## 4. Data Structure / Approach Justification
**Chosen:** `vector<uint8_t>` counters + k hashes.

| Alternative | Note |
|-------------|------|
| Cuckoo filter | Better deletes |
| Plain Bloom | No delete |

## 5. Logic Walkthrough
1. add: ++counters at hashes.
2. remove: -- if >0.
3. maybe: all counters >0.

## 6. Dry Run
add cat; remove cat; maybe(cat) usually false if no collisions.

## 7. Time & Space Complexity
**O(k)** per op.

## 8. Trade-offs & Alternatives
Counters use more memory; still false positives.

## 9. Common Mistakes / Edge Cases
Underflow wrapping; treating maybe as sure after delete.

## 10. Interview Follow-ups / Variations
Saturated counters; spectral Bloom.

## 11. Tags
`counting-bloom`, `lab`, `difficulty:medium`
