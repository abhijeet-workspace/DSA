# MinHash Lab (Simplified)

## 1. Problem Statement
Estimate Jaccard similarity of two sets via MinHash signatures.

- **Inputs:** two sets of strings; `k` hash functions (salted).
- **Output:** estimated Jaccard vs exact.
- **Edges:** empty set; identical sets; disjoint.
- **Note:** simplified salts — not cryptographic permutations.

## 2. Intuition
For random permutations, P(minhash equal) = Jaccard. Approximate with k hashes.

## 3. Brute Force → Optimal
- **Exact:** |A∩B|/|A∪B|.
- **MinHash:** compare signature equality rate.

## 4. Data Structure / Approach Justification
**Chosen:** k salted hashes; store min hash per set; fraction of matches.

| Alternative | Note |
|-------------|------|
| SimHash | Cosine/angular |
| Full pairwise | Exact |

## 5. Logic Walkthrough
1. For each salt, compute min hash over set.
2. Estimated J = matches/k.
3. Compare to exact.

## 6. Dry Run
A≈B → estimate near 1; disjoint → near 0.

## 7. Time & Space Complexity
**O(k·(|A|+|B|))**.

## 8. Trade-offs & Alternatives
Variance shrinks with k.

## 9. Common Mistakes / Edge Cases
Using same hash without salts; comparing sets of different universe wrong.

## 10. Interview Follow-ups / Variations
LSH banding; weighted MinHash.

## 11. Tags
`minhash`, `jaccard`, `lab`, `difficulty:medium`
