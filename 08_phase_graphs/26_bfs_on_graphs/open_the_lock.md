# Open the Lock

## 1. Problem Statement
[LeetCode 752](https://leetcode.com/problems/open-the-lock/) — 4-digit lock starting at `"0000"`. Each turn rotates one wheel ±1. Avoid `deadends`. Return minimum turns to `target`, or `-1`.

- **Inputs:** `deadends`, `target`.
- **Output:** min turns or -1.
- **Valid answer:** shortest path in the 10^4 state graph.
- **Edges:** target is start; start dead; unreachable.

## 2. Intuition
Each configuration is a graph node with 8 neighbors. BFS from `"0000"` yields minimum turns.

## 3. Brute Force → Optimal
- **Brute:** DFS depths — not shortest.
- **Optimal:** BFS O(states × 8) with visited/dead sets.

## 4. Data Structure / Approach Justification
**Chosen:** queue BFS + hash visited.

- **vs bidirectional BFS:** faster in practice for this problem.
- **vs A*:** unnecessary for tiny state space.

## 5. Logic Walkthrough
Enqueue start. Pop; if target return dist. Else push unseen non-dead neighbors at dist+1.

## 6. Dry Run
Sample deadends to `"0202"` → **6**.

## 7. Time & Space Complexity
Time **O(10^4)**. Space **O(10^4)**. Why: fixed state space (section 4).

## 8. Trade-offs & Alternatives
Bidirectional BFS from start and target.

## 9. Common Mistakes / Edge Cases
Not wrapping 0↔9; marking dead only at pop; forgetting start dead.

## 10. Interview Follow-ups / Variations
Sliding puzzle; word ladder; genetic mutation.

## 11. Tags
`bfs`, `shortest-path`, `leetcode-752`, `difficulty:medium`
