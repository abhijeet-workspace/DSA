# Compare Version Numbers

## 1. Problem Statement
[LeetCode 165](https://leetcode.com/problems/compare-version-numbers/) — Compare two version strings composed of dot-separated revisions. Compare revision integers left to right (leading zeros ignored). Missing revisions count as 0. Return `-1`, `0`, or `1`.

- **Inputs:** `string version1`, `version2`.
- **Output:** `-1` / `0` / `1`.
- **Edges:** Unequal revision counts; leading zeros; trailing `.0` groups.

## 2. Intuition
Parse one integer revision at a time from each string (between dots), compare, then advance past the dots. Treat exhausted sides as zeros.

## 3. Brute Force → Optimal
Split both into vectors of ints then compare — clear O(N) with allocations. Streaming parse is O(N) / O(1).

## 4. Data Structure / Approach Justification
**Chosen:** two scan indices parsing decimal revisions on the fly.

| Alternative | Why it loses here |
|-------------|-------------------|
| `stringstream` + `getline(..., '.')` | Fine; more overhead |
| `stoi` on substrings | Extra allocations per revision |

Tokenizing by `.` is string construction/parsing discipline — still this topic’s throughline.

## 5. Logic Walkthrough
1. While either string has unread chars: parse next revision ints `a`, `b` (0 if missing).
2. Compare `a` vs `b`; return early on inequality.
3. Skip dots; if both exhausted equally, return 0.

## 6. Dry Run
`1.01` vs `1.001` → `(1,1)` then `(1,1)` → 0. `0.1` vs `1.1` → `(0,1)` → -1.

## 7. Time & Space Complexity
- **Time:** O(N + M)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Vector-of-revisions is easier to debug; streaming is tighter on memory.

## 9. Common Mistakes / Edge Cases
Comparing as strings (`"1.10"` vs `"1.2"`); forgetting missing revisions are 0; overflow if not using a wide accumulator (constraints are safe for 32-bit usually — `long` is defensive).

## 10. Interview Follow-ups / Variations
Semver with pre-release tags; compare IP-like dotted quads.

## 11. Tags
`string`, `parsing`, `leetcode-165`, `difficulty:medium`
