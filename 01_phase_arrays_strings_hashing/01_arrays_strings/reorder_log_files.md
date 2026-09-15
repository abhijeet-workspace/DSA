# Reorder Data in Log Files

## Problem Statement
[LeetCode 937](https://leetcode.com/problems/reorder-data-in-log-files/) — reorder logs: letter-logs first (sort by content, then identifier), digit-logs after in original order.

- **Inputs:** `vector<string> logs` (`id` + space + words).
- **Output:** reordered logs.
- **Valid answer:** stable digit relative order; letter ties broken by id.
- **Edges:** identical contents; single log; all digit.

## Intuition
Split by type using first content character; sort only letter-logs with compound key `(content, id)`.

## Brute Force → Optimal
- **Brute:** custom comparator on full array (must carefully preserve digit stability).
- **Optimal:** partition then sort letters — clearer and O(N log N).

## Data Structure / Approach Justification
**Chosen:** two vectors + `sort` on letter keys.

- **vs `stable_sort` whole array:** harder comparator.
- **vs map:** unnecessary.

## Logic Walkthrough
Classify each log; sort letter by content then id; append digits.

## Dry Run
`let1 art can` and `let3 art zero` → `art can` before `art zero`.

## Time & Space Complexity
Time **O(N log N · L)**. Space **O(N·L)** for copies/keys.

## Trade-offs & Alternatives
In-place partition + stable_sort with careful comparator.

## Common Mistakes / Edge Cases
Sorting digit-logs; comparing full string including id first; unstable digit order.

## Interview Follow-ups / Variations
Custom collators; multi-key sorts in logs systems.

## Tags
`string`, `sorting`, `leetcode-937`, `difficulty:medium`
