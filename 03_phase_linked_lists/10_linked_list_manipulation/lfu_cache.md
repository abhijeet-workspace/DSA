# LFU Cache

## 1. Problem Statement
[LeetCode 460](https://leetcode.com/problems/lfu-cache/) — capacity-bounded cache with O(1) `get`/`put`; evict LFU, break ties by LRU.

- **Inputs:** capacity; get/put ops.
- **Output:** get value or -1; put may evict.
- **Valid answer:** frequency increments on get/put hit; new keys start at freq 1.
- **Edges:** capacity 0; update existing; many same freq.

## 2. Intuition
Map key→(val,freq); map freq→ordered list of keys (MRU front); track minFreq for eviction.

## 3. Brute Force → Optimal
- **Brute:** scan all keys for min freq — O(C).
- **Optimal:** freq buckets + minFreq — O(1).

## 4. Data Structure / Approach Justification
**Chosen:** three hash maps + `list` per frequency.

| Alternative | Why we skip it here |
|-------------|---------------------|
| Two heaps | Not O(1) |
| Only LRU | Wrong eviction policy |

## 5. Logic Walkthrough
1. `touch` moves key from freq list to freq+1.
2. On insert at full capacity, pop back of `minFreq` list.
3. Insert new key at freq 1; update `minFreq` when a bucket empties.

## 6. Dry Run
cap=2: put1, put2, get1 → freq1=2; put3 evicts key2 (freq1 LRU).

## 7. Time & Space Complexity
- **Time:** O(1) amortized per op
- **Space:** O(C)

## 8. Trade-offs & Alternatives
Manual DLL like LRU if avoiding `std::list`.

## 9. Common Mistakes / Edge Cases
Not updating minFreq when a freq bucket empties; capacity 0.

## 10. Interview Follow-ups / Variations
LRU (146); LFU with TTL.

## 11. Tags
`design`, `hash-map`, `doubly-linked-list`, `lfu`, `leetcode-460`, `difficulty:hard`
