# Replace Words

## 1. Problem Statement
[LeetCode 648](https://leetcode.com/problems/replace-words/) — given a dictionary of roots and a sentence, replace each word with the shortest root that is a prefix (else leave unchanged).

- **Inputs:** `dictionary` of roots, space-separated `sentence`.
- **Output:** replaced sentence string.
- **Valid answer:** shortest matching root per word.
- **Edges:** no root matches; root equals word; multiple nested roots (`a`, `aa`).

## 2. Intuition
A trie of roots lets each word walk letter-by-letter and stop at the first `isEnd` — that path is the shortest root prefix.

## 3. Brute Force → Optimal
- **Brute:** for each word check every dictionary prefix — O(words · dict · L).
- **Optimal:** build trie once, query per word — O(total chars).

## 4. Data Structure / Approach Justification
**Chosen:** 26-way trie + `shortestRoot` early exit on `isEnd`.

- **vs sorted dict + binary search:** works; trie is natural for shared prefixes.
- **vs hash set of all prefixes:** more memory.

## 5. Logic Walkthrough
Insert all roots. Tokenize sentence; for each word walk trie until missing child or `isEnd`; emit root or original.

## 6. Dry Run
dict `{cat,bat,rat}`, `"the cattle was rattled by the battery"` → `"the cat was rat by the bat"`.

## 7. Time & Space Complexity
Time **O(total chars)**. Space **O(sum of root lengths)**. Why: each character touches one edge (section 4).

## 8. Trade-offs & Alternatives
If dictionary is tiny and sentence huge, hashing prefixes may suffice.

## 9. Common Mistakes / Edge Cases
Replacing with longest root; continuing past first `isEnd`; mishandling spaces when rebuilding sentence.

## 10. Interview Follow-ups / Variations
Longest root instead; case sensitivity; Unicode.

## 11. Tags
`trie`, `string`, `leetcode-648`, `difficulty:medium`
