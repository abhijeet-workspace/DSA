# Bloom Membership Spellcheck Demo

## 1. Problem Statement
Demo: load a tiny dictionary into a Bloom filter; spellcheck words as maybe-in-dictionary vs exact set confirmation.

- **Inputs:** dictionary words; query words.
- **Output:** for each query: `miss` / `maybe` / `hit` after exact check.
- **Edges:** FP maybe that exact rejects.

## 2. Intuition
Spellcheckers historically used Bloom filters to cheaply reject non-words.

## 3. Brute Force → Optimal
- **Exact set only.**
- **Bloom+exact:** fast negative path.

## 4. Data Structure / Approach Justification
**Chosen:** Bloom cascade (same idea as cascade filter) with printed statuses.

| Alternative | Note |
|-------------|------|
| Trie dictionary | Exact prefixes |
| BK-tree | Corrections |

## 5. Logic Walkthrough
1. Insert dict into Bloom + set.
2. Query: Bloom miss → miss; else exact hit/maybe-FP.

## 6. Dry Run
Dict `{cat,dog}`; query `cat` hit; `cot` miss or FP-then-reject.

## 7. Time & Space Complexity
**O(k)** per query typical.

## 8. Trade-offs & Alternatives
FP require exact fallback.

## 9. Common Mistakes / Edge Cases
Autocorrecting on Bloom maybe alone.

## 10. Interview Follow-ups / Variations
Suggest edits; measure FP on real lists.

## 11. Tags
`bloom-filter`, `spellcheck`, `lab`, `difficulty:easy`
