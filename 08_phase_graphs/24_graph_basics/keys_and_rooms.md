# Keys and Rooms

## 1. Problem Statement
[LeetCode 841](https://leetcode.com/problems/keys-and-rooms/) — `rooms[i]` lists keys in room `i`. Start at room 0. Return true if you can enter every room.

- **Inputs:** adjacency-like `rooms`.
- **Output:** bool.
- **Valid answer:** all rooms reachable from 0 via keys.
- **Edges:** one room; keys to self; unreachable room.

## 2. Intuition
Treat rooms as nodes and keys as directed edges; BFS/DFS reachability from 0; compare visit count to `n`.

## 3. Brute Force → Optimal
- **Brute/Optimal:** one traversal O(n+E).

## 4. Data Structure / Approach Justification
**Chosen:** BFS with visited flags.

- **vs DFS:** identical reachability.

## 5. Logic Walkthrough
Start queue with 0. For each room, enqueue unused keys/rooms. Success if `seen==n`.

## 6. Dry Run
`[[1],[2],[3],[]]` visits all → true. Example with room 2 locked → false.

## 7. Time & Space Complexity
Time **O(n+E)**. Space **O(n)**. Why: each room/key once (section 4).

## 8. Trade-offs & Alternatives
Stack DFS; bitset visited for tiny n.

## 9. Common Mistakes / Edge Cases
Not starting at 0; counting keys not rooms; missing empty room lists.

## 10. Interview Follow-ups / Variations
Minimum keys to collect; open locks with costs.

## 11. Tags
`graph`, `dfs`, `bfs`, `leetcode-841`, `difficulty:medium`
