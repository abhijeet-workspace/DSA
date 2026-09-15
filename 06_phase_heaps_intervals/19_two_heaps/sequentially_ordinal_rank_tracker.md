# Sequentially Ordinal Rank Tracker

## 1. Problem Statement
[LeetCode 2102](https://leetcode.com/problems/sequentially-ordinal-rank-tracker/) — design SORTracker: `add(name, score)`; `get()` on the i-th call returns the i-th best location (score desc, name asc).

- **Inputs:** stream of adds and gets.
- **Output:** name from each get.
- **Valid answer:** maintain dual ordered sets for top-i vs rest.
- **Edges:** ties on score; get after each add; more adds than gets.

## 2. Intuition
Like a moving order statistic: keep the best `queryCount` locations in one set and the rest in another; expand the “good” set on each get.

## 3. Brute Force → Optimal
- **Brute:** store all and sort each get — O(N log N) per get.
- **Optimal:** two balanced trees / heaps — O(log N) per op.

## 4. Data Structure / Approach Justification
**Chosen:** two `multiset`s as dual heaps with custom order.

- **vs one multiset + advance iterator:** also valid; dual sets mirror two-heaps median.

## 5. Logic Walkthrough
good = best `queryCount` items. On add: insert into good, spill worst to rest if oversized. On get: ++queryCount, pull best from rest into good, return the new boundary (queryCount-th).

## 6. Dry Run
add branford(3), bradford(2); get→branford; add alps(2); get→alps; …

## 7. Time & Space Complexity
Each op **O(log N)**. Space **O(N)**. Why: tree rebalance (section 4).

## 8. Trade-offs & Alternatives
True two-heap / dual-set design problem; excellent companion to MedianFinder.

## 9. Common Mistakes / Edge Cases
Wrong tie-break on names; off-by-one on queryCount; returning best instead of i-th.

## 10. Interview Follow-ups / Variations
Find Median from Data Stream (295); Finding MK Average (1825).

## 11. Tags
`heap`, `two-heaps`, `ordered-set`, `design`, `leetcode-2102`, `difficulty:hard`
