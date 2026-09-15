# Snapshot Array (LC 1146)

## 1. Problem Statement
Implement an array that supports `set`, `snap`, and `get` at a historical snap id.

- **Inputs:** length; sequence of set/snap/get.
- **Output:** `get(index, snap_id)` values.
- **Valid answer:** [LC 1146](https://leetcode.com/problems/snapshot-array/).
- **Edges:** snap without changes; multiple sets before snap; large snap ids.
- **Link:** [LC 1146](https://leetcode.com/problems/snapshot-array/)

## 2. Intuition
Per index, store a timeline of (snap_id, value); binary search last change ≤ snap_id.

## 3. Brute Force → Optimal
- **Brute:** copy whole array each snap.
- **Better:** sparse history per index.

## 4. Data Structure / Approach Justification
**Chosen:** `vector<vector<pair<snap,val>>>` + upper_bound.

| Alternative | Note |
|-------------|------|
| Persistent segtree | Heavier, also correct |
| Copy-on-write pages | Systems flavor |

## 5. Logic Walkthrough
1. `set` records value at current snap id.
2. `snap` increments id.
3. `get` binary-searches history.

## 6. Dry Run
set(0,5); snap→0; set(0,6); get(0,0)→5.

## 7. Time & Space Complexity
**O(log S)** get; **O(1)** amortized set. Space **O(#sets)**.

## 8. Trade-offs & Alternatives
Simple LC solution; persistent trees teach deeper CP ideas.

## 9. Common Mistakes / Edge Cases
Storing snap after increment wrong; missing initial zeros.

## 10. Interview Follow-ups / Variations
Range snap queries; persistent tree implementation.

## 11. Tags
`snapshot`, `binary-search`, `lc-1146`, `persistent-adjacent`, `difficulty:medium`
