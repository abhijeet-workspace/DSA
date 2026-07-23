# String Operations with Stack

## Problem Statement
Practice three LIFO patterns: reverse a string, check palindrome via half-stack, convert decimal to binary via remainders.

- **Inputs:** strings / non-negative ints in demos.
- **Output:** reversed string; boolean palindrome; binary bit string.
- **Valid answer:** matches naive reverse / palindrome / base-2 conversion.
- **Edges:** empty string; odd-length palindrome; `num == 0`.

## Intuition
Stack reverses order naturally. Palindrome compares first half (pushed) to second half. Binary bits emerge LSB-first as remainders — stack flips to MSB-first.

## Brute Force → Optimal
- **Reverse:** two pointers O(N)/O(1) beats stack O(N)/O(N) — stack is pedagogical here.
- **Palindrome:** two pointers from ends is simpler; stack mirrors the LIFO lesson.
- **Binary:** bit shifts / recursion also work; stack stores remainders cleanly.

## Data Structure / Approach Justification
**Chosen:** `stack<char>` / `stack<int>` to make LIFO explicit for teaching.

- **vs two pointers:** preferred in production for reverse/palindrome.
- **vs `bitset`/`to_string` tricks:** less clear for base conversion learning.

## Logic Walkthrough
1. Push all chars; pop into result.
2. Push first half; compare with second half (skip middle if odd).
3. While `num>0`, push `num%2`, `num/=2`; pop into binary string.

## Dry Run
`"Hello"` → `olleH`. `"racecar"`: push r,a,c; skip e; match c,a,r. `5` → remainders 1,0,1 → `"101"`.

## Time & Space Complexity
Each demo **O(N)** time and **O(N)** space (or O(log num) for binary). Why: stack stores half/full input or remainders (section 4).

## Trade-offs & Alternatives
Prefer two pointers for reverse/palindrome in interviews unless asked for a stack solution.

## Common Mistakes / Edge Cases
Forgetting odd-length middle skip; empty binary for 0; building string with `+=` of ints incorrectly.

## Interview Follow-ups / Variations
In-place reverse; Unicode-aware palindrome; base-k conversion.

## Tags
`stack`, `string`, `palindrome`, `binary`, `difficulty:easy`
