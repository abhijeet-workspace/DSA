# Subtraction Game — Teaching Lab

## 1. Problem Statement
**Teaching lab:** win/lose positions for subtraction set S.

## 2. Intuition
Win if move to a lose position.

## 3. Brute Force → Optimal
- **Brute:** search.
- **Optimal:** see approach.

## 4. Data Structure / Approach Justification
**Chosen:** bool DP.

**Pedagogy:** Win/lose before full Grundy (single pile).

## 5. Logic Walkthrough
See implementation comments and dry run.

## 6. Dry Run
S={1,2} → lose when i%3==0.

## 7. Time & Space Complexity
See approach.

## 8. Trade-offs & Alternatives
Prefer the simplest correct theory (XOR / DP / closed form) that matches constraints.

## 9. Common Mistakes / Edge Cases
Off-by-one terminals; confusing first/second win; missing memoization; misère edge cases.

## 10. Interview Follow-ups / Variations
Related stone/Nim/Grundy variants; multi-pile composition via XOR.

## 11. Tags
`subtraction-game`, `teaching-lab`, `difficulty:easy`
