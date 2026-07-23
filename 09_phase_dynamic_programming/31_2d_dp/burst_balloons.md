# Burst Balloons

## Problem Statement
[LeetCode 312](https://leetcode.com/problems/burst-balloons/) — maximize coins from bursting all balloons; bursting `i` yields `nums[i-1] * nums[i] * nums[i+1]` with boundaries treated as `1`.

- **Inputs:** `vector<int> nums` of balloon values.
- **Output:** maximum total coins.
- **Valid answer:** any burst order’s score; return the optimum.
- **Edges:** single balloon; all equal; length 1–n boundaries as 1.

## Intuition
Think in open intervals: the **last** balloon `k` burst inside `(l, r)` sees walls `nums[l]` and `nums[r]` still present. Subproblems on subintervals compose.

## Brute Force → Optimal
- **Brute:** try every burst permutation — O(N!) time.
- **Optimal:** interval DP over last-burst `k` — O(N³) time, O(N²) space.

## Data Structure / Approach Justification
**Chosen:** 2D `dp[l][r]` = best coins bursting balloons strictly between `l` and `r` (with sentinels).

- **vs recursion + memo only:** same asymptotics; bottom-up by length is clearer for interviews.
- **vs greedy (always burst min):** wrong — local choice misses global last-burst structure.

## Logic Walkthrough
Pad `nums` with `1` at both ends. For increasing `len`, for each `[l,r]`, try every `k` in `(l,r)`: `nums[l]*nums[k]*nums[r] + dp[l][k] + dp[k][r]`. Answer is `dp[0][n-1]`.

## Dry Run
`nums=[3,1,5,8]` → padded `[1,3,1,5,8,1]`. One optimal order ends with last interior burst yielding total **167** (classic LC example).

## Time & Space Complexity
Time **O(N³)** (length × left × last-burst). Space **O(N²)** for the table. Why: every open interval and every split (section 4).

## Trade-offs & Alternatives
Top-down memo matches complexity. No meaningful better asymptotics for classic formulation.

## Common Mistakes / Edge Cases
Forgetting sentinels; iterating closed intervals wrong; treating first-burst instead of last-burst; empty `nums`.

## Interview Follow-ups / Variations
Matrix chain multiplication; burst balloons with different scoring; reconstruct burst order.

## Tags
`interval-dp`, `2d-dp`, `leetcode-312`, `difficulty:hard`
