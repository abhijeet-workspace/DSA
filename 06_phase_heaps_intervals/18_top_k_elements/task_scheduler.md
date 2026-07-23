# Task Scheduler

## Problem Statement
[LeetCode 621](https://leetcode.com/problems/task-scheduler/) — minimum CPU intervals to finish all tasks with cooldown `n` between two identical tasks.

- **Inputs:** `vector<char> tasks` (uppercase letters), `int n` cooldown.
- **Output:** least units of time (tasks + forced idles).
- **Valid answer:** any valid schedule length; order of different tasks is free.
- **Edges:** n = 0 (no idle); one dominant task; many distinct tasks filling gaps.

## Intuition
The bottleneck is the most frequent task: you need `(max_freq - 1)` gaps of length `n` between its runs. Other tasks (and ties for max freq) fill those gaps; leftover empty slots become idle.

## Brute Force → Optimal
- **Brute / sim:** always schedule highest remaining count with cooldown tracking (heap) — O(time · 26 log 26).
- **Optimal math:** formula from max frequency — O(N) count + O(26).

## Data Structure / Approach Justification
**Chosen:** frequency array of size 26 + closed-form idle calculation.

- **vs priority-queue simulation:** same answer; formula is shorter and O(N).
- **vs greedy without counting max-ties:** undercounts when multiple tasks share `max_freq`.

## Logic Walkthrough
Count freqs → `max_freq`, `max_freq_count`.  
`empty_slots = (max_freq - 1) * (n - (max_freq_count - 1))`.  
`idles = max(0, empty_slots - available_other_tasks)`.  
Answer = `tasks.size() + idles`.

## Dry Run
`tasks=[A,A,A,B,B,B]`, `n=2`:
- `max_freq=3`, `max_freq_count=2` (A and B)
- `part_count=2`, `part_length=2-(2-1)=1`, `empty_slots=2`
- `available_tasks=6-3*2=0` → `idles=2`
- answer = 6+2 = **8** (e.g. A B idle A B idle A B)

## Time & Space Complexity
Time **O(N)**. Space **O(1)** (26 bins). Why: one pass over tasks + fixed alphabet scan (section 4).

## Trade-offs & Alternatives
Heap simulation is clearer if cooldown rules get more complex. Formula wins for this exact LC statement. If alphabet were huge, still O(U) after hashing.

## Common Mistakes / Edge Cases
Ignoring ties for max frequency; returning only idle count; assuming answer can be less than `tasks.size()`; n = 0.

## Interview Follow-ups / Variations
Reorganize string (767); CPU scheduling with priorities; return an actual schedule, not just length.

## Tags
`greedy`, `frequency`, `math`, `cooldown`, `leetcode-621`, `difficulty:medium`
