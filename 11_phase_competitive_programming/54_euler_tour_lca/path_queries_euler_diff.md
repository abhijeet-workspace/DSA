# Path Queries Euler Diff

## 1. Problem Statement
Teaching-lab — node-weighted **path sums** via Euler difference array (+val at enter, −val at exit).

- `rootSum(u)=prefix[in[u]]`; path via LCA formula.

## 2. Intuition
Tour difference makes subtree/root prefixes fenwick-friendly.

## 3. Brute Force → Optimal
- Climb summing. Euler+Fenwick for updates.

## 4. Data Structure / Approach Justification
**Chosen:** Euler diff + LCA path formula.

**Pedagogy:** framed for **Euler tour / LCA query machinery** (in/out times, RMQ, binary lifting). Tree-DFS topic may cover recursive LC 236; here we build CP-style offline/online tree query tools.

## 5. Logic Walkthrough
Build tour; prefix; LCA; combine.

## 6. Dry Run
path(3,2)=10; path(3,1)=6.

## 7. Time & Space Complexity
**O(n)** build; **O(n)** LCA climb here (use lifting in contests).

## 8. Trade-offs & Alternatives
Edge weights: put on child node.

## 9. Common Mistakes / Edge Cases
Forgetting +val[LCA].

## 10. Interview Follow-ups / Variations
Subtree update Euler.

## 11. Tags
`euler-tour`, `path-query`, `teaching-lab`, `difficulty:hard`

