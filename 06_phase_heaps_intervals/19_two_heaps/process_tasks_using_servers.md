# Process Tasks Using Servers

## 1. Problem Statement
[LeetCode 1882](https://leetcode.com/problems/process-tasks-using-servers/) — assign each task to the free server with smallest weight (tie → smallest index); busy until time+task; return server index per task.

- **Inputs:** `servers` weights, `tasks` durations.
- **Output:** `ans[j]` = server for task j.
- **Valid answer:** dual heaps free/busy.
- **Edges:** more tasks than servers; all servers busy; weight ties.

## 2. Intuition
True two-heap scheduling: free servers ordered by (weight,index); busy servers ordered by free-time. Move busy→free when time catches up.

## 3. Brute Force → Optimal
- **Brute:** scan servers each task — O(N·M).
- **Optimal:** two heaps — O((N+M) log N).

## 4. Data Structure / Approach Justification
**Chosen:** min-heap free + min-heap busy.

- **vs one heap:** cannot efficiently both “next free time” and “best free server”.

## 5. Logic Walkthrough
For task j at time max(j, …): release busy servers with freeTime≤t into free; if free empty, jump t to next busy freeTime; assign free.top(); push busy.

## 6. Dry Run
servers `[3,3,2]`, tasks `[1,2,3,2,1,2]` → **[2,2,0,2,1,2]**.

## 7. Time & Space Complexity
Time **O((N+M) log N)**. Space **O(N)**. Why: each assignment heap ops (section 4).

## 8. Trade-offs & Alternatives
Flagship dual-PQ problem for this topic alongside median heaps.

## 9. Common Mistakes / Edge Cases
Not advancing time when all busy; wrong comparator; using task index as start without max(j,t).

## 10. Interview Follow-ups / Variations
Single-Threaded CPU (1834); Meeting Rooms II.

## 11. Tags
`heap`, `two-heaps`, `scheduling`, `leetcode-1882`, `difficulty:medium`
