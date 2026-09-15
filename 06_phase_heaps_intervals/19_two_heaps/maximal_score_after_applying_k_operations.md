# Maximal Score After Applying K Operations

## 1. Problem Statement
[LeetCode 2530](https://leetcode.com/problems/maximal-score-after-applying-k-operations/) — op: choose `nums[i]`, add it to score, replace with `ceil(nums[i]/3)`; maximize score after `k` ops.

- **Inputs:** `nums`, `k`.
- **Output:** max score (`long long`).
- **Valid answer:** always pick current maximum.
- **Edges:** k=1; all equal; large values.

## 2. Intuition
Score gains the chosen value immediately — always take the current max from a max-heap.

## 3. Brute Force → Optimal
- **Brute:** branching on choices — exponential.
- **Optimal:** max-heap k times — O(K log N).

## 4. Data Structure / Approach Justification
**Chosen:** max-heap.

- **Adjacent** single-heap greedy next to true two-heap problems.

## 5. Logic Walkthrough
k times: pop max x, score+=x, push ceil(x/3).

## 6. Dry Run
`[1,10,3,3,3]`, k=3 → 10+4+3 = **17**.

## 7. Time & Space Complexity
Time **O((N+K) log N)**. Space **O(N)**. Why: heap (section 4).

## 8. Trade-offs & Alternatives
Integer ceil via `(x+2)/3` avoids floats.

## 9. Common Mistakes / Edge Cases
Using floor; 32-bit score overflow; min-heap.

## 10. Interview Follow-ups / Variations
Remove Stones; Halve Array Sum.

## 11. Tags
`heap`, `greedy`, `leetcode-2530`, `difficulty:medium`
