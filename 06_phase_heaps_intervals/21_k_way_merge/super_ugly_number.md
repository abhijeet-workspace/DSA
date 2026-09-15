# Super Ugly Number

## 1. Problem Statement
[LeetCode 313](https://leetcode.com/problems/super-ugly-number/) — super ugly numbers are positive integers whose prime factors are in `primes`; return the n-th.

- **Inputs:** `n`, `primes`.
- **Output:** n-th super ugly number.
- **Valid answer:** k-way generation via min-heap of candidates.
- **Edges:** n=1 → 1; single prime; duplicates in heap.

## 2. Intuition
Like merging k sorted sequences of multiples — pop min, push min*each prime (deduped).

## 3. Brute Force → Optimal
- **Brute:** scan integers testing factors.
- **Optimal:** heap / DP pointers — O(n log n · |primes|) heap form.

## 4. Data Structure / Approach Justification
**Chosen:** min-heap + hash set for seen.

- **vs DP with pointers per prime:** O(n·|primes|) classic ugly DP.

## 5. Logic Walkthrough
Start with 1. n times: pop cur; for each prime push cur*p if unseen.

## 6. Dry Run
primes `{2,7,13,19}`, n=12 → **32**.

## 7. Time & Space Complexity
Time **O(n · P log (nP))** heap form. Space **O(nP)**. Why: candidates grow (section 4).

## 8. Trade-offs & Alternatives
Heap version maps cleanly to k-way merge teaching; DP pointers often faster.

## 9. Common Mistakes / Edge Cases
Overflow without 64-bit; not deduping; off-by-one on n.

## 10. Interview Follow-ups / Variations
Ugly Number II (264) in top-k folder; merge k lists.

## 11. Tags
`heap`, `k-way-merge`, `math`, `leetcode-313`, `difficulty:medium`
