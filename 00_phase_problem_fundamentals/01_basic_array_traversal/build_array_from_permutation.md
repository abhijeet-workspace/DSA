# Build Array from Permutation

## 1. Problem Statement
[LeetCode 1920](https://leetcode.com/problems/build-array-from-permutation/) — `nums` is a permutation of `[0..n-1]`. Build `ans` where `ans[i] = nums[nums[i]]`.

- **Inputs:** `vector<int> nums` (permutation of `0..n-1`).
- **Output:** `vector<int> ans` of length `n`.
- **Edges:** `n = 1`; identity permutation; fully reversed.

## 2. Intuition
Each index stores another valid index — double indirection with one read per position.

## 3. Brute Force → Optimal
Same as optimal: must touch every `i`. In-place bit-packing tricks exist but obscure the lesson for this topic.

## 4. Data Structure / Approach Justification
**Chosen:** separate `ans` array; `ans[i] = nums[nums[i]]`.

| Alternative | Why it loses here |
|-------------|-------------------|
| In-place encode two values per cell | Clever O(1) extra space; harder to reason about for beginners |
| Recursion / visited marks | Unnecessary — no cycles to chase for the required output |

Plain indexing keeps the mental model: “index holds an index.”

## 5. Logic Walkthrough
1. Allocate `ans` size `n`.
2. For each `i`, set `ans[i] = nums[nums[i]]` (both indices in range by permutation).
3. Return `ans`.

## 6. Dry Run
`nums = [0,2,1,5,3,4]` → `ans[0]=0`, `ans[1]=1`, `ans[2]=2`, `ans[3]=4`, `ans[4]=5`, `ans[5]=3`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(N) for `ans` (O(1) extra)

## 8. Trade-offs & Alternatives
Follow-up “O(1) extra space” needs encoding; skip until bit tricks / cyclic-sort comfort.

## 9. Common Mistakes / Edge Cases
Treating `nums[i]` as an out-of-range value; mutating `nums` while reading nested indices.

## 10. Interview Follow-ups / Variations
Build in-place; related “recover permutation” puzzles.

## 11. Tags
`array`, `simulation`, `permutation`, `leetcode-1920`, `difficulty:easy`
