# Detect Negative Cycle (Bellman–Ford)

## 1. Problem Statement
CP classic — decide whether a digraph has a negative cycle (Johnson prerequisite).

- **Inputs:** `n`, edge list.
- **Output:** true if negative cycle exists.
- **Edges:** unreachable cycle from a source (0-init catches any).

## 2. Intuition
After `|V|-1` relaxations, any further improvement ⇒ negative cycle.

## 3. Brute Force → Optimal
- **Floyd diagonal:** also detects.
- **BF:** O(VE), works sparse.

## 4. Data Structure / Approach Justification
**Chosen:** Bellman–Ford with zero initialization.

| Alternative | Note |
|-------------|------|
| Super-source BF | Same as Johnson step 1 |
| SPFA queue | Faster average, worse worst |

## 5. Logic Walkthrough
Relax |V|-1 rounds; one more pass for detection.

## 6. Dry Run
Cycle weight -1 → true; positive graph → false.

## 7. Time & Space Complexity
Time **O(VE)**. Space **O(V)**.

## 8. Trade-offs & Alternatives
First step of Johnson potentials.

## 9. Common Mistakes / Edge Cases
Only checking from one source missing remote cycles.

## 10. Interview Follow-ups / Variations
Report a cycle vertex set.

## 11. Tags
`bellman-ford`, `negative-cycle`, `cp`, `difficulty:medium`
