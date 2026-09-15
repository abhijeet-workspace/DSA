# Queue Reconstruction by Height

## Problem Statement
[LeetCode 406](https://leetcode.com/problems/queue-reconstruction-by-height/) — reconstruct queue from `[h, k]` where `k` is how many people in front are ≥ `h`.

- **Inputs:** list of `[height, k]` people.
- **Output:** reconstructed queue order.
- **Valid answer:** unique under problem constraints.
- **Edges:** all same height; `k=0` for tallest; single person.

## Intuition
Place tallest people first: their `k` is exactly the insert index among already-placed (taller) people; shorter people inserted later do not change taller counts.

## Brute Force → Optimal
- **Brute:** try all permutations — O(N!).
- **Optimal:** sort by height desc, insert at `k` — O(N²) with vector insert.

## Data Structure / Approach Justification
**Chosen:** sort tallest-first, `vector::insert` at index `k`.

- **vs linked list:** same insert idea, messier in C++ interviews.
- **vs fenwick empty slots:** O(N log N) advanced; overkill for LC N≤1100.

## Logic Walkthrough
Sort: height ↓, then `k` ↑. For each person, `insert` at position `k` in the growing queue.

## Dry Run
`[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]`: place 7s → `[7,0],[7,1]`; then 6 → insert at 1 → … ends **[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]**.

## Time & Space Complexity
Time **O(N²)** (inserts). Space **O(N)**. Why: each of N inserts can shift O(N) (section 4).

## Trade-offs & Alternatives
Indexed tree / fenwick for empty indices if N grows large.

## Common Mistakes / Edge Cases
Sorting shortest first; wrong tie-break on equal height; inserting at `k` among all vs among taller only.

## Interview Follow-ups / Variations
Reconstruct with left-and-right constraints; O(N log N) empty-slot method.

## Tags
`greedy`, `sorting`, `array`, `leetcode-406`, `difficulty:medium`
