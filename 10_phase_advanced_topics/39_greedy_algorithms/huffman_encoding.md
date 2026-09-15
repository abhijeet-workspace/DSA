# Huffman Encoding

## 1. Problem Statement
Build optimal **prefix-free** binary codes for character frequencies (classic greedy compression).

- **Inputs:** text (or explicit frequency table).
- **Output:** code string per distinct character.
- **Valid answer:** any optimal-length assignment (ties allowed).
- **Edges:** one symbol; equal frequencies; empty text (not handled here).

## 2. Intuition
Repeatedly merge the two lowest-frequency nodes into a parent. Rare symbols end up deeper → longer codes; common ones stay shallow.

## 3. Brute Force → Optimal
- **Brute:** enumerate prefix codes — exponential.
- **Optimal:** min-heap merges — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** min `priority_queue` of `HuffNode*`; DFS collect leaf codes.

- **vs Shannon-Fano:** inferior / less clean optimality proof.
- **vs arithmetic coding:** better compression, different model.

## 5. Logic Walkthrough
Count freqs → push leaves → while >1 node: pop two lightest, push parent → walk tree assigning `0`/`1`.

## 6. Dry Run
`"aabbbcc"` → freqs a:2,b:3,c:2 → three leaf codes (exact bits may vary by tie-breaking).

## 7. Time & Space Complexity
Time **O(N log N)** heap ops on distinct symbols. Space **O(N)** tree. Why: Huffman minimizes weighted external path length (section 4).

## 8. Trade-offs & Alternatives
Needs a frequency table; not adaptive alone. Canonical Huffman for compact headers.

## 9. Common Mistakes / Edge Cases
Using a max-heap; forgetting the single-symbol `"0"` code; memory leaks if nodes never freed (demo code).

## 10. Interview Follow-ups / Variations
Canonical Huffman? Adaptive Huffman? Prove optimality.

## 11. Tags
`greedy`, `heap`, `compression`, `tree`, `difficulty:medium`
