# Add Strings

## 1. Problem Statement
[LeetCode 415](https://leetcode.com/problems/add-strings/) — Given two non-negative integers as strings `num1` and `num2`, return their sum as a string. Do not convert the inputs to machine integers directly.

- **Inputs:** `string num1`, `num2` (digits only).
- **Output:** Sum as a decimal string.
- **Edges:** Different lengths; carry out of the MSB; zeros.

## 2. Intuition
Simulate grade-school addition from the least significant digit: walk both strings from the end with a carry.

## 3. Brute Force → Optimal
Big-integer libraries are cheating here. Digit DP / other heavy tools are unnecessary — one reverse pass is optimal.

## 4. Data Structure / Approach Justification
**Chosen:** indices `i`/`j` from the ends + `carry`; build digits then reverse.

| Alternative | Why we skip leading with it |
|-------------|-----------------------------|
| `stoll` / native ints | Overflow on large inputs; against the spirit |
| Naming ends as “two pointers pattern” | Same positions; formal pattern is topic 7 |

This can look like a two-pointer solution, and a two-pointer formulation also works (and may even be more idiomatic once that pattern is formal). We solve it here via **direct position arithmetic / index scans** on purpose: this topic builds string scan-and-build fluency before the formal two-pointer pattern is introduced in topic 7.

## 5. Logic Walkthrough
1. `i`, `j` at last chars; `carry = 0`; empty `ans`.
2. While either index remains or carry: add digits + carry; push `sum % 10`; set carry `sum / 10`.
3. Reverse `ans` and return.

## 6. Dry Run
`11 + 123` → digits yield `4,3,1` then reverse → `134`.

## 7. Time & Space Complexity
- **Time:** O(max(N, M))
- **Space:** O(max(N, M)) for output

## 8. Trade-offs & Alternatives
Pushing to a `vector<char>` then reversing is equivalent. Multiply/add bigints follow the same digit loop idea.

## 9. Common Mistakes / Edge Cases
Forgetting final carry; mixing up ASCII (`'0'`); unsigned index underflow.

## 10. Interview Follow-ups / Variations
Add binary (LC 67); multiply strings (LC 43); subtract strings.

## 11. Tags
`string`, `math`, `simulation`, `leetcode-415`, `difficulty:easy`
