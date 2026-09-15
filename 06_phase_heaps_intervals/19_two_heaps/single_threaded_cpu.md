# Single-Threaded CPU

## 1. Problem Statement
[LeetCode 1834](https://leetcode.com/problems/single-threaded-cpu/) — CPU runs one task at a time; when free, pick available task with shortest processing time (tie → smallest index). Return execution order.

- **Inputs:** `tasks[i] = [enqueueTime, processingTime]`.
- **Output:** permutation of indices in run order.
- **Valid answer:** greedy by available min-heap.
- **Edges:** all enqueue at 0; idle gaps; ties on processing time.

## 2. Intuition
Sort tasks by enqueue time. Maintain a min-heap of tasks that have arrived. Always run the shortest available; jump time forward when idle.

## 3. Brute Force → Optimal
- **Brute:** each step scan all arrived tasks — O(N²).
- **Optimal:** sort + min-heap — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** sorted queue of future tasks + min-heap of available `(proc, idx)`.

- **vs two heaps:** one heap for available is enough; “dual structure” is sort+heap scheduling.

## 5. Logic Walkthrough
Sort. Advance `time`. Push all with enqueue≤time into heap. Pop shortest, add to order, advance time by proc. If heap empty, jump to next enqueue.

## 6. Dry Run
`[[1,2],[2,4],[3,2],[4,1]]` → order **0,2,3,1**.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: each task enters/leaves heap once (section 4).

## 8. Trade-offs & Alternatives
Classic dual-structure scheduling (sorted timeline + ready heap). Closely related to process tasks using servers.

## 9. Common Mistakes / Edge Cases
Not jumping time when idle; wrong tie-break; comparing enqueue instead of processing time in heap.

## 10. Interview Follow-ups / Variations
Process Tasks Using Servers (1882); Course Schedule III (630).

## 11. Tags
`heap`, `scheduling`, `sorting`, `two-heaps-adjacent`, `leetcode-1834`, `difficulty:medium`
