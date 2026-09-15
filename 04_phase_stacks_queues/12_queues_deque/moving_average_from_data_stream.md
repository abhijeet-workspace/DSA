# Moving Average from Data Stream

## 1. Problem Statement
[LeetCode 346](https://leetcode.com/problems/moving-average-from-data-stream/) — given window size `size`, `next(val)` returns the average of the last at most `size` values.

- **Inputs:** constructor `size`; stream of `next` calls.
- **Output:** double average of current window.
- **Edges:** first call; window not full; exact capacity.

## 2. Intuition
Keep a FIFO of the last `size` values and a running sum; when full, subtract the leaving front before adding the new value.

## 3. Brute Force → Optimal
- **Brute:** store all history and rescan last `size` — O(size) per call.
- **Optimal:** queue + running sum — O(1) per call.

## 4. Data Structure / Approach Justification
**Chosen:** `queue` + `sum` / `count`.

| Alternative | Why |
|-------------|-----|
| Circular array of `size` | Same asymptotics; less allocation churn |
| Prefix sums of full stream | Extra memory |

## 5. Logic Walkthrough
1. If `q.size() == size`, `sum -= q.front()`, pop.
2. Push `val`, `sum += val`.
3. Return `sum / q.size()`.

## 6. Dry Run
`size=3`: `next(1)`→1; `next(10)`→5.5; `next(3)`→4.666…; `next(5)` drops 1 → 6.

## 7. Time & Space Complexity
- **Time:** O(1) per `next`
- **Space:** O(size)

## 8. Trade-offs & Alternatives
Integer sum may overflow for large streams — use `long long` / `double` carefully.

## 9. Common Mistakes / Edge Cases
Dividing by `size` before the window is full; forgetting to subtract the evicted value.

## 10. Interview Follow-ups / Variations
Weighted moving average; hit counter; recent calls.

## 11. Tags
`queue`, `design`, `sliding-window`, `leetcode-346`, `difficulty:easy`
