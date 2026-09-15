# Sum of All Odd Length Subarrays

## Problem Statement
[LeetCode 1588](https://leetcode.com/problems/sum-of-all-odd-length-subarrays/) — return the sum of all possible odd-length subarrays of `arr`.

- **Input:** `vector<int> arr`
- **Output:** sum of elements across every odd-length contiguous subarray
- **Edges:** length 1; length 2 (only singles); all equal elements

## Intuition
Instead of enumerating subarrays, count how many odd-length subarrays include index `i`, then add `arr[i] * count(i)`.

Number of subarrays containing `i` is `(i+1)*(n-i)`. Half of them (rounded up) have odd length → `((i+1)*(n-i)+1)/2`.

## Brute Force → Optimal
- **Brute:** for every odd length L, slide and sum — O(N²).
- **Optimal:** contribution formula per index — O(N). Prefix-sum sliding also O(N²) or O(N) with formula.

## Data Structure / Approach Justification
Closed-form contribution count; no extra structures.

| Alternative | Why it loses here |
|-------------|-------------------|
| Explicit nested loops | Fine for tiny N; slower asymptotically |
| Prefix sums per window | Still O(N²) windows |

## Logic Walkthrough
For each i: `count = ((i+1)*(n-i)+1)/2`; `total += arr[i]*count`.

## Dry Run
`[1,4,2,5,3]`: odd windows include singles, length-3, length-5; total sum **58**.

## Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)
- Why: one pass with arithmetic counts.

## Trade-offs & Alternatives
Brute force is clearer in interviews if N is small; mention the O(N) contribution insight as optimization. Prefix sum helps if you still expand windows.

## Common Mistakes / Edge Cases
Forgetting length-1 subarrays; integer division flooring without `+1`; counting even lengths too.

## Interview Follow-ups / Variations
Sum of all even-length subarrays; sum of all subarrays (contribution `(i+1)*(n-i)`); 2D analog.

## Tags
`prefix-sum`, `math`, `contribution-technique`, `leetcode-1588`, `easy`
