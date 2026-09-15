# Replace Words

## Problem Statement
[LeetCode 648](https://leetcode.com/problems/replace-words/) — given a dictionary of roots and a sentence, replace each word with the shortest root that is a prefix (else leave unchanged).

- **Inputs:** `dictionary` of roots, space-separated `sentence`.
- **Output:** replaced sentence string.
- **Valid answer:** shortest matching root per word.
- **Edges:** no root matches; root equals word; multiple nested roots (`a`, `aa`).

## Intuition
A trie of roots lets each word walk letter-by-letter and stop at the first `isEnd` — that path is the shortest root prefix.

## Brute Force → Optimal
- **Brute:** for each word check every dictionary prefix — O(words · dict · L).
- **Optimal:** build trie once, query per word — O(total chars).

## Data Structure / Approach Justification
**Chosen:** 26-way trie + `shortestRoot` early exit on `isEnd`.

- **vs sorted dict + binary search:** works; trie is natural for shared prefixes.
- **vs hash set of all prefixes:** more memory.

## Logic Walkthrough
Insert all roots. Tokenize sentence; for each word walk trie until missing child or `isEnd`; emit root or original.

## Dry Run
dict `{cat,bat,rat}`, `"the cattle was rattled by the battery"` → `"the cat was rat by the bat"`.

## Time & Space Complexity
Time **O(total chars)**. Space **O(sum of root lengths)**. Why: each character touches one edge (section 4).

## Trade-offs & Alternatives
If dictionary is tiny and sentence huge, hashing prefixes may suffice.

## Common Mistakes / Edge Cases
Replacing with longest root; continuing past first `isEnd`; mishandling spaces when rebuilding sentence.

## Interview Follow-ups / Variations
Longest root instead; case sensitivity; Unicode.

## Tags
`trie`, `string`, `leetcode-648`, `difficulty:medium`
