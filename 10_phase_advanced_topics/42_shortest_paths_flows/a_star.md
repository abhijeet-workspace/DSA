# A* Search

## Problem Statement
Find a shortest path on a grid (or graph) from `start` to `goal` using  
`f(n) = g(n) + h(n)`, where `g` is cost so far and `h` is an admissible heuristic estimate.

- **Inputs:** grid (0 free / 1 wall), start, goal.
- **Output:** path length (unit steps), or `-1` if blocked.
- **Edges:** start/goal blocked; no path; heuristic must not overestimate.

## Intuition
Dijkstra expands by `g` only. A* biases expansion toward the goal using `h`, so fewer nodes are opened when `h` is informative and admissible.

## Brute Force → Optimal
- **Brute:** BFS/Dijkstra on the grid.
- **A*:** same optimality as Dijkstra when `h` is admissible (and consistent → efficient); often fewer expansions.

## Data Structure / Approach Justification
**Chosen:** min-heap on `f`, Manhattan distance heuristic (admissible for 4-directional unit grids).

- **vs Dijkstra:** Dijkstra is A* with `h=0`.
- **vs greedy best-first:** greedy uses `h` only and is not optimal.

## Logic Walkthrough
Push start with `g=0`, `f=h(start)`. Pop lowest `f`. For each free neighbor, relax `g` and push with updated `f`. Stop when goal is dequeued.

## Dry Run
Small 4×4 grid with walls: path snakes around blockers → length **6**.

## Time & Space Complexity
Worst **O(V log V)** like Dijkstra on the state space. Better in practice with a tight heuristic. Space **O(V)**.

## Trade-offs & Alternatives
Bad heuristics → behaves like Dijkstra. Inadmissible `h` can find suboptimal paths faster (weighted A*).

## Common Mistakes / Edge Cases
Inadmissible heuristic; not skipping stale heap entries; diagonal moves with Manhattan (use Chebyshev / octile instead).

## Interview Follow-ups / Variations
Path reconstruction; 8-connected grids; consistent vs admissible; IDA*.

## Tags
`graph`, `a-star`, `heuristic`, `shortest-path`, `difficulty:medium`
