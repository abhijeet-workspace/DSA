# Move Zeroes

## 1. Problem Statement
Move all zeros to the end **in place**, preserving relative order of non-zeros.

- **Input:** `nums`
- **Output:** mutated array
- **Edges:** no zeros; all zeros; single element

## 2. Intuition
Same-direction write pointer: compact non-zeros, then zero-fill the tail.

## 3. Brute Force → Optimal
- **Brute:** extra array of non-zeros + zeros — O(N) space.
- **Optimal:** one write index — O(1) extra.

## 4. Data Structure / Approach Justification
Single write index over `vector` (stable partition without `std::stable_partition`).

| Alternative | Why it loses here |
|-------------|-------------------|
| Swap with next non-zero | Also O(N); similar |
| `remove` + fill | Idiomatic C++; same idea |

## 5. Logic Walkthrough
1. `write=0`; copy each non-zero to `nums[write++]`.
2. Fill `[write, n)` with 0.

## 6. Dry Run
`[0,1,0,3,12]` → write `1,3,12` then pad zeros → `[1,3,12,0,0]`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) auxiliary

## 8. Trade-offs & Alternatives
Two-pass clear; one-pass swap variant also fine in interviews.

## 9. Common Mistakes / Edge Cases
Breaking non-zero order; writing zeros before finishing compaction.

## 10. Interview Follow-ups / Variations
Move all evens; snow plow / Dutch flag variants.

## 11. Tags
`two-pointers`, `in-place`, `partition`, `leetcode-283`
