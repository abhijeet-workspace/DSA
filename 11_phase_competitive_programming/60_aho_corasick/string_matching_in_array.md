# String Matching in an Array (LC 1408)

## 1. Problem Statement
Return all strings in `words` that are a substring of some other string in the array.

- **Inputs:** `words[]` of distinct lowercase strings (per LC constraints typically).
- **Output:** list of such strings (any order).
- **Valid answer:** [LC 1408](https://leetcode.com/problems/string-matching-in-an-array/).
- **Edges:** no matches; nested substrings; equal lengths.
- **Link:** [LC 1408](https://leetcode.com/problems/string-matching-in-an-array/)

## 2. Intuition
Small n allows O(n²) `find`. AC of all words scanned over concatenations is valid but overkill.

## 3. Brute Force → Optimal
- **Brute:** for each pair i≠j, check if words[i] is substring of words[j].
- **AC:** insert all, run each word as text — heavier.

## 4. Data Structure / Approach Justification
**Chosen:** nested loops with `string::find` (fits LC constraints).

| Alternative | Note |
|-------------|------|
| Aho-Corasick | Good teaching when n and lengths grow |
| Sort by length | Optional micro-opt |

## 5. Logic Walkthrough
1. For each word i, scan other words.
2. If found as substring, collect and break.

## 6. Dry Run
`{mass,as,hero,superhero}` → `as`, `hero`.

## 7. Time & Space Complexity
**O(n² · L²)** with naive find; fine for small LC limits. Space **O(1)** extra.

## 8. Trade-offs & Alternatives
Prefer AC when many patterns against long texts.

## 9. Common Mistakes / Edge Cases
Comparing a string to itself; requiring proper substring only (equal strings usually absent).

## 10. Interview Follow-ups / Variations
Deduplicate outputs; AC multi-pattern version; case-insensitive.

## 11. Tags
`string`, `substring`, `lc-1408`, `difficulty:easy`
