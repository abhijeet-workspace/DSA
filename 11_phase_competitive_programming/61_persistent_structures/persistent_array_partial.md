# Persistent Array (Partial / Path Copying)

## 1. Problem Statement
Support `set(version, index, value) -> newVersion` and `get(version, index)` on an array with path-copied segment tree.

- **Inputs:** initial array; updates creating versions; gets on any version.
- **Output:** values at historical versions.
- **Edges:** update same index twice; get on version 0.

## 2. Intuition
Segtree leaves hold values; each update copies O(log N) nodes.

## 3. Brute Force → Optimal
- **Brute:** copy entire array per update.
- **Persistent:** O(log N) per set/get.

## 4. Data Structure / Approach Justification
**Chosen:** persistent segment tree over indices.

| Alternative | Note |
|-------------|------|
| Rope / persistent vector | Different constants |
| Fat-node undo | Offline-friendly |

## 5. Logic Walkthrough
1. Build version 0 from array.
2. `upd` copies path to leaf.
3. `get` walks chosen root.

## 6. Dry Run
`[1,2,3]`; set v1 idx0=9; get(v0,0)=1, get(v1,0)=9.

## 7. Time & Space Complexity
**O(log N)** per op; space **O(log N)** per update.

## 8. Trade-offs & Alternatives
Simple and general; heavier than specialized structures.

## 9. Common Mistakes / Edge Cases
Mutating previous node; wrong leaf bounds.

## 10. Interview Follow-ups / Variations
Range assign; persistent fenwick (harder).

## 11. Tags
`persistent`, `array`, `segtree`, `difficulty:hard`
