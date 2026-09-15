# Grundy Numbers Demo — Teaching Lab

## 1. Problem Statement
**Teaching lab:** Grundy for subtraction game; multi-pile via XOR.

## 2. Intuition
G(x)=mex{G(x-s)}; piles XOR.

## 3. Brute Force → Optimal
- **Brute:** search.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** DP vector.

**Pedagogy:** Kayles skipped (harder graph); focused subtraction Grundy.

## 5. Logic Walkthrough
See implementation comments and dry run.

## 6. Dry Run
Print G(0..10) for S={1,3,4}.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Prefer the simplest correct theory (XOR / DP / closed form) that matches constraints.

## 9. Common Mistakes / Edge Cases
Off-by-one terminals; confusing first/second win; missing memoization; misère edge cases.

## 10. Interview Follow-ups / Variations
Related stone/Nim/Grundy variants; multi-pile composition via XOR.

## 11. Tags
`grundy`, `teaching-lab`, `difficulty:medium`
