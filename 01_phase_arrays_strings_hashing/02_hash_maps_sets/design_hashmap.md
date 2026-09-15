# Design HashMap

## Problem Statement
[LeetCode 706](https://leetcode.com/problems/design-hashmap/) — implement `put`, `get`, `remove` without built-in hash maps.

- **Inputs:** non-negative keys/values.
- **Output:** get returns value or `-1`.
- **Edges:** overwrite; remove missing; many collisions.

## Intuition
Array of buckets; each bucket is a chain of `(key,value)` pairs.

## Brute Force → Optimal
- **Brute:** single list — O(N) ops.
- **Optimal:** fixed buckets + chaining — average O(1).

## Data Structure / Approach Justification
**Chosen:** 1009 buckets of `list<pair>`.

- **vs open addressing:** harder delete.
- **vs BST per bucket:** overkill for interview.

## Logic Walkthrough
Hash `key % BUCKETS`, scan chain for key on put/get/remove.

## Dry Run
put(1,1), put(2,2), get(1)=1, put(2,1) overwrites, remove(2), get(2)=-1.

## Time & Space Complexity
Time **O(1)** average. Space **O(N + B)**.

## Trade-offs & Alternatives
Dynamic rehashing improves load factor; not required by LC.

## Common Mistakes / Edge Cases
Not updating on put; removing wrong node in chain.

## Interview Follow-ups / Variations
Design HashSet; thread-safe map; open addressing.

## Tags
`design`, `hash-map`, `difficulty:easy`
