# Merge Strings Alternately

## 1. Problem Statement
[LeetCode 1768](https://leetcode.com/problems/merge-strings-alternately/) — merge `word1` and `word2` by alternating characters starting with `word1`; append the remainder of the longer string.

- **Inputs:** strings `word1`, `word2`.
- **Output:** merged string.
- **Edges:** one empty; equal length; one much longer.

## 2. Intuition
Two indices advance in lockstep while both have chars; then append the leftover suffix.

## 3. Brute Force → Optimal
Single pass building the result — O(N+M) optimal.

## 4. Data Structure / Approach Justification
**Chosen:** two pointers / index walk (string analog of merge in merge-sort).

## 5. Logic Walkthrough
1. While both have remaining chars: append `word1[i++]`, then `word2[j++]`.
2. Append leftover of either string.

## 6. Dry Run
`abc` + `pqr` → `apbqcr`. `ab` + `pqrs` → `apbqrs`.

## 7. Time & Space Complexity
Time **O(N+M)**. Space **O(N+M)** for output.

## 8. Trade-offs & Alternatives
`reserve(n+m)` avoids realloc churn.

## 9. Common Mistakes / Edge Cases
Stopping at `min` length without appending remainder; swapping start order.

## 10. Interview Follow-ups / Variations
Merge alternately with custom start; zigzag merge of k strings.

## 11. Tags
`two-pointers`, `string`, `leetcode-1768`, `difficulty:easy`
