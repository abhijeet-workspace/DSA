# Restore IP Addresses

## Problem Statement
[LeetCode 93](https://leetcode.com/problems/restore-ip-addresses/) — from digit string `s`, return all valid IPv4 addresses by inserting three dots.

- **Inputs:** `string s` of digits (length typically 1–12).
- **Output:** `vector<string>` of dotted IPs.
- **Valid segment:** integer 0–255, no leading zeros (except `"0"`).
- **Edges:** too short/long; leading zeros; `"0000"` → `"0.0.0.0"`.

## Intuition
Build exactly 4 segments. From each start, try lengths 1–3; accept only valid segments; succeed when string consumed and segment count is 4.

## Brute Force → Optimal
- **Brute:** all ways to place 3 dots — O(N³) placements then validate.
- **Optimal:** DFS with early prune on invalid segments / leftover length; N≤12 so constant in practice.

## Data Structure / Approach Justification
**Chosen:** backtracking with segment length loop + validity helper.

- **vs triple nested loops on cut indices:** same idea, less flexible when generalizing.
- **vs regex:** hard to enumerate all valid splits cleanly in interview code.

## Logic Walkthrough
`backtrack(start, count, current)`: if `start==n && count==4`, strip trailing `.` and save. Else try `len=1..3`, if valid append `seg+"."` and recurse.

## Dry Run
`s="25525511135"`:
- `255.255.11.135` and `255.255.111.35` are the two valid IPs
- `255.255.1113.5` invalid (1113 > 255) pruned

## Time & Space Complexity
Time **O(1)** practically (≤3⁴ search, N≤12). Space **O(1)** recursion depth ≤4 (plus output). Why: fixed four segments and tiny N (section 4).

## Trade-offs & Alternatives
String-building with pass-by-value is simple; path vector + join also works. Iterative cut enumeration is fine for this bounded problem.

## Common Mistakes / Edge Cases
Allowing `"01"`; accepting values >255; leftover digits with `count==4`; forgetting to remove the final dot.

## Interview Follow-ups / Variations
Count only. IPv6 (different rules). Validate a single IP string.

## Tags
`backtracking`, `string`, `leetcode-93`, `difficulty:medium`
