# Replace Words — Trie vs Aho note (LC 648)

## 1. Problem Statement
Replace each word in a sentence by the shortest dictionary root that is a prefix.

- **Inputs:** `dictionary` of roots, `sentence` of words.
- **Output:** replaced sentence.
- **Valid answer:** [LC 648](https://leetcode.com/problems/replace-words/).
- **Edges:** no root; multiple roots; empty roots.
- **Note:** Prefix replacement is a pure trie job; AC is unnecessary unless roots match as arbitrary substrings.
- **Link:** [LC 648](https://leetcode.com/problems/replace-words/)

## 2. Intuition
Walk each word down a trie of roots; stop at first end mark (shortest root).

## 3. Brute Force → Optimal
- **Brute:** for each word, try all roots as prefixes.
- **Trie:** O(total chars).

## 4. Data Structure / Approach Justification
**Chosen:** trie of dictionary roots.

| Alternative | Note |
|-------------|------|
| Hash set of roots | Check all prefixes of each word |
| Aho-Corasick | Overkill for prefix-only |

## 5. Logic Walkthrough
1. Insert roots into trie.
2. For each sentence word, walk until end mark or miss.
3. Replace with root string if found.

## 6. Dry Run
Dict `{cat,bat,rat}`, sentence `the cattle was rattled by the battery` → `the cat was rat by the bat`.

## 7. Time & Space Complexity
**O(total dictionary + sentence chars)**.

## 8. Trade-offs & Alternatives
Trie is the right tool; mention AC only for contrast.

## 9. Common Mistakes / Edge Cases
Using longest root instead of shortest; splitting sentence wrong.

## 10. Interview Follow-ups / Variations
Longest root; case folding; AC if replacing arbitrary substrings.

## 11. Tags
`trie`, `lc-648`, `aho-contrast`, `difficulty:medium`
