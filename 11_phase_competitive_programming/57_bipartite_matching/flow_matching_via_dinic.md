# Flow Matching via Dinic

## 1. Problem Statement
Teaching lab — compute maximum bipartite matching as unit-capacity max flow with Dinic: `S→L→R→T`.

- **Inputs:** `nL`, `nR`, edges.
- **Output:** matching size (= max flow).
- **Edges:** no edges → 0; perfect matching.

## 2. Intuition
Each path S-L-R-T augments one match; Dinic blocking flows mirror Hopcroft phases on unit networks.

## 3. Brute Force → Optimal
- **Brute:** Kuhn.
- **Dinic on unit bipartite:** O(E√V) class.

## 4. Data Structure / Approach Justification
**Chosen:** Dinic template specialized to bipartite layout.

| Alternative | Note |
|-------------|------|
| Hopcroft–Karp | Dedicated |
| Ford–Fulkerson | Slower |

## 5. Logic Walkthrough
Build layered network; Dinic until no S–T path.

## 6. Dry Run
Edges covering both rights → flow `2`.

## 7. Time & Space Complexity
Time **O(E√V)** typical for unit. Space **O(V+E)**.

## 8. Trade-offs & Alternatives
Unifies matching with max-flow curriculum.

## 9. Common Mistakes / Edge Cases
Forgetting reverse edges; capacity >1 on L→R changing meaning.

## 10. Interview Follow-ups / Variations
Min-cut reconstruction; Konig from residual.

## 11. Tags
`dinic`, `max-flow`, `bipartite-matching`, `teaching`, `difficulty:hard`
