# Longest Repeating Character Replacement

## 1. Problem Statement
Longest substring you can make into one repeated character using at most `k` replacements.

- **Input:** uppercase string `s`, int `k`
- **Output:** int max length
- **Valid answer:** longest window where `len − maxFreq ≤ k`
- **Edges:** k=0; k≥n; all same; empty

## 2. Intuition
Keep a window dominated by its most frequent char; replacements cover the rest.

## 3. Brute Force → Optimal
- **Brute:** all windows + count — O(N² · 26).
- **Optimal:** sliding window tracking `maxFreq` — O(N).

## 4. Data Structure / Approach Justification
`array<int,26>` frequency + running `maxFreq`.

| Alternative | Why it loses here |
|-------------|-------------------|
| Binary search on length | Also O(N log N), more code |
| Per-target-char windows | 26 passes; fine but heavier |

## 5. Logic Walkthrough
1. Expand right; update `freq` and `maxFreq`.
2. While `len − maxFreq > k`, shrink left and decrement freq.
3. Track best window length.

## 6. Dry Run
`s=AABABBA`, `k=1` — grow until replacements needed > 1, shrink; best length **4**.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) for A–Z
- Why: each index enters/leaves once; fixed alphabet.

## 8. Trade-offs & Alternatives
Classic window is O(N). Note: `maxFreq` need not decrease on shrink for correctness of the max answer (monotonic best).

## 9. Common Mistakes / Edge Cases
Forgetting to update freq on shrink; assuming lowercase; k=0 → longest run of same char.

## 10. Interview Follow-ups / Variations
Replace to any pattern? Two character types only?

## 11. Tags
`sliding-window`, `frequency`, `leetcode-424`, `medium`
