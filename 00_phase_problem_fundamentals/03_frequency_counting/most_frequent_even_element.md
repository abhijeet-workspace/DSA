# Most Frequent Even Element

## 1. Problem Statement
[LeetCode 2404](https://leetcode.com/problems/most-frequent-even-element/) — Return the most frequent even element; ties → smallest value; none → `-1`.

- **Inputs:** `vector<int> nums`.
- **Output:** Even value or `-1`.
- **Edges:** No evens; tie on frequency; zeros.

## 2. Intuition
Count only evens; track best frequency and smallest value on ties.

## 3. Brute Force → Optimal
For each even distinct value recount. Map once.

## 4. Data Structure / Approach Justification
**Chosen:** counting bag for even keys.

A general `unordered_map` also works and is the idiomatic tool once topic 6 formalizes hashmap patterns. Here we prefer a **fixed alphabet/value table** where constraints allow, so the skill is "count occurrences," not "design a hash table API." When values are sparse we may still use `unordered_map` as a **counting bag** — framed as frequency storage, not as the Two Sum / Group Anagrams pattern unit.

## 5. Logic Walkthrough
1. Count evens.
2. Scan map for max freq, min value on tie.

## 6. Dry Run
[0,1,2,2,4,4,1] → 2 and 4 both freq 2 → choose 2.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(U)

## 8. Trade-offs & Alternatives
Dense array if value range is tiny.

## 9. Common Mistakes / Edge Cases
Picking largest on ties; counting odds.

## 10. Interview Follow-ups / Variations
Most frequent odd; top-k evens.

## 11. Tags
`array`, `frequency`, `leetcode-2404`, `difficulty:easy`
