# Minimum Genetic Mutation

## 1. Problem Statement
[LeetCode 433](https://leetcode.com/problems/minimum-genetic-mutation/) — genes length 8 over `A,C,G,T`. A mutation changes one character. Only genes in `bank` are valid (except start). Return minimum mutations from `startGene` to `endGene`, or `-1`.

- **Inputs:** start, end, bank.
- **Output:** min mutations.
- **Valid answer:** shortest Word-Ladder-style path.
- **Edges:** end not in bank; start==end (0 if allowed by constraints).

## 2. Intuition
Same pattern as Word Ladder: BFS where neighbors differ by one char and lie in the bank.

## 3. Brute Force → Optimal
- **Brute:** DFS — not shortest.
- **Optimal:** BFS O(|bank| · L · 4).

## 4. Data Structure / Approach Justification
**Chosen:** BFS + hash set bank/visited.

- **vs bidirectional BFS:** optional speedup.

## 5. Logic Walkthrough
Enqueue start. Try all one-char mutations in ACGT; if in bank and unseen, enqueue with dist+1.

## 6. Dry Run
One valid mutation to end → **1**.

## 7. Time & Space Complexity
Time **O(B · L · Σ)**. Space **O(B)**. Why: BFS over bank (section 4).

## 8. Trade-offs & Alternatives
Precompute adjacency among bank strings.

## 9. Common Mistakes / Edge Cases
Allowing mutations outside bank; forgetting end must be in bank; not restoring char while generating.

## 10. Interview Follow-ups / Variations
Word Ladder I/II; open the lock.

## 11. Tags
`bfs`, `string`, `leetcode-433`, `difficulty:medium`
