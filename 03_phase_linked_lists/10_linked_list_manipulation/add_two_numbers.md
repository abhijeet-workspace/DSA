# Add Two Numbers

## Problem Statement
[LeetCode 2](https://leetcode.com/problems/add-two-numbers/) — two non-negative integers stored digit-by-digit in reverse order as linked lists; return their sum as a list in the same format.

- **Inputs:** `ListNode* l1`, `ListNode* l2` (non-empty).
- **Output:** new list representing the sum.
- **Valid answer:** correct decimal sum with digits reverse-ordered.
- **Edges:** different lengths; final carry (`999+1`); zeros.

## Intuition
Schoolbook addition: walk both lists, add digits plus carry, emit `sum % 10`, keep `sum / 10`.

## Brute Force → Optimal
- **Brute:** convert lists to big integers / strings, add, rebuild — messy with leading zeros and language limits.
- **Optimal:** single pass with carry and dummy head — O(max(N,M)).

## Data Structure / Approach Justification
**Chosen:** dummy node + iterative digit merge.

- **vs convert to int:** overflows for long lists.
- **vs recursion:** same idea; iterative is clearer for carry state.

## Logic Walkthrough
`dummy` anchors the result. While either list or `carry` remains, add available digits, append `sum % 10`, set `carry = sum / 10`. Return `dummy.next`.

## Dry Run
`2→4→3` + `5→6→4` (342+465):
- `2+5=7`, carry 0 → `7`
- `4+6=10`, carry 1 → `0`
- `3+4+1=8` → `8` → `7→0→8`

## Time & Space Complexity
Time **O(max(N,M))**. Space **O(max(N,M))** for output (O(1) extra besides result). Why: one pass over longer input (section 4).

## Trade-offs & Alternatives
In-place mutate one list only if mutation allowed; usually build fresh nodes.

## Common Mistakes / Edge Cases
Dropping final carry; stopping when one list ends; forgetting dummy cleanup / leak in demos.

## Interview Follow-ups / Variations
Digits in forward order (LC 445); add on arrays; multiply strings.

## Tags
`linked-list`, `math`, `carry`, `dummy-node`, `difficulty:medium`
