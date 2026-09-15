# DSU Template

## 1. Problem Statement
Teaching-lab — Disjoint Set Union with path compression + union by size. Demo: edges connect `{0,1,2}` and `{3,4}`.

- **Output:** same component checks.

## 2. Intuition
Near-constant amortized connectivity queries after unions.

## 3. Brute Force → Optimal
- **Brute:** DFS/BFS per query.
- **Optimal:** DSU for offline/union-heavy graphs.

## 4. Data Structure / Approach Justification
**Chosen:** path compression + union by size.

**Pedagogy:** contest skeleton / teaching-lab — paste-ready CP snippet. Not a full contest statement; demos prove the template compiles and solves a tiny case. Full DS deep-dives live in Fenwick/SegTree/graph topics.

Full UF problems live in the Union-Find topic; this is the pasteable struct.

## 5. Logic Walkthrough
`find` compresses; `unite` attaches smaller root under larger.

## 6. Dry Run
After 0-1-2 and 3-4: `find(0)==find(2)`, `find(0)!=find(3)`.

## 7. Time & Space Complexity
Almost **O(α(n))** per op. Space **O(n)**.

## 8. Trade-offs & Alternatives
Union by rank equivalent; rollback DSU for offline divide-conquer.

## 9. Common Mistakes / Edge Cases
Forgetting to compare roots after find; 1-based indexing bugs.

## 10. Interview Follow-ups / Variations
Bipartite DSU; MST Kruskal wrapper.

## 11. Tags
`dsu`, `union-find`, `template`, `difficulty:easy`
