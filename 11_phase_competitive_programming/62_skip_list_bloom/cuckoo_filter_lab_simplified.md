# Cuckoo Filter Lab (Simplified)

## 1. Problem Statement
Simplified cuckoo filter: store fingerprints in buckets with limited kicks; support add/lookup/delete.

- **Inputs:** keys; ops.
- **Output:** maybe-contains; successful deletes of inserted keys.
- **Edges:** table full; fingerprint collisions.
- **Note:** teaching simplification — not production-complete.

## 2. Intuition
Each item hashes to two buckets; on conflict, kick existing fingerprint to its alternate bucket.

## 3. Brute Force → Optimal
- **Hash set.**
- **Cuckoo filter:** compact fingerprints + deletes.

## 4. Data Structure / Approach Justification
**Chosen:** 2-way buckets of fingerprints; kick limit.

| Alternative | Note |
|-------------|------|
| Bloom | No good deletes |
| Cuckoo hash table | Stores full keys |

## 5. Logic Walkthrough
1. Fingerprint = hash bits.
2. Try insert in i1 or i2; else kick.
3. Lookup checks both buckets.

## 6. Dry Run
Insert a few strings; lookup true; delete; lookup false.

## 7. Time & Space Complexity
Amortized **O(1)** with load limits.

## 8. Trade-offs & Alternatives
Simplified fingerprint/bucket sizes.

## 9. Common Mistakes / Edge Cases
Infinite kick loops; wrong alternate index formula.

## 10. Interview Follow-ups / Variations
Partial-key cuckooing; load factor experiments.

## 11. Tags
`cuckoo-filter`, `probabilistic`, `lab`, `difficulty:hard`
