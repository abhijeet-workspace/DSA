# Copy List with Random Pointer

## 1. Problem Statement
[LeetCode 138](https://leetcode.com/problems/copy-list-with-random-pointer/) — deep-copy a list where each node has `next` and `random` (to any node or null).

- **Inputs:** `Node* head` with `val`, `next`, `random`.
- **Output:** head of an independent deep copy.
- **Valid answer:** isomorphic `next`/`random` structure; no shared nodes.
- **Edges:** empty; all `random` null; `random` to self; dense cross links.

## 2. Intuition
Interleave each copy beside its original so `original->random->next` is the copied random target — no hash map required.

## 3. Brute Force → Optimal
- **Brute:** `unordered_map<Node*,Node*>` old→new, two passes — O(N) space.
- **Optimal:** weave / wire random / unweave — O(1) auxiliary (excluding output).

## 4. Data Structure / Approach Justification
**Chosen:** in-place interleaving of copy nodes.

| Alternative | Why we skip it here |
|-------------|---------------------|
| Hash map | Clearer, uses O(N) map memory |
| Recursion + map | Same map idea with stack cost |

## 5. Logic Walkthrough
1. After each `curr`, insert `copy`.
2. Set `copy.random = curr.random->next` when random exists.
3. Split odd/even positions into original and copy lists.

## 6. Dry Run
`7→13→11` with `13.random=7`, `11.random=13`:
- Weave: `7,7',13,13',11,11'`
- Wire: `13'.random=7'`, `11'.random=13'`
- Unweave restores originals and yields `7'→13'→11'`

## 7. Time & Space Complexity
- **Time:** O(N) (three linear passes)
- **Space:** O(1) auxiliary + O(N) for new nodes

## 8. Trade-offs & Alternatives
Hash map preferred if mutating the original list is forbidden mid-process; weave temporarily changes `next`.

## 9. Common Mistakes / Edge Cases
Forgetting null random; breaking original list on unweave; not handling empty head.

## 10. Interview Follow-ups / Variations
Clone graph; copy with only `next` (trivial); immutable original → must use map.

## 11. Tags
`linked-list`, `deep-copy`, `interleaving`, `hash-map-alt`, `leetcode-138`, `difficulty:medium`
