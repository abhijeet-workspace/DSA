# Palindrome Linked List

## 1. Problem Statement
[LeetCode 234](https://leetcode.com/problems/palindrome-linked-list/) — return whether a singly linked list is a palindrome.

- **Inputs:** `ListNode* head`.
- **Output:** `bool`.
- **Valid answer:** values equal when read forward vs backward.
- **Edges:** empty/single; even vs odd length; non-palindrome mid mismatch.

## 2. Intuition
Find middle, reverse second half, compare first half against reversed second — O(1) extra space.

## 3. Brute Force → Optimal
- **Brute:** copy values to array/vector and two-pointer check — O(N) space.
- **Optimal:** mid + reverse + compare — O(1) space (mutates list).

## 4. Data Structure / Approach Justification
**Chosen:** slow/fast mid, iterative reverse, dual walk.

| Alternative | Why we skip it here |
|-------------|---------------------|
| Stack of first half | O(N) space |
| Recurse to end | O(N) stack; harder to restore |

## 5. Logic Walkthrough
1. Advance `slow`/`fast` to mid.
2. Reverse from `slow`.
3. Compare `p1` from head with `p2` from reversed half until `p2` ends.

## 6. Dry Run
`1→2→2→1`: mid at second `2`; reverse second half → `1→2`; compare `1,2` vs `1,2` → true.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) auxiliary

## 8. Trade-offs & Alternatives
If list must stay intact, reverse again after compare or use O(N) copy. Interview often allows mutation.

## 9. Common Mistakes / Edge Cases
Odd-length center node; comparing past midpoint; null head.

## 10. Interview Follow-ups / Variations
Restore list after check; palindrome for doubly linked; longest palindromic substring on arrays.

## 11. Tags
`linked-list`, `two-pointers`, `reverse`, `palindrome`, `leetcode-234`, `difficulty:easy`
