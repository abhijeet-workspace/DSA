# Detect Squares

## Problem Statement
[LeetCode 2013](https://leetcode.com/problems/detect-squares/) — support `add(point)` and `count(point)`: how many axis-aligned squares use the query point as one corner among added points (with multiplicity).

- **Inputs:** points with integer coords in a plane.
- **Output:** `add` void; `count` integer combinations.
- **Valid answer:** axis-aligned squares only; duplicate points multiply counts.
- **Edges:** collinear points; no diagonal partner; repeated adds.

## Intuition
A square’s opposite corner is a diagonal. For each stored point as diagonal partner of the query, the other two corners are determined; multiply frequencies.

## Brute Force → Optimal
- **Brute:** store all points in a list; for count, try all triples — too slow.
- **Optimal:** frequency map of points; for each candidate diagonal, O(1) lookup of the other two corners → O(N) per count.

## Data Structure / Approach Justification
**Chosen:** `unordered_map<long long,int>` packing `(x,y)` into one key.

- **vs `map<pair>` / nested maps:** same idea; packing is lighter and hash-friendly.
- **vs list of points only:** count becomes O(N³) or O(N²) with weaker pruning.

## Logic Walkthrough
`add`: increment `cnt[key(x,y)]`. `count(x,y)`: for each `(px,py)` with count `c`, skip same row/col; require `|px-x|==|py-y|`; add `c * cnt[(px,y)] * cnt[(x,py)]`.

## Dry Run
Add `(3,10)`, `(11,2)`, `(3,2)`; `count(11,10)` → diagonal `(3,2)` forms square with `(3,10)` and `(11,2)` → **1**.

## Time & Space Complexity
`add` **O(1)** average. `count` **O(N)** over stored distinct keys. Space **O(N)**. Why: hash frequencies + one diagonal scan (section 4).

## Trade-offs & Alternatives
Nested `x -> (y -> count)` maps avoid bit packing but more verbose. Exact square length filter same asymptotics.

## Common Mistakes / Edge Cases
Counting same-row points as corners; forgetting multiplicity; signed/unsigned packing bugs in `key`.

## Interview Follow-ups / Variations
Only unit squares; delete points; count rectangles (relax equal-side).

## Tags
`geometry`, `hash-map`, `design`, `difficulty:medium`
