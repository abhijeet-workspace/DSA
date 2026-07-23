# First Negative Integer in Every Window of Size K

## Problem Statement
Classic sliding-window problem — for every contiguous window of size `k`, return the first negative integer in that window (or `0` if none).

- **Inputs:** `vector<int> arr`, `int k`.
- **Output:** vector of length `n - k + 1`.
- **Valid answer:** leftmost negative by index within each window.
- **Edges:** no negatives; all negatives; `k == 1`; `k == n`.

## Intuition
Negatives enter the window in order; the earliest one still inside the window is always at the front of a queue of negative indices.

## Brute Force → Optimal
- **Brute:** for each window, scan until first negative — O(NK).
- **Optimal:** deque of negative indices — O(N) time, O(K) space.

## Data Structure / Approach Justification
**Chosen:** `deque` storing indices of negatives only; front = first negative in window.

- **vs scanning each window:** same answer, worse asymptotics.
- **vs storing values:** indices needed to expire when `i - k` leaves.

## Logic Walkthrough
For each `i`: if `front == i - k`, pop; if `arr[i] < 0`, push `i`; once `i >= k - 1`, answer is `arr[front]` or `0`.

## Dry Run
`arr=[12,-1,-7,8,-15,30,16,28]`, `k=3`:
- windows: `[12,-1,-7]→-1`, `[-1,-7,8]→-1`, `[-7,8,-15]→-7`, … last `[30,16,28]→0`

## Time & Space Complexity
Time **O(N)**. Space **O(K)** worst case (all negatives). Why: each index enters/leaves deque once (section 4).

## Trade-offs & Alternatives
Same pattern as sliding-window maximum with a simpler monotonic rule (FIFO of negatives only). Two pointers + count also possible but less clean.

## Common Mistakes / Edge Cases
Returning `0` vs omitting the window; forgetting to expire `i - k`; pushing non-negatives.

## Interview Follow-ups / Variations
First positive; kth negative; count of negatives per window; combine with window maximum.

## Tags
`deque`, `sliding-window`, `queue`, `difficulty:easy`
