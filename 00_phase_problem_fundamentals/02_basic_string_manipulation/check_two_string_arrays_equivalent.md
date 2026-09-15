# Check If Two String Arrays are Equivalent

## 1. Problem Statement
[LeetCode 1662](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/) — Two string arrays represent concatenations. Return whether `word1` joined equals `word2` joined.

- **Inputs:** `vector<string> word1`, `word2`.
- **Output:** `true` / `false`.
- **Edges:** Single chunks; unequal total lengths; mismatch mid-stream.

## 2. Intuition
Walk both concatenations character-by-character with `(chunk index, offset)` pairs — no need to allocate the full join.

## 3. Brute Force → Optimal
Concatenate both, then compare — O(N) time and O(N) space. Streaming comparison is O(N) time and O(1) extra.

## 4. Data Structure / Approach Justification
**Chosen:** four indices streaming both sides.

| Alternative | Why we skip leading with it |
|-------------|-----------------------------|
| Build both full strings | Clear; wastes memory |
| Formal two-pointer narrative | Same indices; vocabulary is topic 7 |

This can look like a two-pointer solution, and a two-pointer formulation also works (and may even be more idiomatic once that pattern is formal). We solve it here via **direct position arithmetic / index scans** on purpose: this topic builds string scan-and-build fluency before the formal two-pointer pattern is introduced in topic 7.

## 5. Logic Walkthrough
1. `(i,p)` on `word1`, `(j,q)` on `word2`.
2. Compare current chars; advance offsets; roll to next chunk at boundaries.
3. Equal iff both streams exhaust together.

## 6. Dry Run
`[ab,c]` vs `[a,bc]` → stream `a,b,c` on both sides → true.

## 7. Time & Space Complexity
- **Time:** O(N) total characters
- **Space:** O(1) extra

## 8. Trade-offs & Alternatives
Building concatenations is fine if N is small; streaming shows care for memory.

## 9. Common Mistakes / Edge Cases
Forgetting to advance the chunk index; returning true when one side still has characters.

## 10. Interview Follow-ups / Variations
Lazy iterators; compare k arrays.

## 11. Tags
`string`, `simulation`, `leetcode-1662`, `difficulty:easy`
