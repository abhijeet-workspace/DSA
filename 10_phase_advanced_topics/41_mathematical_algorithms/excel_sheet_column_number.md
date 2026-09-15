# Excel Sheet Column Number

## 1. Problem Statement
[LeetCode 171](https://leetcode.com/problems/excel-sheet-column-number/) — convert Excel column title (`A`,`AB`,…) to its 1-indexed number.

- **Inputs:** uppercase string `columnTitle`.
- **Output:** integer column number.
- **Valid answer:** base-26 value with `A=1` … `Z=26`.
- **Edges:** `"A"`; `"ZY"`; long titles.

## 2. Intuition
Base-26 with digits 1..26 (no zero digit). Horner: `ans = ans*26 + (c-'A'+1)`.

## 3. Brute Force → Optimal
Same Horner loop is optimal.

## 4. Data Structure / Approach Justification
**Chosen:** left-to-right Horner accumulation.

- **vs right-to-left powers:** same result; Horner avoids explicit pow.

## 5. Logic Walkthrough
For each char: multiply by 26 and add mapped value.

## 6. Dry Run
`"AB"` → `((0*26+1)*26+2)=28`. `"ZY"` → **701**.

## 7. Time & Space Complexity
Time **O(L)**. Space **O(1)**.

## 8. Trade-offs & Alternatives
Inverse problem is Excel Sheet Column Title (168).

## 9. Common Mistakes / Edge Cases
Using `A=0`; 32-bit overflow on long titles (use long).

## 10. Interview Follow-ups / Variations
Column title from number (168); arbitrary base with no zero.

## 11. Tags
`math`, `base-conversion`, `leetcode-171`, `difficulty:easy`
