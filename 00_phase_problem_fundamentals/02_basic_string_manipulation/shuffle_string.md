# Shuffle String

## 1. Problem Statement
[LeetCode 1528](https://leetcode.com/problems/shuffle-string/) — Given string `s` and permutation `indices`, shuffle so the character at `s[i]` moves to position `indices[i]`.

- **Inputs:** `string s`, `vector<int> indices` (permutation of `0..n-1`).
- **Output:** Shuffled string.
- **Edges:** Identity permutation; `n = 1`.

## 2. Intuition
Same skill as array index placement: `ans[indices[i]] = s[i]`.

## 3. Brute Force → Optimal
Must write each character once — O(N) is required. Sorting `(index, char)` pairs is slower for no gain.

## 4. Data Structure / Approach Justification
**Chosen:** pre-sized `ans` and index writes.

| Alternative | Why it loses here |
|-------------|-------------------|
| Sort pairs `(indices[i], s[i])` | O(N log N); unnecessary |

Continues topic 1’s index-placement skill on characters.

## 5. Logic Walkthrough
1. Allocate `ans` length `n`.
2. For each `i`, `ans[indices[i]] = s[i]`.
3. Return `ans`.

## 6. Dry Run
`s = codeleet` with the given indices → `leetcode`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(N) output

## 8. Trade-offs & Alternatives
In-place cycle following is possible but harder; an extra string is clearer.

## 9. Common Mistakes / Edge Cases
Writing `ans[i] = s[indices[i]]` (inverted mapping).

## 10. Interview Follow-ups / Variations
In-place permute via cycles; apply inverse permutation.

## 11. Tags
`string`, `indexing`, `leetcode-1528`, `difficulty:easy`
