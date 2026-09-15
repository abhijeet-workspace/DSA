# Final Value of Variable After Performing Operations

## 1. Problem Statement
[LeetCode 2011](https://leetcode.com/problems/final-value-of-variable-after-performing-operations/) — Start with `X = 0`. Perform operations from `["++X","X++","--X","X--"]`. Return final `X`.

- **Inputs:** `vector<string> operations`.
- **Output:** Final integer value of `X`.
- **Edges:** Single op; all increments; mixed signs.

## 2. Intuition
Only the sign matters — every valid op changes `X` by ±1. In all four forms the middle character is `+` or `-`.

## 3. Brute Force → Optimal
Full string compare / parse is correct but noisier than reading `op[1]`.

## 4. Data Structure / Approach Justification
**Chosen:** scalar `x` and a single pass over operations.

| Alternative | Why it loses here |
|-------------|-------------------|
| `unordered_map` from string → delta | Overkill for four fixed ops |
| Regex / parsing | Unnecessary ceremony |

No fancy indexing — trains loop + branch hygiene on a simple sequence.

## 5. Logic Walkthrough
1. `x = 0`.
2. For each `op`, if `op[1] == '+'` then `++x` else `--x`.
3. Return `x`.

## 6. Dry Run
`["--X","X++","X++"]` → -1 → 0 → 1.

## 7. Time & Space Complexity
- **Time:** O(N) operations
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Counting `+` vs `-` then `plus - minus` is equivalent; per-op update is clearer.

## 9. Common Mistakes / Edge Cases
Checking only `op[0]` (breaks on `X++` / `X--`); assuming only prefix forms.

## 10. Interview Follow-ups / Variations
Ops with magnitudes; invalid op detection.

## 11. Tags
`array`, `string`, `simulation`, `leetcode-2011`, `difficulty:easy`
