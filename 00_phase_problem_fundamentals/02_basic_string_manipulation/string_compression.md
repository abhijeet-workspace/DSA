# String Compression

## 1. Problem Statement
[LeetCode 443](https://leetcode.com/problems/string-compression/) — Compress `chars` in-place with run-length encoding: groups of identical letters become letter + decimal count (omit count when 1). Return the new length; the first that many entries hold the answer.

- **Inputs:** `vector<char>& chars`.
- **Output:** New length (array mutated).
- **Edges:** All unique; single long run; counts ≥ 10 (multi-digit).

## 2. Intuition
Scan runs with a read index; write the letter (and digits of the count) with a write index that never overtakes unread data for this problem’s constraints.

## 3. Brute Force → Optimal
Build a new string then copy back — O(N) extra. Dual index read/write is O(N) time and O(1) extra.

## 4. Data Structure / Approach Justification
**Chosen:** `read` walks runs; `write` emits compressed form.

| Alternative | Why we skip leading with it |
|-------------|-----------------------------|
| Extra string buffer | Clear; uses O(N) space |
| Calling the indices “two pointers pattern” | Same positions; formal pattern is topic 7 |

This can look like a two-pointer solution, and a two-pointer formulation also works (and may even be more idiomatic once that pattern is formal). We solve it here via **direct position arithmetic / index scans** on purpose: this topic builds string scan-and-build fluency before the formal two-pointer pattern is introduced in topic 7.

## 5. Logic Walkthrough
1. `read = write = 0`.
2. While `read < n`: measure run of `c`; write `c`; if `count > 1`, write decimal digits.
3. Return `write`.

## 6. Dry Run
`aabbc cc` → writes `a2b2c3` length 6.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) extra (`to_string` uses O(log count) temp)

## 8. Trade-offs & Alternatives
Manual digit extraction without `to_string` avoids a tiny allocation. Decompress is the inverse (topic 1 RLE).

## 9. Common Mistakes / Edge Cases
Writing count `1`; multi-digit order; letting `write` corrupt unread runs (not an issue when writing shorter/equal runs as here).

## 10. Interview Follow-ups / Variations
Compress only runs ≥ k; decompress; binary run-length.

## 11. Tags
`string`, `two-index-write`, `leetcode-443`, `difficulty:medium`
