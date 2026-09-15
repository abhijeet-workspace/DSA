# Shuffle the Array

## 1. Problem Statement
[LeetCode 1470](https://leetcode.com/problems/shuffle-the-array/) — `nums` has length `2n`: first half `x`, second half `y`. Return `[x0,y0,x1,y1,...,x_{n-1},y_{n-1}]`.

- **Inputs:** `vector<int> nums` length `2n`; `int n`.
- **Output:** Interleaved `vector<int>` length `2n`.
- **Edges:** `n = 1`; identical halves.

## 2. Intuition
Map pair index `i` to output positions `2i` (from left half) and `2i+1` (from right half).

## 3. Brute Force → Optimal
Two index pointers into each half also work, but that teaches two-pointer choreography early. Prefer explicit `i → 2i` math here.

## 4. Data Structure / Approach Justification
**Chosen:** one loop on `i ∈ [0,n)` writing `ans[2i]` and `ans[2i+1]`.

| Alternative | Why we skip it here |
|-------------|---------------------|
| Two pointers (`p`/`q`) advancing together | Valid and idiomatic later (topic 7); here we want index arithmetic |
| In-place shuffle with swaps | Harder correctness; not required |

We choose direct indexing on purpose so interleaving is “position math,” not pointer choreography.

## 5. Logic Walkthrough
1. Allocate `ans(2n)`.
2. For `i = 0..n-1`: `ans[2i] = nums[i]`, `ans[2i+1] = nums[n+i]`.
3. Return `ans`.

## 6. Dry Run
`nums=[2,5,1,3,4,7]`, `n=3` → pairs `(2,3)`, `(5,4)`, `(1,7)` → `[2,3,5,4,1,7]`.

## 7. Time & Space Complexity
- **Time:** O(N) where N = 2n
- **Space:** O(N) output

## 8. Trade-offs & Alternatives
In-place variants exist as interview follow-ups; clarity first in this topic.

## 9. Common Mistakes / Edge Cases
Using `2n` as the loop bound; swapping half indices (`n+i` vs `i+n` confusion).

## 10. Interview Follow-ups / Variations
In-place shuffle; k-way interleave.

## 11. Tags
`array`, `simulation`, `indexing`, `leetcode-1470`, `difficulty:easy`
