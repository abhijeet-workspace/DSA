# Game Theory

## 1. Problem Statement

Impartial games toolkit: Nim XOR winner and Grundy/MEX for subtraction games.

- **Inputs:** piles; max n + move set.
- **Output:** first-win bool; Grundy table.
- **Edges:** empty; G(0)=0.

## 2. Intuition

Sprague–Grundy: independent piles XOR; G(x)=mex of moves.

## 3. Brute Force → Optimal

- **Brute:** game tree.
- **Optimal:** XOR / O(n|S|) Grundy.

## 4. Data Structure / Approach Justification

**Chosen:** XOR fold; memo Grundy with mex set.

**Pedagogy:** Teaching lab overview; later files are LC drills and focused demos.

## 5. Logic Walkthrough

See implementation comments and dry run.

## 6. Dry Run

Piles {1,2,3} XOR=0 → second wins.

## 7. Time & Space Complexity

Nim O(P); Grundy O(n|S|).

## 8. Trade-offs & Alternatives

Prefer the simplest correct theory (XOR / DP / closed form) that matches constraints.

## 9. Common Mistakes / Edge Cases

Off-by-one terminals; confusing first/second win; missing memoization; misère edge cases.

## 10. Interview Follow-ups / Variations

Related stone/Nim/Grundy variants; multi-pile composition via XOR.

## 11. Tags

`game-theory`, `nim`, `grundy`, `difficulty:medium`
