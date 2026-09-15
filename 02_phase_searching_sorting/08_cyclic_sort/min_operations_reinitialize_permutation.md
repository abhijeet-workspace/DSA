# Minimum Number of Operations to Reinitialize a Permutation

## 1. Problem Statement
[LeetCode 1806](https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/) — `n` even. Start with `perm[i] = i`. One operation builds `arr` where even `i` takes `perm[i/2]`, odd `i` takes `perm[n/2 + (i-1)/2]`, then `perm = arr`. Return minimum operations to return to identity.

- **Inputs:** even `int n`.
- **Output:** minimum operation count.
- **Edges:** `n = 2` → 1.

## 2. Intuition
The operation is a fixed permutation of indices. Reinitialize time equals the order of that permutation — length of the cycle containing any non-fixed point (commonly index `1`). On `{1..n-2}`, the map reduces to doubling modulo `n - 1`.

## 3. Brute Force → Optimal
- **Brute:** simulate full array each step — O(N · answer).
- **Optimal:** track one index under doubling mod `n-1` — O(answer) ≤ O(N).

## 4. Data Structure / Approach Justification
**Chosen:** cycle length of index `1` under `i → 2i mod (n-1)`.

- **vs full simulation:** same answer, worse constants.
- Fits **cycle following** on the operation’s index map (cousin of cyclic sort’s placement cycles).

## 5. Logic Walkthrough
1. If `n == 2`, return `1`.
2. `i = 1`, `ans = 0`.
3. Repeat `i = (2 * i) % (n - 1)`, `++ans` until `i == 1`.
4. Return `ans`.

## 6. Dry Run
`n = 4`: `i: 1 → 2 → 1` → 2 operations.  
`n = 6`: `1 → 2 → 4 → 3 → 1` → 4 operations.

## 7. Time & Space Complexity
- **Time:** O(N) worst-case cycle length.
- **Space:** O(1).

## 8. Trade-offs & Alternatives
Full permutation power simulation is fine for tiny `n`. Number-theory order of 2 modulo `n-1` is the closed form when `gcd(2, n-1)=1`.

## 9. Common Mistakes / Edge Cases
Using mod `n` instead of `n-1`; forgetting `n == 2`; simulating the value array but off-by-one on odd/even rule.

## 10. Interview Follow-ups / Variations
Array Nesting (565); rotate array cycles (189); order of a permutation.

## 11. Tags
`cyclic-sort`, `math`, `permutation`, `leetcode-1806`, `difficulty:medium`
