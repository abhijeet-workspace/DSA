# Sort List

## 1. Problem Statement
[LeetCode 148](https://leetcode.com/problems/sort-list/) — sort a linked list in ascending order in O(N log N) time and O(1) extra space ideally (O(log N) stack for top-down merge is accepted).

- **Inputs:** `ListNode* head`.
- **Output:** head of sorted list.
- **Valid answer:** ascending by `val`.
- **Edges:** empty; one node; already sorted; reverse sorted; duplicates.

## 2. Intuition
Merge sort: find middle with slow/fast, split, sort halves, merge two sorted lists.

## 3. Brute Force → Optimal
- **Brute:** copy to array, `std::sort`, rebuild — O(N) space.
- **Optimal:** linked-list merge sort — O(N log N) time, O(log N) recursion (or bottom-up O(1)).

## 4. Data Structure / Approach Justification
**Chosen:** top-down merge sort using mid-find (fast/slow) + merge.

- **vs array sort:** easier but O(N) memory.
- **vs insertion sort:** O(N²) — too slow for constraints.

## 5. Logic Walkthrough
1. Base: 0/1 nodes.
2. Slow/fast to mid; cut before mid’s second half.
3. Recursively sort left/right; merge with dummy.

## 6. Dry Run
`4→2→1→3`: mid split `4→2` | `1→3` → sort → `2→4` | `1→3` → merge → `1→2→3→4`.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(log N)** stack (top-down). Why: log N splits × linear merges; mid via slow/fast (section 4).

## 8. Trade-offs & Alternatives
Bottom-up merge sort meets strict O(1) space; top-down is clearer in interviews.

## 9. Common Mistakes / Edge Cases
Not cutting halves (infinite recursion); wrong mid leaving one side empty; merge losing tails.

## 10. Interview Follow-ups / Variations
Merge two sorted lists; merge k lists; bottom-up sort list.

## 11. Tags
`linked-list`, `merge-sort`, `fast-slow-pointers`, `leetcode-148`, `difficulty:medium`
