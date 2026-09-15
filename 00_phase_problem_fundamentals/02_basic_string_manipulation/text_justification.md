# Text Justification

## 1. Problem Statement
[LeetCode 68](https://leetcode.com/problems/text-justification/) — Given words and `maxWidth`, format text fully justified: pack as many words as fit per line; distribute extra spaces as evenly as possible between words (left-biased extras). The last line is left-justified with no extra gaps between words — pad spaces only at the end.

- **Inputs:** `vector<string> words`, `int maxWidth`.
- **Output:** `vector<string>` of justified lines, each length `maxWidth`.
- **Edges:** Single word on a line; last line; exact fit with no extra spaces.

## 2. Intuition
Greedily take the longest prefix of words that fits (`word lengths + minimum single spaces`). Then distribute leftover spaces across gaps — except on the last line (or one-word lines), which are left-padded.

## 3. Brute Force → Optimal
Must inspect each word once for packing — O(N) words, O(total characters) output construction. No asymptotic shortcuts; careful gap math is the hard part.

## 4. Data Structure / Approach Justification
**Chosen:** window `[i, j)` of words for the current line; build each line with `append` of spaces.

| Alternative | Why it loses here |
|-------------|-------------------|
| Stringstream formatting | Harder to control exact spaces |
| Precompute all gap sizes in a separate structure | Fine; in-loop math is enough |

This capstone is pure **construction/formatting discipline** — not a parsing FSM (Valid Number) and not DP/window patterns.

## 5. Logic Walkthrough
1. Advance `i`; grow `j` while words + min spaces fit in `maxWidth`.
2. Compute `spaces = maxWidth - sum(word lengths)`, `gaps = j - i - 1`.
3. If last line or `gaps == 0`: join with single spaces; pad end to `maxWidth`.
4. Else: `base = spaces/gaps`, `extra = spaces%gaps`; put `base(+1)` spaces in left gaps first.
5. Push line; set `i = j`.

## 6. Dry Run
Words for width 16 → lines `This    is    an`, `example  of text`, `justification.  ` (exact spacing per LC).

## 7. Time & Space Complexity
- **Time:** O(T) where T is total output characters
- **Space:** O(T) for the answer

## 8. Trade-offs & Alternatives
Building with a `vector<int>` of gap widths first can make uneven distribution easier to test. Last-line special case is the usual bug magnet — isolate it clearly.

## 9. Common Mistakes / Edge Cases
Using the same distribution on the last line; off-by-one in fit check (`+ (j-i)` min spaces); forgetting one-word lines; not padding to exactly `maxWidth`.

## 10. Interview Follow-ups / Variations
Left-only justify; center lines; hyphenation; HTML-like soft wraps.

## 11. Tags
`string`, `simulation`, `formatting`, `leetcode-68`, `difficulty:hard`
