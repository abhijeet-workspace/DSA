# Stock Price Fluctuation (LC 2034)

## 1. Problem Statement
Track stock prices by timestamp with updates; support latest price, max, and min among current records.

- **Inputs:** `update(timestamp, price)`; queries max/min/current.
- **Output:** correct aggregates after corrections.
- **Valid answer:** [LC 2034](https://leetcode.com/problems/stock-price-fluctuation/).
- **Edges:** updating same timestamp; single record.
- **Persistence note:** not classic persistence — shows ordered multisets; contrast with versioned maps.
- **Link:** [LC 2034](https://leetcode.com/problems/stock-price-fluctuation/)

## 2. Intuition
Map timestamp→price; multisets of prices with lazy deletion when outdated.

## 3. Brute Force → Optimal
- **Brute:** scan map each query.
- **Better:** ordered multisets + hashmap.

## 4. Data Structure / Approach Justification
**Chosen:** `map` for time, `multiset` for prices, lazy erase on max/min.

| Alternative | Note |
|-------------|------|
| Two heaps | Similar lazy deletion |
| Persistent tree of prices | Overkill here |

## 5. Logic Walkthrough
1. On update, remove old price from multiset if present.
2. Insert new price; update latest timestamp.
3. Max/min = rbegin/begin after cleanup.

## 6. Dry Run
update(1,10), update(2,5), current=5, max=10; update(1,3) → max=5.

## 7. Time & Space Complexity
**O(log N)** per op.

## 8. Trade-offs & Alternatives
LC design problem; included for versioned-state intuition adjacent to persistence topic.

## 9. Common Mistakes / Edge Cases
Forgetting to delete old price; using wrong latest time.

## 10. Interview Follow-ups / Variations
Historical max at time t (needs persistence).

## 11. Tags
`design`, `multiset`, `lc-2034`, `difficulty:medium`
