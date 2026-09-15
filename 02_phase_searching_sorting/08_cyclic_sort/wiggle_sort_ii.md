# Wiggle Sort II

## 1. Problem Statement
[LeetCode 324](https://leetcode.com/problems/wiggle-sort-ii/) — reorder `nums` so `nums[0] < nums[1] > nums[2] < nums[3] ...`. Values need not be distinct. O(N) time / O(1) extra preferred in follow-ups.

- **Inputs:** `vector<int>& nums`.
- **Output:** any valid wiggle order (in-place).
- **Edges:** duplicates around median; odd/even length.

## 2. Intuition
Put the larger half on “peaks” (odd indices) and the smaller half on “valleys” (even). Access order via virtual index map `A(i) = (1 + 2·i) % (n|1)` so a Dutch-flag partition around the median writes directly into wiggle slots — index remapping, same family as cyclic placement.

## 3. Brute Force → Optimal
- **Brute:** sort + interleave from two ends — O(N log N), O(N).
- **Optimal:** `nth_element` median + 3-way partition on mapped indices — O(N) avg, O(1) extra.

## 4. Data Structure / Approach Justification
**Chosen:** median + virtual cyclic index map + Dutch partition.

- **vs sort+copy:** simpler; uses O(N) space / O(N log N).
- Teaching goal: **index permutation** before writing values (cyclic-sort mindset).

## 5. Logic Walkthrough
1. `nth_element` so median sits at `n/2`.
2. Map `A(i) = (1 + 2*i) % (n|1)`.
3. 3-way partition: values `> mid` to the left of virtual order, `< mid` to the right, `== mid` in middle.

## 6. Dry Run
`[1,5,1,1,6,4]` → median `1`; after mapped partition one valid layout `[1,6,1,5,1,4]`.

## 7. Time & Space Complexity
- **Time:** O(N) average (`nth_element` + partition).
- **Space:** O(1) extra.

## 8. Trade-offs & Alternatives
Sort-and-interleave is safer in interviews if O(N log N)/O(N) is allowed. Perfect wiggle with many median duplicates is the hard case for both.

## 9. Common Mistakes / Edge Cases
Interleaving small/large from the front (equal medians adjacent); wrong map formula; treating as Wiggle Sort I (adjacent swap only).

## 10. Interview Follow-ups / Variations
Wiggle Sort I (280); Sort Colors (75) partition; cyclic index maps in rotate (189).

## 11. Tags
`cyclic-sort`, `array`, `partition`, `leetcode-324`, `difficulty:medium`
