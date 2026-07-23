# Top K Frequent Elements

## 1. Problem Statement
Return the `k` most frequent elements in `nums` (order among ties unconstrained).

- **Input:** `vector<int> nums`, int `k`
- **Output:** `vector<int>` of size k
- **Valid answer:** k values with highest frequencies
- **Edges:** k == unique count; all equal; negatives

## 2. Intuition
Count frequencies, then place numbers into buckets indexed by count (bounded by N).

## 3. Brute Force → Optimal
- **Brute:** count then sort unique pairs — O(U log U).
- **Optimal:** bucket sort by frequency — O(N).

## 4. Data Structure / Approach Justification
`unordered_map` for counts + `vector<vector<int>>` buckets sized N+1.

| Alternative | Why it loses here |
|-------------|-------------------|
| Full sort of uniques | Extra log factor |
| Min-heap of size k | O(N log k); good when k ≪ N |

## 5. Logic Walkthrough
1. Count each value → `freq`.
2. Push value into `buckets[f]`.
3. Scan buckets from high frequency to low; collect until k.

## 6. Dry Run
`nums=[1,1,1,2,2,3]`, `k=2`
- freq: 1→3, 2→2, 3→1
- buckets[3]={1}, [2]={2}, [1]={3}
- scan high→low → `{1,2}`

## 7. Time & Space Complexity
- **Time:** O(N) average
- **Space:** O(N)
- Why: frequency ∈ [1..N] enables counting sort.

## 8. Trade-offs & Alternatives
Buckets are O(N) time/space. Heap is better when k ≪ N. Quickselect on counts also works.

## 9. Common Mistakes / Edge Cases
Off-by-one bucket index; assuming unique answer order; k larger than unique count (problem guarantees valid k).

## 10. Interview Follow-ups / Variations
Return sorted by frequency? Streaming / top-k online?

## 11. Tags
`bucket-sort`, `hash-map`, `leetcode-347`, `medium`
