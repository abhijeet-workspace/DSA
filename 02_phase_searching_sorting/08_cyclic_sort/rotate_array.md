# Rotate Array (Cycle Following)

## 1. Problem Statement
[LeetCode 189](https://leetcode.com/problems/rotate-array/) — rotate `nums` right by `k` steps in-place.

- **Inputs:** `vector<int>& nums`, `int k`.
- **Output:** array rotated right by `k % n`.
- **Edges:** `k = 0`; `k > n`; `n = 1`; already periodic.

## 2. Intuition
Index `i` maps to `(i + k) % n`. The permutation decomposes into `gcd(k, n)` cycles. Follow each cycle and rotate values along it — same “place value at home index” spirit as cyclic sort, but homes are modular.

## 3. Brute Force → Optimal
- **Brute:** rotate one step `k` times — O(Nk).
- **Extra array:** O(N) time, O(N) space.
- **Optimal in-place:** reverse three times, or **cycle following** — O(N)/O(1).

## 4. Data Structure / Approach Justification
**Chosen:** cycle decomposition for this folder’s index/cycle theme.

- **vs reverse method:** fewer lines; less explicit about cycles.
- **vs extra buffer:** clearer but uses O(N) space.

Also appears in fundamentals with the reverse framing; here we teach **cycle following**.

## 5. Logic Walkthrough
1. `k %= n`. Start cycle at each unused index `start`.
2. Hold `prev = nums[start]`; repeatedly `next = (cur + k) % n`, swap into `nums[next]`, until back at `start`.
3. Count placed elements; stop when all `n` moved.

## 6. Dry Run
`nums = [1,2,3,4,5,6,7]`, `k = 3`:
- cycle `0→3→6→2→5→1→4→0` moves all seven → `[5,6,7,1,2,3,4]`.

## 7. Time & Space Complexity
- **Time:** O(N) — each element moved once.
- **Space:** O(1).

## 8. Trade-offs & Alternatives
Reverse method is interview-favorite for brevity. Cycle method generalizes to arbitrary index permutations.

## 9. Common Mistakes / Edge Cases
Forgetting `k %= n`; starting a new cycle on an already-visited index; off-by-one on stop condition.

## 10. Interview Follow-ups / Variations
Left rotate; rotate linked list (61); array nesting (565) — follow index cycles without writing.

## 11. Tags
`cyclic-sort`, `array`, `cycle-following`, `leetcode-189`, `difficulty:medium`
