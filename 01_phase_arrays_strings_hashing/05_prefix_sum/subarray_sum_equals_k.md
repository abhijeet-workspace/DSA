# Subarray Sum Equals K

## Problem Statement
Count continuous subarrays whose sum equals `k`.

LeetCode: [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)

**Inputs:** `nums`, integer `k` (nums may contain negatives / zeros).  
**Valid answer:** number of contiguous subarrays with sum `k`.  
**Edges:** `k=0`; negatives; single element equals `k`; empty.

## Intuition
If `prefix[r] - prefix[l] = k`, then `prefix[l] = prefix[r] - k`. Hash how often each prior prefix appeared.

## Brute Force → Optimal
- **Brute:** check all O(N²) subarrays.
- **Optimal:** one pass with hashmap of prefix frequencies — O(N).

## Data Structure / Approach Justification (REQUIRED)
`unordered_map` of prefix-sum frequencies.
- **vs sliding window:** window needs non-negative nums; fails with negatives.
- **vs sorting:** destroys index order required for contiguous subarrays.

## Logic Walkthrough
Start `freq[0]=1`. For each `x`: add to `prefixSum`, add `freq[prefixSum-k]` to `count`, then `++freq[prefixSum]`.

## Dry Run
`[1,1,1]`, `k=2`: at last index `prefix=3`, `freq[1]=2` → `count += 2`.

## Time & Space Complexity
**O(N)** time, **O(N)** space. Why: one scan; map stores distinct prefixes (section 4).

## Trade-offs & Alternatives
Handles negatives; uses O(N) hash space. All-positive → sliding window / two pointers also work.

## Common Mistakes / Edge Cases
Forgetting `freq[0]=1`; updating frequency before querying (under/overcounts).

## Interview Follow-ups / Variations
Count distinct subarrays? Subarray XOR equals `k`? (same map idea on XOR prefixes)

## Tags
`prefix-sum`, `hash-map`, `subarray`, `medium`, `lc-560`
