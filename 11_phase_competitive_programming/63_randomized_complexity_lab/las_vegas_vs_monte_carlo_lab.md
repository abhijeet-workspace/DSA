# Las Vegas vs Monte Carlo Lab

## 1. Problem Statement
Contrast Las Vegas (always correct, random runtime) vs Monte Carlo (bounded time, random error) with tiny demos.

- **Inputs:** small search / primality instances.
- **Output:** printed classification of each algorithm's guarantees.
- **Edges:** error probability discussion; expected vs worst time.

## 2. Intuition
Randomized quicksort/quickselect ≈ Las Vegas; Fermat primality ≈ Monte Carlo (may err on composites).

## 3. Brute Force → Optimal
- **Deterministic baselines.**
- **Randomized flavors** differ in error vs time.

## 4. Data Structure / Approach Justification
**Chosen:** (1) randomized find of a guaranteed-present key (Las Vegas); (2) one-shot Fermat (Monte Carlo).

| Alternative | Note |
|-------------|------|
| RP / BPP theory | Complexity classes |

## 5. Logic Walkthrough
1. Shuffle-scan until key found — always correct.
2. Single Fermat test — may wrongly call Carmichael prime.

## 6. Dry Run
Find 7 in array always succeeds; Fermat on 561 (Carmichael) may lie.

## 7. Time & Space Complexity
LV expected O(N); MC O(log³ n) with error risk.

## 8. Trade-offs & Alternatives
Know which guarantee your interview answer needs.

## 9. Common Mistakes / Edge Cases
Calling all randomized algs 'approximate'.

## 10. Interview Follow-ups / Variations
Atlantic City algorithms; amplify MC by repetition.

## 11. Tags
`las-vegas`, `monte-carlo`, `lab`, `difficulty:medium`
