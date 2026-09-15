# Centroid Layers Build

## 1. Problem Statement
Teaching lab — build centroid decomposition and record the **layer** (depth in the centroid tree) of every node.

- **Inputs:** undirected tree.
- **Output:** `layer[v]` for all `v`.
- **Edges:** path (deeper layers); balanced tree (shallower).

## 2. Intuition
Each removal round places a centroid at the current depth; recursion on components increments depth. Depth is O(log N).

## 3. Brute Force → Optimal
- **Brute:** N/A beyond full CD.
- **Optimal:** standard CD O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** CD with `layer[c]=dep`.

| Alternative | Note |
|-------------|------|
| Only parent links | Enough for queries; layers help visualize balance |

## 5. Logic Walkthrough
`build(entry,dep)`: find centroid, set layer, mark dead, recurse `dep+1`.

## 6. Dry Run
Path of 5: middle node layer 0; ends deeper. All nodes get a non-negative layer.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**. Why: section 4.

## 8. Trade-offs & Alternatives
Layers diagnose whether decomposition is balanced.

## 9. Common Mistakes / Edge Cases
Not resetting `dead` between independent builds.

## 10. Interview Follow-ups / Variations
Store centroid parent + dist to ancestors for queries.

## 11. Tags
`centroid-decomposition`, `layers`, `teaching`, `cp`, `difficulty:medium`
