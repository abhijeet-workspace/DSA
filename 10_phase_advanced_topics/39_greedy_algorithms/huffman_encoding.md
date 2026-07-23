# Huffman Encoding

## Problem Statement
Build optimal **prefix-free** binary codes for character frequencies (classic greedy compression).

- **Inputs:** text (or explicit frequency table).
- **Output:** code string per distinct character.
- **Valid answer:** any optimal-length assignment (ties allowed).
- **Edges:** one symbol; equal frequencies; empty text (not handled here).

## Intuition
Repeatedly merge the two lowest-frequency nodes into a parent. Rare symbols end up deeper → longer codes; common ones stay shallow.

## Brute Force → Optimal
- **Brute:** enumerate prefix codes — exponential.
- **Optimal:** min-heap merges — O(N log N).

## Data Structure / Approach Justification
**Chosen:** min `priority_queue` of `HuffNode*`; DFS collect leaf codes.

- **vs Shannon-Fano:** inferior / less clean optimality proof.
- **vs arithmetic coding:** better compression, different model.

## Logic Walkthrough
Count freqs → push leaves → while >1 node: pop two lightest, push parent → walk tree assigning `0`/`1`.

## Dry Run
`"aabbbcc"` → freqs a:2,b:3,c:2 → three leaf codes (exact bits may vary by tie-breaking).

## Time & Space Complexity
Time **O(N log N)** heap ops on distinct symbols. Space **O(N)** tree. Why: Huffman minimizes weighted external path length (section 4).

## Trade-offs & Alternatives
Needs a frequency table; not adaptive alone. Canonical Huffman for compact headers.

## Common Mistakes / Edge Cases
Using a max-heap; forgetting the single-symbol `"0"` code; memory leaks if nodes never freed (demo code).

## Interview Follow-ups / Variations
Canonical Huffman? Adaptive Huffman? Prove optimality.

## Tags
`greedy`, `heap`, `compression`, `tree`, `difficulty:medium`
