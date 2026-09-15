# Skip List Range Query

## 1. Problem Statement
Return all keys in `[L,R]` from a skip list in order.

- **Inputs:** inserted keys; query bounds.
- **Output:** sorted keys in range.
- **Edges:** empty range; L/R outside data.

## 2. Intuition
Search to first ≥ L at bottom level, then walk next pointers while ≤ R.

## 3. Brute Force → Optimal
- **Brute:** scan all keys.
- **Skip:** O(log N + K) output-sensitive.

## 4. Data Structure / Approach Justification
**Chosen:** bottom-level traversal after finger search.

| Alternative | Note |
|-------------|------|
| Tree ordered iteration | Same asymptotics |
| Fenwick/segtree | Different API |

## 5. Logic Walkthrough
1. Descend to predecessor of L.
2. Walk `next[0]` collecting keys ≤ R.

## 6. Dry Run
Keys 1..5; `[2,4]` → 2,3,4.

## 7. Time & Space Complexity
Expected **O(log N + K)**.

## 8. Trade-offs & Alternatives
Natural for ordered maps.

## 9. Common Mistakes / Edge Cases
Starting from head without search; inclusive bounds off-by-one.

## 10. Interview Follow-ups / Variations
Count in range; sum aggregates.

## 11. Tags
`skip-list`, `range-query`, `lab`, `difficulty:medium`
