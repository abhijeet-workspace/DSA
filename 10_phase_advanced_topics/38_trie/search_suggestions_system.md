# Search Suggestions System

## 1. Problem Statement
[LeetCode 1268](https://leetcode.com/problems/search-suggestions-system/) — after each typed character of `searchWord`, return up to 3 lexicographically smallest products sharing that prefix.

- **Inputs:** `products` list, `searchWord`.
- **Output:** list of suggestion lists (one per prefix length).
- **Valid answer:** ≤3 sorted matches per step.
- **Edges:** no matches; fewer than 3; single product; empty products (not typical).

## 2. Intuition
Sorted products make the matching window contiguous; `lower_bound(prefix)` then scan next three that still share the prefix.

## 3. Brute Force → Optimal
- **Brute:** filter all products each keystroke — O(P·L²).
- **Optimal:** sort once + advancing `lower_bound` — O(P log P + L·(log P + 3)).
- **Alt:** trie storing up to 3 suggestions per node.

## 4. Data Structure / Approach Justification
**Chosen:** sort + binary search (clear, no custom trie).

- **vs trie of products:** O(total chars) build; nice when many queries.
- **vs priority queues per prefix:** heavier.

## 5. Logic Walkthrough
Sort `products`. Grow `prefix`; `lower_bound` from previous iterator; collect up to 3 strings with that prefix.

## 6. Dry Run
products sorted `mobile,moneypot,monitor,mouse,mousepad`; typing `mouse` → first two prefixes yield `mobile…`, then `mou…` → `mouse,mousepad`.

## 7. Time & Space Complexity
Time **O(P log P + |searchWord|·log P)**. Space **O(1)** extra beyond output (sort may use O(log P)). Why: sort + binary searches (section 4).

## 8. Trade-offs & Alternatives
Trie shines for interactive typeahead with shared structure across queries.

## 9. Common Mistakes / Edge Cases
Not sorting; taking more than 3; comparing full string equality instead of prefix; resetting search range each time unnecessarily (still correct).

## 10. Interview Follow-ups / Variations
Case-insensitive; fuzzy match; trie with top-k cached at nodes.

## 11. Tags
`trie`, `binary-search`, `sorting`, `string`, `leetcode-1268`, `difficulty:medium`
