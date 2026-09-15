# Count Paths With XOR

## 1. Problem Statement
CP classic — undirected weighted tree; count unordered pairs whose path-XOR equals target `X`.

- **Inputs:** tree edges `(u,v,w)`, target XOR `X`.
- **Output:** pair count.
- **Edges:** single edge; `X=0` needs care with identity.

## 2. Intuition
At each centroid, path XOR from the centroid is a prefix; pair prefixes `a,b` with `a^b==X` via frequency map.

## 3. Brute Force → Optimal
- **Brute:** DFS each pair — O(N²).
- **Optimal:** CD + hash map — O(N log N) expected.

## 4. Data Structure / Approach Justification
**Chosen:** CD + `unordered_map` of XOR frequencies (query before merge).

| Alternative | Note |
|-------------|------|
| Bit trie | Better for XOR ≤ K |
| Linear basis | Different problem |

## 5. Logic Walkthrough
Collect XORs from centroid through each subtree; add `freq[X^xr]`; merge.

## 6. Dry Run
Path `1—(1)—2—(2)—3`, `X=3` → one pair `(1,3)`.

## 7. Time & Space Complexity
Time **O(N log N)** expected. Space **O(N)**. Why: CD layers + hashing (section 4).

## 8. Trade-offs & Alternatives
Bit-trie when you need count of XOR ≤ K.

## 9. Common Mistakes / Edge Cases
Forgetting to XOR the first edge weight; merging before query.

## 10. Interview Follow-ups / Variations
Count XOR in range; k-th XOR path.

## 11. Tags
`centroid`, `xor`, `path-counting`, `cp`, `difficulty:hard`
