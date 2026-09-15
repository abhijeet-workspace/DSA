# Next Greater Element I

## 1. Problem Statement
[LeetCode 496](https://leetcode.com/problems/next-greater-element-i/) — `nums1` is a subset of `nums2`. For each `x` in `nums1`, find the first strictly greater element to the right of `x` in `nums2` (or `-1`).

- **Inputs:** `vector<int> nums1`, `vector<int> nums2` (distinct values; `nums1 ⊆ nums2`).
- **Output:** `vector<int>` same length as `nums1`.
- **Edges:** empty `nums1`; next greater never exists; `x` at end of `nums2`.

## 2. Intuition
Precompute next-greater for every value in `nums2` with a monotonic decreasing stack, then answer queries via a map. Unresolved values leave `-1`.

## 3. Brute Force → Optimal
- **Brute:** for each `x` in `nums1`, scan right from its position in `nums2` — O(N·M).
- **Optimal:** one O(N) pass on `nums2` + O(1) lookups — O(N + M).

## 4. Data Structure / Approach Justification
**Chosen:** decreasing stack of values + `unordered_map` value → next greater.

| Alternative | Why it loses here |
|-------------|-------------------|
| Nested scan per query | Quadratic when both arrays are large |
| Store indices only | Values are unique; map of values is enough |

## 5. Logic Walkthrough
1. Scan `nums2` left→right.
2. While stack top `< x`, pop and record `next_greater[top] = x`.
3. Push `x`.
4. For each `nums1[i]`, look up map (default `-1`).

## 6. Dry Run
`nums1=[4,1,2]`, `nums2=[1,3,4,2]`:
- `3` resolves `1`; `4` resolves `3`; `2` resolves nothing → map `{1→3, 3→4}` → answers `-1, 3, -1`.

## 7. Time & Space Complexity
- **Time:** O(N + M) — each `nums2` value pushed/popped ≤ once.
- **Space:** O(N) stack + map.

## 8. Trade-offs & Alternatives
Right-to-left with a candidate stack also works. Index-based stack is needed when values are not unique (see II / linked-list variants).

## 9. Common Mistakes / Edge Cases
Using `<=` (problem is strictly greater); scanning `nums1` with a stack instead of precomputing on `nums2`; forgetting leftovers are `-1`.

## 10. Interview Follow-ups / Variations
Next Greater Element II (circular); daily temperatures (distance); next greater node in linked list.

## 11. Tags
`stack`, `monotonic-stack`, `hash-map`, `leetcode-496`, `difficulty:easy`
