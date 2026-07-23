# Rotate Array (Reversal)

## 1. Problem Statement
Rotate `nums` right by `k` steps in place.

- **Input:** `nums`, `k ≥ 0`
- **Output:** mutated array
- **Edges:** `k % n == 0`; `n==0`; `k > n`

## 2. Intuition
Right rotate by k ≡ reverse whole array, then reverse first k and the rest — three two-pointer reversals.

## 3. Brute Force → Optimal
- **Brute:** rotate one step k times — O(Nk).
- **Extra buffer:** O(N) time/space.
- **Optimal:** three reverses — O(N) time, O(1) space.

## 4. Data Structure / Approach Justification
In-place reverse via opposite swaps; no extra array.

| Alternative | Why it loses here |
|-------------|-------------------|
| Cycle/juggling | O(N)/O(1) but harder to code |
| `std::rotate` | Fine in prod; hides the interview trick |

## 5. Logic Walkthrough
1. `k %= n`.
2. Reverse `[0,n)`.
3. Reverse `[0,k)` and `[k,n)`.

## 6. Dry Run
`[1,2,3,4,5,6,7]`, k=3:
full reverse → `[7,6,5,4,3,2,1]`
→ `[5,6,7,4,3,2,1]` → `[5,6,7,1,2,3,4]`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) auxiliary

## 8. Trade-offs & Alternatives
Left rotate uses different segment cuts; always normalize `k` with `%`.

## 9. Common Mistakes / Edge Cases
Forgetting `k %= n`; empty array; reversing wrong segment bounds.

## 10. Interview Follow-ups / Variations
Rotate linked list; block-swap algorithm.

## 11. Tags
`two-pointers`, `reversal`, `in-place`, `leetcode-189`
