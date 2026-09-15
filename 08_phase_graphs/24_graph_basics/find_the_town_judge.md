# Find the Town Judge

## 1. Problem Statement
[LeetCode 997](https://leetcode.com/problems/find-the-town-judge/) — people `1..n`. Trust edges `a → b` mean `a` trusts `b`. Town judge is trusted by all others and trusts nobody. Return judge or `-1`.

- **Inputs:** `n`, `trust` list.
- **Output:** judge id or -1.
- **Valid answer:** unique if exists.
- **Edges:** `n=1` no edges → 1; cycles; no judge.

## 2. Intuition
Track net score: −1 when trusting, +1 when trusted. Judge score is `n-1`.

## 3. Brute Force → Optimal
- **Brute:** build graph, check in/out degrees.
- **Optimal:** single pass score array O(n + E).

## 4. Data Structure / Approach Justification
**Chosen:** degree-delta array.

- **vs adjacency lists:** more code for same answer.

## 5. Logic Walkthrough
For each trust, decrement truster, increment trustee. Scan for score `n-1`.

## 6. Dry Run
`n=3`, trust `(1,3),(2,3)` → **3**.

## 7. Time & Space Complexity
Time **O(n+E)**. Space **O(n)**. Why: one pass + scan (section 4).

## 8. Trade-offs & Alternatives
Explicit in/out degree arrays are equivalent and clearer for beginners.

## 9. Common Mistakes / Edge Cases
Forgetting `n=1`; requiring score `n` instead of `n-1`.

## 10. Interview Follow-ups / Variations
Celebrity problem; find centers; graph sinks.

## 11. Tags
`graph`, `degree`, `leetcode-997`, `difficulty:easy`
