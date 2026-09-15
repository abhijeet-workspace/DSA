# Bloom Cascade Filter

## 1. Problem Statement
Chain two Bloom filters (cascade): only keys that pass L1 are checked in L2 / exact set — classic cascade for reducing work.

- **Inputs:** large candidate stream; small positive set.
- **Output:** confirmed memberships after cascade.
- **Edges:** L1 false positives reaching L2.

## 2. Intuition
Cheap approximate reject in front; expensive exact structure behind.

## 3. Brute Force → Optimal
- **Exact only.**
- **Cascade:** Bloom then hash set.

## 4. Data Structure / Approach Justification
**Chosen:** Bloom prefilter + `unordered_set` confirm.

| Alternative | Note |
|-------------|------|
| Multi-level Bloom | Cascade of Blooms |
| Cuckoo | Different FP profile |

## 5. Logic Walkthrough
1. Insert true keys into Bloom and set.
2. On query: if Bloom says no → no; else check set.

## 6. Dry Run
Query absent key often rejected at Bloom; present key confirmed by set.

## 7. Time & Space Complexity
**O(k)** reject path; occasional O(1) set.

## 8. Trade-offs & Alternatives
Industry pattern for caches / spellcheck.

## 9. Common Mistakes / Edge Cases
Skipping exact confirm (unsafe).

## 10. Interview Follow-ups / Variations
Measure reduce rate; tune m,k.

## 11. Tags
`bloom-filter`, `cascade`, `lab`, `difficulty:medium`
