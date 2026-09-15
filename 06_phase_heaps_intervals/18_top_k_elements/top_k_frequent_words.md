# Top K Frequent Words

## Problem Statement
[LeetCode 692](https://leetcode.com/problems/top-k-frequent-words/) — return the `k` most frequent words. Ties broken by lexicographical order (smaller first). Output sorted by frequency descending, then lex ascending.

- **Inputs:** `words`, `k`.
- **Output:** `vector<string>` length `k`.
- **Valid answer:** unique words ordered by the ranking rules.
- **Edges:** all unique; full ties; `k=1`; single word repeated.

## Intuition
Count frequencies. Keep a size-`k` heap of the “worst” candidates so far: smaller frequency is worse; equal frequency → lexicographically larger is worse (so lex-smaller stays).

## Brute Force → Optimal
- **Brute:** count then sort all unique words — O(U log U).
- **Optimal:** count + size-k heap — O(N + U log k).

## Data Structure / Approach Justification
**Chosen:** hashmap + custom min-heap comparator.

- **vs full sort:** fine when U is small; heap matches top-k pattern.
- **vs bucket by frequency:** also O(N); need careful lex sort per bucket.

## Logic Walkthrough
Count. Push `(freq, word)` into min-heap with comparator above; pop when size > k. Pop all into result from back to front so final order is best-first.

## Dry Run
`["i","love","leetcode","i","love","coding"]`, k=2: freqs i:2, love:2, others 1. Tie i vs love → lex `i` before `love` → `[i, love]`.

## Time & Space Complexity
Time **O(N + U log k)**. Space **O(U)**. Why: hash all words, heap of size k (section 4).

## Trade-offs & Alternatives
Sorting unique words with a comparator is clearer code; heap is better when k ≪ U.

## Common Mistakes / Edge Cases
Wrong tie-break direction in the heap; returning heap order without reversing; case sensitivity (LC lowercase).

## Interview Follow-ups / Variations
Top K Frequent Elements (347); sort characters by frequency; trending hashtags stream.

## Tags
`heap`, `hash-map`, `sorting`, `leetcode-692`, `difficulty:medium`
