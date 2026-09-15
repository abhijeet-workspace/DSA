# Single Number II

## 1. Problem Statement
[LeetCode 137](https://leetcode.com/problems/single-number-ii/) — every element appears three times except one; find the single in linear time and constant space.

- **Inputs:** `vector<int> nums`.
- **Output:** the unique integer.
- **Valid answer:** the singleton.
- **Edges:** negatives; singleton first/last; zeros appearing thrice.

## 2. Intuition
Track bits in base-3: after three sightings a bit returns to 0. `ones`/`twos` are a 2-bit FSM per bit; XOR with masks implements the transitions.

## 3. Brute Force → Optimal
- **Brute:** hash map counts — O(N) space.
- **Alt:** 32 counters of bit occurrences `% 3` — O(32N), O(1) space.
- **Optimal here:** ones/twos bitmasks — O(N), O(1).

## 4. Data Structure / Approach Justification
**Chosen:** `ones`/`twos` finite-state update.

- **vs bit-count arrays:** easier to explain; slightly more code.
- **vs sort:** O(N log N), violates spirit of bit puzzle.

## 5. Logic Walkthrough
For each `n`: `ones = (ones^n) & ~twos`; `twos = (twos^n) & ~ones`. Return `ones`.

## 6. Dry Run
`[2,2,3,2]`: after three `2`s state clears; `3` remains in `ones` → **3**.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: constant-width bit state (section 4).

## 8. Trade-offs & Alternatives
Bit-count `% 3` is clearer in interviews if FSM confuses; same asymptotics.

## 9. Common Mistakes / Edge Cases
Using plain XOR (works only for pairs); sign bit / negatives with naive sum tricks; updating `twos` before masking with new `ones` incorrectly.

## 10. Interview Follow-ups / Variations
Appears k times (generalize FSM); two singles (260); Single Number I (136).

## 11. Tags
`bit-manipulation`, `finite-state`, `leetcode-137`, `difficulty:medium`
