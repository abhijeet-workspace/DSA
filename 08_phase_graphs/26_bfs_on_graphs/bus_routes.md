# Bus Routes

## 1. Problem Statement
[LeetCode 815](https://leetcode.com/problems/bus-routes/) — each `routes[i]` is a bus loop; find minimum buses to travel `source → target` (may transfer).

- **Inputs:** routes, source, target.
- **Output:** min buses or -1.
- **Valid answer:** taking a bus counts 1 regardless of stops ridden.
- **Edges:** source==target → 0; disconnected.

## 2. Intuition
Model BFS by stops, but mark buses visited so each route is taken at most once (levels = buses).

## 3. Brute Force → Optimal
- **Brute:** graph of stops with edges if same bus — huge.
- **Optimal:** map stop→buses; BFS stops; visit each bus once — O(Σ |route|).

## 4. Data Structure / Approach Justification
**Chosen:** `stopToBuses` + BFS queue of stops + seen buses.

- **vs BFS on bus nodes:** also valid.

## 5. Logic Walkthrough
From current stops, board unseen buses, enqueue all their stops; each layer +1 bus.

## 6. Dry Run
1→ bus0 →7→ bus1 →6 costs 2.

## 7. Time & Space Complexity
Time **O(Σ S)**. Space **O(Σ S)**.

## 8. Trade-offs & Alternatives
Bidirectional BFS for large instances.

## 9. Common Mistakes / Edge Cases
Counting stops instead of buses; revisiting buses.

## 10. Interview Follow-ups / Variations
Cheapest flights within K stops; subway transfers.

## 11. Tags
`bfs`, `graph`, `leetcode-815`, `difficulty:hard`
