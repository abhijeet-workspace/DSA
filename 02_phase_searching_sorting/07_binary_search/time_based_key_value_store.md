# Time Based Key-Value Store

## Problem Statement
[LeetCode 981](https://leetcode.com/problems/time-based-key-value-store/) — `set(key, value, timestamp)` with strictly increasing timestamps per key; `get(key, timestamp)` returns value with largest `ts <= timestamp`, or `""`.

- **Inputs:** stream of sets/gets.
- **Output:** string from `get`.
- **Valid answer:** latest value not after query time.
- **Edges:** get before any set; exact timestamp; timestamp between sets.

## Intuition
Per key, store chronologically ordered `(timestamp, value)` pairs; binary search the rightmost `ts <= query`.

## Brute Force → Optimal
- **Brute:** scan pairs backward — O(N) per get.
- **Optimal:** map + binary search — O(log N) get.

## Data Structure / Approach Justification
**Chosen:** `unordered_map<string, vector<pair<int,string>>>`; BS for largest feasible index `ans`.

- **vs `map<int,string>` per key:** `upper_bound` works; vector + BS matches “timestamps increase” guarantee with less overhead.
- **vs linear:** slow under many gets.

## Logic Walkthrough
`set` appends. `get`: while `lo<=hi`, if `v[mid].first <= timestamp`, record `ans` and go right; else go left. Return `""` if `ans == -1`.

## Dry Run
`set("foo","bar",1)` → get(1)/get(3) = `"bar"`; `set(...,"bar2",4)` → get(4) = `"bar2"`.

## Time & Space Complexity
Time **O(1)** amortized set, **O(log N)** get. Space **O(total sets)**. Why: sorted appends + BS (section 4).

## Trade-offs & Alternatives
Tree map if timestamps are not guaranteed increasing on set.

## Common Mistakes / Edge Cases
Using first match instead of rightmost ≤; assuming key always exists; off-by-one on empty vector.

## Interview Follow-ups / Variations
Range queries; delete by timestamp; multiple values at same time.

## Tags
`binary-search`, `hash-map`, `design`, `difficulty:medium`
