# Maximal Network Rank

## 1. Problem Statement
[LeetCode 1615](https://leetcode.com/problems/maximal-network-rank/) — undirected roads between `n` cities. Network rank of two cities = total roads incident to either, counting the shared road once. Return the maximal rank over all pairs.

- **Inputs:** `n`, `roads`.
- **Output:** max rank.
- **Valid answer:** max over pairs i<j.
- **Edges:** no roads; complete-ish graph.

## 2. Intuition
`rank(i,j)=deg[i]+deg[j]-(edge(i,j)?1:0)`. Brute all pairs after computing degrees and adjacency.

## 3. Brute Force → Optimal
- **Brute:** O(n²) pairs — fine for n≤100.
- **Optimal:** same; can optimize by sorting degrees but not required.

## 4. Data Structure / Approach Justification
**Chosen:** degree array + adjacency matrix.

- **vs set of edges:** slower lookups.

## 5. Logic Walkthrough
Build deg and conn. Enumerate pairs; track max formula.

## 6. Dry Run
Example n=4 → maximal rank **4**.

## 7. Time & Space Complexity
Time **O(n² + E)**. Space **O(n²)**. Why: pair enumeration (section 4).

## 8. Trade-offs & Alternatives
Hash set of edges if n large and sparse; still O(n²) pairs.

## 9. Common Mistakes / Edge Cases
Double-subtracting the shared edge; using directed edges.

## 10. Interview Follow-ups / Variations
Max rank of k cities; weighted roads.

## 11. Tags
`graph`, `degree`, `leetcode-1615`, `difficulty:medium`
