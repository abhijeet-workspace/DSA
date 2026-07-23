# LRU Cache

## Problem Statement
[LeetCode 146](https://leetcode.com/problems/lru-cache/) — design a cache with capacity `C` supporting `get`/`put` in O(1); on overflow, evict the least recently used key.

- **Inputs:** capacity; sequence of `get(key)` / `put(key,value)`.
- **Output:** `get` returns value or `-1`; `put` updates/inserts with eviction.
- **Valid answer:** recency order updates on every successful `get`/`put`.
- **Edges:** capacity 1; update existing key; get miss; eviction after capacity.

## Intuition
Need O(1) key lookup and O(1) move-to-front / evict-tail → hash map + doubly linked list.

## Brute Force → Optimal
- **Brute:** vector/list scan for key and LRU — O(C) ops.
- **Optimal:** `unordered_map` + DLL with sentinels — O(1) get/put.

## Data Structure / Approach Justification
**Chosen:** map `key → node*`; DLL ordered MRU (after `head_`) → LRU (before `tail_`).

- **vs `std::list` + map of iterators:** same idea; explicit nodes teach splicing.
- **vs timestamp heap:** slower than O(1) and heavier.

## Logic Walkthrough
`get`: map lookup; on hit, unlink and insert after `head_`. `put`: update+move if present; else if full erase `tail_->prev` from list and map; insert new at head.

## Dry Run
`capacity=2`: `put(1,1)`, `put(2,2)`, `get(1)` → 1 is MRU; `put(3,3)` evicts 2; `get(2)` → `-1`.

## Time & Space Complexity
Time **O(1)** per `get`/`put`. Space **O(C)** for map + nodes. Why: hash + constant-time DLL splice (section 4).

## Trade-offs & Alternatives
`std::list` is shorter in production C++; interviews often want manual DLL.

## Common Mistakes / Edge Cases
Evicting from list but not map (dangling get); capacity 0; updating value without moving to MRU.

## Interview Follow-ups / Variations
LFU cache; TTL cache; thread-safe LRU.

## Tags
`design`, `hash-map`, `doubly-linked-list`, `lru`, `difficulty:medium`
