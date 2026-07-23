# Bloom Filter Lab

## 1. Problem Statement
Demonstrate a tiny Bloom filter: insert keys and query `possiblyContains`.

- **Inputs:** bit array size `m`, hash count `k`, strings to insert/query.
- **Output:** true if all k bits set (maybe present); false ⇒ definitely absent.
- **Valid answer:** no false negatives (without deletes); false positives possible.
- **Edges:** saturation (too many inserts); empty filter.

## 2. Intuition
k independent-looking hashes set bits on insert. Lookup requires all k bits; any zero proves absence.

## 3. Brute Force → Optimal
- **Exact:** hash set stores keys.
- **Bloom:** O(k) per op with m bits — approximate membership.

## 4. Data Structure / Approach Justification
**Chosen:** `vector<bool>` + `std::hash` salted by index (teaching demo, not crypto-grade).

| Alternative | Note |
|-------------|------|
| Cuckoo / quotient filter | Deletions / better locality |
| Exact set | When memory allows |

## 5. Logic Walkthrough
1. Allocate `m` bits, choose `k`.
2. Insert: set `hash(s,i)` for i in 0..k-1.
3. Query: return false on first unset bit; else true.

## 6. Dry Run
Insert `cat`,`dog`; `cat` → true; `fish` → usually false on a sparse filter.

## 7. Time & Space Complexity
Time **O(k)** per op, space **O(m)** bits. Why: fixed bit array independent of key size (section 4).

## 8. Trade-offs & Alternatives
Great for cache / dictionary pre-checks. Production uses battle-tested hashes and tuned `(m,k)`.

## 9. Common Mistakes / Edge Cases
Treating maybe as certainty; weak/repeated hashes; deletes without counting Bloom.

## 10. Interview Follow-ups / Variations
False-positive rate ≈ `(1-e^(-kn/m))^k`; counting Bloom for deletes.

## 11. Tags
`bloom-filter`, `probabilistic`, `hashing`, `lab`, `difficulty:medium`
