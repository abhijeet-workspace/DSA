# Tree Distance Via LCA

## 1. Problem Statement
Teaching-lab — unweighted tree distance via LCA depths.

## 2. Intuition
Unique path goes through LCA.

## 3. Brute Force → Optimal
- BFS per query. LCA prep + O(1)/O(log) queries.

## 4. Data Structure / Approach Justification
**Chosen:** depth + climb LCA.

**Pedagogy:** framed for **Euler tour / LCA query machinery** (in/out times, RMQ, binary lifting). Tree-DFS topic may cover recursive LC 236; here we build CP-style offline/online tree query tools.

## 5. Logic Walkthrough
DFS depths; distance formula.

## 6. Dry Run
dist(3,4)=4.

## 7. Time & Space Complexity
**O(n)** prep; **O(n)** query climb (lifting → log).

## 8. Trade-offs & Alternatives
Weighted: use root distances.

## 9. Common Mistakes / Edge Cases
Wrong formula forgetting *2.

## 10. Interview Follow-ups / Variations
Binary lifting LCA.

## 11. Tags
`lca`, `distance`, `teaching-lab`, `difficulty:easy`

