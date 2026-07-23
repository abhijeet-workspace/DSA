# Game Theory

## Problem Statement
Impartial combinatorial games: decide Nim winner from pile sizes, and compute Grundy (nimber) values for a subtraction game via MEX.

- **Inputs:** pile sizes; max pile + allowed subtractions.
- **Output:** whether first player wins Nim; Grundy numbers G(0..n).
- **Valid answer:** XOR≠0 ⇒ first wins standard Nim; G=0 ⇒ P-position.
- **Edges:** empty piles; n=0 terminal; moves larger than n ignored.

## Intuition
Nim piles combine by XOR (Sprague-Grundy). For a custom impartial game, each position’s Grundy is the MEX of Grundy values of positions reachable in one move. Sum of games is XOR of nimbers.

## Brute Force → Optimal
- **Brute:** recurse full game tree with alpha-beta / win-lose DP without theory — exponential in multi-pile sums.
- **Optimal:** Nim XOR O(piles); memoized Grundy O(n·|moves|); multi-pile via XOR of G values.

## Data Structure / Approach Justification
**Chosen:** integer XOR for Nim; `unordered_set` + MEX for move sets; memo vector for Grundy.

- **vs win/lose boolean only:** loses compositionality across independent components.
- **vs bitset MEX:** faster when move counts are huge.

## Logic Walkthrough
Nim: fold XOR; nonzero → first wins. Grundy(n): collect G(n−m) for legal m; return smallest missing nonnegative. Memoize. Multi-pile subtraction game: XOR all pile Grundies.

## Dry Run
Piles `{1,2,3}`: `1^2^3=0` → second wins.
Subtraction moves `{1,3,4}`:
- G(0)=0
- G(1)=mex{G(0)}=mex{0}=1
- G(2)=mex{G(1)}=mex{1}=0
- G(3)=mex{G(2),G(0)}=mex{0,0}=1 … continues

## Time & Space Complexity
Nim **O(P)**. Grundy **O(n · |moves|)** time, **O(n)** memo (+ set per state). Why: each state computed once (section 4).

## Trade-offs & Alternatives
Partisan games need other tools (e.g. surreal numbers). For huge n with periodic Grundy, detect period instead of filling all n.

## Common Mistakes / Edge Cases
Confusing misère Nim (small piles differ); treating G≠0 as second-win; forgetting memo; MEX starting at 0 not 1.

## Interview Follow-ups / Variations
Misère Nim; Kayles; graph games; multi-pile XOR of custom Grundy; “can first force win in k moves?”

## Tags
`game-theory`, `nim`, `sprague-grundy`, `mex`, `impartial`, `difficulty:medium`
