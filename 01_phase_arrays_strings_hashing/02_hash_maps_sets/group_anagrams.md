# Group Anagrams

## 1. Problem Statement
Group strings that are anagrams of each other.

- **Input:** `vector<string> strs`
- **Output:** `vector<vector<string>>` groups (order unconstrained)
- **Valid answer:** each group shares the same letter multiset
- **Edges:** empty strings; single group; all unique

## 2. Intuition
Anagrams share a canonical key — sorted characters (or a count signature).

## 3. Brute Force → Optimal
- **Brute:** pairwise `isAnagram` — O(N² · K).
- **Optimal:** hash map from key → list — one pass over N strings.

## 4. Data Structure / Approach Justification
`unordered_map<string, vector<string>>` keyed by sorted string.

| Alternative | Why it loses here |
|-------------|-------------------|
| Pairwise compare | Quadratic |
| Count-tuple key | Faster O(N·K), slightly more code |

## 5. Logic Walkthrough
1. For each string, copy and sort → `key`.
2. Append original to `groups[key]`.
3. Move map values into result vector.

## 6. Dry Run
`["eat","tea","tan","ate","nat","bat"]`
- `"aet"` → eat, tea, ate
- `"ant"` → tan, nat
- `"abt"` → bat  
→ **3 groups**

## 7. Time & Space Complexity
- **Time:** O(N · K log K) with sorted keys (K = max length)
- **Space:** O(N · K)
- Why: sort each string; store all strings in map.

## 8. Trade-offs & Alternatives
Sorted keys are simple. Count signature keys are O(N·K) and better for large K.

## 9. Common Mistakes / Edge Cases
Mutating the original when building the key; assuming group order matters.

## 10. Interview Follow-ups / Variations
Prefer 26-count key; unicode; stream grouping.

## 11. Tags
`hash-map`, `anagram`, `leetcode-49`, `medium`
