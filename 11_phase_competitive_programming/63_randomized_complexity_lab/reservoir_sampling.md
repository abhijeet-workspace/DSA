# Reservoir Sampling (LC 382 array framing)

## 1. Problem Statement
Sample `k` items uniformly from a stream / array without knowing length ahead (reservoir).

- **Inputs:** stream of values, `k`.
- **Output:** k-sample; each subset equally likely for finite streams.
- **Related:** [LC 382](https://leetcode.com/problems/linked-list-random-node/) is k=1 on a list.
- **Edges:** stream length < k; k=1.
- **Link:** [LC 382](https://leetcode.com/problems/linked-list-random-node/)

## 2. Intuition
Keep first k; for i-th item (i≥k), replace a random reservoir slot with prob k/(i+1).

## 3. Brute Force → Optimal
- **Brute:** store all then sample.
- **Reservoir:** O(k) memory.

## 4. Data Structure / Approach Justification
**Chosen:** Algorithm R for arrays as stream.

| Alternative | Note |
|-------------|------|
| Skip-based Vitter | Fewer RNG calls |
| Exact index pick | Needs length |

## 5. Logic Walkthrough
1. Fill reservoir with first k.
2. For each new index i, j=rand(0..i); if j<k replace.

## 6. Dry Run
Stream 1..5, k=2 → random pair; roughly uniform over C(5,2).

## 7. Time & Space Complexity
**O(N)** time, **O(k)** space.

## 8. Trade-offs & Alternatives
Fundamental streaming algorithm.

## 9. Common Mistakes / Edge Cases
Wrong probability; off-by-one on i.

## 10. Interview Follow-ups / Variations
Weighted reservoir; distributed.

## 11. Tags
`reservoir-sampling`, `streaming`, `lc-382-related`, `difficulty:medium`
