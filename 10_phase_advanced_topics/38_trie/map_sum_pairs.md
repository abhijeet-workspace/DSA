# Map Sum Pairs

## 1. Problem Statement
[LeetCode 677](https://leetcode.com/problems/map-sum-pairs/) — design `MapSum` with `insert(key, val)` and `sum(prefix)` = sum of values of all keys with that prefix. Re-inserting a key overwrites its value.

- **Inputs:** lowercase keys; integer values; prefix queries.
- **Output:** prefix sum integers.
- **Valid answer:** after overwrite, old value must not remain in sums.
- **Edges:** missing prefix → 0; key equals prefix; overwrite same key.

## 2. Intuition
Store running `prefixSum` on each trie node. On insert, add `delta = new - old` along the key path so overwrites stay correct.

## 3. Brute Force → Optimal
- **Brute:** hash map of all keys; scan matching prefixes each query.
- **Optimal:** trie with aggregated prefix sums — O(L) per op.

## 4. Data Structure / Approach Justification
**Chosen:** trie node `prefixSum` + `unordered_map` of last values for deltas.

- **vs store only leaf values and DFS sum:** slower queries.
- **vs Fenwick on compressed keys:** heavier for strings.

## 5. Logic Walkthrough
`insert`: compute delta vs previous value; walk/create nodes; add delta to each. `sum`: walk prefix; return node’s `prefixSum` or 0.

## 6. Dry Run
`insert("apple",3)`; `sum("ap")`→3; `insert("app",2)`; `sum("ap")`→5; `insert("apple",2)`; `sum("ap")`→4.

## 7. Time & Space Complexity
Per op **O(L)**. Space **O(total chars)**. Why: path updates only (section 4).

## 8. Trade-offs & Alternatives
Keeping value only at end and summing subtree is simpler but O(subtree) per query.

## 9. Common Mistakes / Edge Cases
Adding full new value on overwrite without subtracting old; putting sum only at leaf; not handling missing prefix.

## 10. Interview Follow-ups / Variations
Delete key; count of keys with prefix; unicode alphabet.

## 11. Tags
`trie`, `design`, `prefix-sum`, `leetcode-677`, `difficulty:medium`
