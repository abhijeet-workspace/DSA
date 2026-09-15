# Functional Update Path-Copying Demo

## 1. Problem Statement
Minimal demo of functional/persistent tree update: binary tree of values, `set` returns new root sharing structure.

- **Inputs:** small fixed-shape tree; updates at leaf indices.
- **Output:** old and new roots yield different leaf values.
- **Edges:** update root-only path; multiple branches.

## 2. Intuition
Purely functional languages update trees by allocating new spine nodes.

## 3. Brute Force → Optimal
- **Brute:** clone all nodes.
- **Path copy:** O(height) new nodes.

## 4. Data Structure / Approach Justification
**Chosen:** explicit `Node{left,right,val}` pool with `setLeaf`.

| Alternative | Note |
|-------------|------|
| In-place mutate | Destroys history |
| Fat nodes | Store versions inside node |

## 5. Logic Walkthrough
1. Build full binary tree over array.
2. `set` copies nodes from root to leaf.
3. Compare queries on both roots.

## 6. Dry Run
Tree over `[1,2,3,4]`; set index 0 to 9; old root still 1.

## 7. Time & Space Complexity
**O(height)** time/space per update.

## 8. Trade-offs & Alternatives
Clearest mental model for persistence.

## 9. Common Mistakes / Edge Cases
Aliasing children without copy; wrong leaf index.

## 10. Interview Follow-ups / Variations
Generalize to segtree; hash-consing.

## 11. Tags
`path-copying`, `persistent`, `functional`, `lab`, `difficulty:medium`
