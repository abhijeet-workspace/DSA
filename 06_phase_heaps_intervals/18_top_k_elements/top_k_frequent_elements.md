# Top K Frequent Elements

## Problem Statement
[LeetCode 347](https://leetcode.com/problems/top-k-frequent-elements/) — return the k most frequent elements in `nums`.

- **Inputs:** `vector<int> nums`, `int k`.
- **Output:** any order of k values with the highest frequencies.
- **Valid answer:** problem guarantees a unique set of top-k answers.
- **Edges:** all unique (k frequencies = 1); one value dominates; negatives; k = 1 / k = distinct count.

## Intuition
First count frequencies, then select top-k counts — classic “top K” on `(frequency, value)` with a size-k min-heap.

## Brute Force → Optimal
- **Brute:** count then sort unique keys by frequency — O(U log U).
- **Optimal:** count + size-k min-heap — O(N + U log K).
- **Also:** bucket sort by frequency — O(N) time / O(N) space.

## Data Structure / Approach Justification
**Chosen:** `unordered_map` for counts + min-heap of size k on `{freq, value}`.

- **vs sort all uniques:** worse when K ≪ U.
- **vs bucket sort:** O(N) and often preferred if constraints allow frequency buckets `[0..N]`.
- **vs max-heap of all uniques:** O(U log U); size-k min-heap is tighter.

## Logic Walkthrough
Build `freq`. For each `(value, count)`, push `{count, value}` into `minHeap`; if size > k, pop. Drain heap values into `result`.

## Dry Run
`nums=[1,1,1,2,2,3,4,4,4,4]`, `k=2`:
- counts: `1→3`, `2→2`, `3→1`, `4→4`
- heap keeps highest freqs; after scan holds `{3,1}` and `{4,4}`
- result ≈ **[1, 4]** (order may vary)

## Time & Space Complexity
Time **O(N + U log K)**. Space **O(U + K)** for map + heap. Why: one count pass, then heap over U keys (section 4).

## Trade-offs & Alternatives
Heap is general and clear. Prefer frequency buckets when N is known and you want linear time. Prefer sort when U is tiny.

## Common Mistakes / Edge Cases
Heaping values instead of frequencies; max-heap of size k (wrong direction); assuming output must be sorted; empty / k larger than distinct (not in LC constraints).

## Interview Follow-ups / Variations
Top K frequent words (tie-break lexicographic); streaming / heavy hitters; return sorted by frequency.

## Tags
`heap`, `hash-map`, `top-k`, `frequency`, `leetcode-347`, `difficulty:medium`
