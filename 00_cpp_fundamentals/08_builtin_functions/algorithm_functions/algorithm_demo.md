# Algorithm Demo (`<algorithm>`, `<numeric>`)

## Problem Statement
Demonstrate common STL algorithms on two practical tasks:
1. **Audit** a price list: total, min, max, and clamped tax.
2. **Query** warehouse stock codes with sort + binary search.

**Inputs:** `vector<double>` prices; `vector<int>` stock codes + query code.  
**Valid answer:** printed audit stats; `AVAILABLE`/`OUT OF STOCK` with index when found.  
**Edges:** empty range (min/max UB — assume non-empty), duplicates in codes, missing query.

## Intuition
STL algorithms encode “what” (sum, extremum, search) without hand-rolled loops. Once data is sorted, binary search answers membership in logarithmic time.

## Brute Force → Optimal
- **Brute:** loop for sum/min/max; linear scan for each stock query → O(Q·N).
- **Optimal:** `accumulate` / `min_element` / `max_element` / `clamp`; one `sort` then `binary_search` / `lower_bound` → O(N log N + Q log N).

## Data Structure / Approach Justification (REQUIRED)
Use `std::vector` as a contiguous random-access range — required by `sort`, `binary_search`, and iterator algorithms.
- **vs `std::list`:** no random access; binary search unavailable / slower.
- **vs `std::set`:** auto-sorted lookups O(log N), but audit needs a flat numeric range for accumulate/min/max in one pass over a bag of prices; vector matches that access pattern.

## Logic Walkthrough
- `auditTransactions`: `accumulate` → `total`; `min_element`/`max_element` → iterators; `clamp(tax, 5, 50)` bounds payment.
- `queryWarehouse`: `sort` codes; `binary_search` for existence; `lower_bound` + `distance` for first index of `queryCode`.
- `main`: `swap`, `gcd`, then both demos.

## Dry Run
Prices `{12.99, 45.50, 8.25, 125.00, 22.10}` → total ≈ 213.84; min 8.25; max 125; tax ≈ 32.08 (already in [5,50]).  
Codes sorted → `{1024,1024,4532,7701,8821,9901}`; query `1024` → AVAILABLE at index 0; `5000` → OUT OF STOCK.

## Time & Space Complexity
- Audit: **O(N)** time, **O(1)** extra space.
- Warehouse: **O(N log N)** sort + **O(log N)** per query; **O(1)**–**O(log N)** stack for sort.
Why: contiguous vector enables IntroSort and binary search (section 4).

## Trade-offs & Alternatives
Keep a `std::set`/`unordered_set` if membership is the only query and order doesn’t matter. Prefer `stable_sort` if relative order of equal codes matters.

## Common Mistakes / Edge Cases
Calling `binary_search` on unsorted data; forgetting `lower_bound` needs sorted range; empty `prices` with `min_element` is UB.

## Interview Follow-ups / Variations
Multi-query without re-sorting; `upper_bound` for ranges; custom comparators; parallel `transform_reduce`.

## Tags
`stl`, `algorithm`, `numeric`, `binary-search`, `beginner`
