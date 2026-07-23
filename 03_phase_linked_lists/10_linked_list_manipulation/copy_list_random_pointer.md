# Copy List with Random Pointer

## Problem Statement
[LeetCode 138](https://leetcode.com/problems/copy-list-with-random-pointer/) — deep-copy a list where each node has `next` and `random` (to any node or null).

- **Inputs:** `Node* head` with `val`, `next`, `random`.
- **Output:** head of an independent deep copy.
- **Valid answer:** isomorphic `next`/`random` structure; no shared nodes.
- **Edges:** empty; all `random` null; `random` to self; dense cross links.

## Intuition
Interleave each copy beside its original so `original->random->next` is the copied random target — no hash map required.

## Brute Force → Optimal
- **Brute:** `unordered_map<Node*,Node*>` old→new, two passes — O(N) space.
- **Optimal:** weave / wire random / unweave — O(1) auxiliary (excluding output).

## Data Structure / Approach Justification
**Chosen:** in-place interleaving of copy nodes.

- **vs hash map:** clearer, uses O(N) map memory.
- **vs recursion + map:** same map idea with stack cost.

## Logic Walkthrough
1. After each `curr`, insert `copy`. 2. Set `copy.random = curr.random->next` when random exists. 3. Split odd/even positions into original and copy lists.

## Dry Run
`7→13→11` with `13.random=7`, `11.random=13`:
- Weave: `7,7',13,13',11,11'`
- Wire: `13'.random=7'`, `11'.random=13'`
- Unweave restores originals and yields `7'→13'→11'`

## Time & Space Complexity
Time **O(N)** (three linear passes). Space **O(1)** auxiliary + O(N) for new nodes. Why: adjacency encodes the map (section 4).

## Trade-offs & Alternatives
Hash map preferred if mutating the original list is forbidden mid-process; weave temporarily changes `next`.

## Common Mistakes / Edge Cases
Forgetting null random; breaking original list on unweave; not handling empty head.

## Interview Follow-ups / Variations
Clone graph; copy with only `next` (trivial); immutable original → must use map.

## Tags
`linked-list`, `deep-copy`, `interleaving`, `hash-map-alt`, `difficulty:medium`
