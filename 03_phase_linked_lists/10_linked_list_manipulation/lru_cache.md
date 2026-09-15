# LRU Cache

## 1. Problem Statement
[LeetCode 146](https://leetcode.com/problems/lru-cache/) — design a cache with capacity `C` supporting `get`/`put` in O(1); on overflow, evict the least recently used key.

- **Inputs:** capacity; sequence of `get(key)` / `put(key,value)`.
- **Output:** `get` returns value or `-1`; `put` updates/inserts with eviction.
- **Valid answer:** recency order updates on every successful `get`/`put`.
- **Edges:** capacity 1; update existing key; get miss; eviction after capacity.

## 2. Intuition
Need O(1) key lookup and O(1) move-to-front / evict-tail → hash map + doubly linked list.

## 3. Brute Force → Optimal
- **Brute:** vector/list scan for key and LRU — O(C) ops.
- **Optimal:** `unordered_map` + DLL with sentinels — O(1) get/put.

## 4. Data Structure / Approach Justification
**Chosen:** map `key → node*`; DLL ordered MRU (after `head_`) → LRU (before `tail_`).

| Alternative | Why we skip it here |
|-------------|---------------------|
| `std::list` + map of iterators | Same idea; explicit nodes teach splicing |
| Timestamp heap | Slower than O(1) and heavier |

## 5. Logic Walkthrough
1. `get`: map lookup; on hit, unlink and insert after `head_`.
2. `put`: update+move if present; else if full erase `tail_->prev` from list and map.
3. Insert new at head.

## 6. Dry Run
`capacity=2`: `put(1,1)`, `put(2,2)`, `get(1)` → 1 is MRU; `put(3,3)` evicts 2; `get(2)` → `-1`.

## 7. Time & Space Complexity
- **Time:** O(1) per `get`/`put`
- **Space:** O(C) for map + nodes

## 8. Trade-offs & Alternatives
`std::list` is shorter in production C++; interviews often want manual DLL.

## 9. Common Mistakes / Edge Cases
Evicting from list but not map (dangling get); capacity 0; updating value without moving to MRU.

## 10. Interview Follow-ups / Variations
LFU cache; TTL cache; thread-safe LRU.

## 11. Tags
`design`, `hash-map`, `doubly-linked-list`, `lru`, `leetcode-146`, `difficulty:medium`
