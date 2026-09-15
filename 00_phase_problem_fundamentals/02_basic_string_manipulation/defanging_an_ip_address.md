# Defanging an IP Address

## 1. Problem Statement
[LeetCode 1108](https://leetcode.com/problems/defanging-an-ip-address/) — Given a valid IPv4 `address`, return a defanged version where every `.` is replaced by `[.]`.

- **Inputs:** `string address`.
- **Output:** Defanged string.
- **Edges:** Minimal IP shape; digits only between dots.

## 2. Intuition
Single left-to-right build: copy non-dots; on `.` append the three-character token `[.]`.

## 3. Brute Force → Optimal
Repeated `find`/`replace` works but is clumsier than one scan-and-build pass.

## 4. Data Structure / Approach Justification
**Chosen:** output `string` built in one pass.

| Alternative | Why it loses here |
|-------------|-------------------|
| Regex replace | Overkill |
| In-place expand from the right | Possible but harder; length grows |

Classic string scan-and-build.

## 5. Logic Walkthrough
1. Empty `ans` (optionally `reserve`).
2. For each `c`: if `.`, append `[.]`; else append `c`.
3. Return `ans`.

## 6. Dry Run
`1.1.1.1` → `1[.]1[.]1[.]1`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(N) for output

## 8. Trade-offs & Alternatives
`reserve` improves constants; clarity first.

## 9. Common Mistakes / Edge Cases
Replacing with `.` only; forgetting brackets.

## 10. Interview Follow-ups / Variations
Defang other delimiters; validate IPv4 first.

## 11. Tags
`string`, `simulation`, `leetcode-1108`, `difficulty:easy`
