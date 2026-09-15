# First Negative Integer in Every Window of Size K

## 1. Problem Statement
Classic sliding-window problem (GFG) — for every contiguous window of size `k`, return the first negative integer in that window (or `0` if none).

- **Inputs:** `vector<int> arr`, `int k`.
- **Output:** vector of length `n - k + 1`.
- **Valid answer:** leftmost negative by index within each window.
- **Edges:** no negatives; all negatives; `k == 1`; `k == n`.

## 2. Intuition
Negatives enter the window in order; the earliest one still inside the window is always at the front of a queue of negative indices.

## 3. Brute Force → Optimal
- **Brute:** for each window, scan until first negative — O(NK).
- **Optimal:** deque of negative indices — O(N) time, O(K) space.

## 4. Data Structure / Approach Justification
**Chosen:** `deque` storing indices of negatives only; front = first negative in window.

| Alternative | Why not |
|-------------|---------|
| Scan each window | Same answer, worse asymptotics |
| Store values only | Indices needed to expire when `i - k` leaves |

## 5. Logic Walkthrough
1. For each `i`: if `front == i - k`, pop.
2. If `arr[i] < 0`, push `i`.
3. Once `i >= k - 1`, answer is `arr[front]` or `0`.

## 6. Dry Run
`arr=[12,-1,-7,8,-15,30,16,28]`, `k=3`:
- windows: `[12,-1,-7]→-1`, `[-1,-7,8]→-1`, `[-7,8,-15]→-7`, … last `[30,16,28]→0`

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(K) worst case (all negatives)

## 8. Trade-offs & Alternatives
Same pattern as sliding-window maximum with a simpler monotonic rule (FIFO of negatives only).

## 9. Common Mistakes / Edge Cases
Returning `0` vs omitting the window; forgetting to expire `i - k`; pushing non-negatives.

## 10. Interview Follow-ups / Variations
First positive; kth negative; count of negatives per window; combine with window maximum.

## 11. Tags
`deque`, `sliding-window`, `queue`, `difficulty:easy`
