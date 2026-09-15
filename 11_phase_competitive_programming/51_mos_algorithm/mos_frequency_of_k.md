# Mo's Frequency of K

## 1. Problem Statement
Offline queries `(L, R, K)`: how many times does value `K` appear in `a[L..R]`?

- **Inputs:** array `a`, queries with inclusive range and target value `K`.
- **Output:** frequency of `K` in each range (0 if `K` never appears).
- **Valid answer:** exact occurrence count inside the closed interval.
- **Edges:** `K` absent; `L=R`; `K` only outside the range.

## 2. Intuition
Keep a frequency table for the current Mo window. After pointers match `[L,R]`, the answer is `freq[K]` in `O(1)`.

## 3. Brute Force → Optimal
- **Brute:** count `K` per range — `O(Q·N)`.
- **Optimal (Mo):** window + `freq[]` — `O((N+Q)√N)`. Occurrence lists + binary search is often simpler for this ask alone: `O((N+Q) log N)`.

## 4. Data Structure / Approach Justification

**Pedagogy:** teaching-lab for **Mo's algorithm** (offline block-sorted windows).
Prefix/Fenwick/SegTree win for associative range queries; Mo is for aggregators that support O(1)/O(
polylog) add/remove but are not prefix-friendly (distinct, mode, mex).

**Chosen:** Mo + dense `freq` array (values small in the demo).

- **vs occurrence lists:** binary-search positions of `K` in `[L,R]` — usually better for freq-of-K only.
- **vs unordered_map:** needed if values are huge/sparse without compression.

## 5. Logic Walkthrough
Block-sort queries. Move window with `++freq[a[i]]` / `--freq[a[i]]`. Guard `K` against out-of-range indices; store `freq[K]` at `idx`.

## 6. Dry Run
`a=[1,2,1,1,3]`:
- `(0,3,K=1)→3`; `(1,4,K=2)→1`; `(0,4,K=9)→0`.

## 7. Time & Space Complexity
Time **O((N+Q)√N)**. Space **O(N+Q+V)**. Why: `freq[v]` always equals occurrences of `v` in `[curL,curR]` (section 4).

## 8. Trade-offs & Alternatives
Mo is general when you already use the pattern; occurrence lists win for freq-of-K alone. Mo pays √ movement for flexibility.

## 9. Common Mistakes / Edge Cases
Resetting freq between queries instead of moving the window; map without compression for large values.

## 10. Interview Follow-ups / Variations
Support updates? Multiple `K`s / full histogram per query?

## 11. Tags
`mo-algorithm`, `frequency`, `offline-queries`, `sqrt-decomposition`, `difficulty:medium`
