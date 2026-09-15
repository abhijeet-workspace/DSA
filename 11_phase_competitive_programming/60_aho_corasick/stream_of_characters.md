# Stream of Characters (LC 1032)

## 1. Problem Statement
Design a structure that, given a stream of letters, reports whether any query suffix of the stream is in a dictionary.

- **Inputs:** dictionary words; then a stream of lowercase letters.
- **Output:** after each letter, `true` if some word is a suffix of the stream so far.
- **Valid answer:** matches [LC 1032](https://leetcode.com/problems/stream-of-characters/).
- **Edges:** overlapping words; long stream; single-letter words.
- **Framing:** reversed trie (usual LC solution) vs AC on reversed patterns — both OK; lab uses reversed trie for clarity, notes AC alternative.
- **Link:** [LC 1032](https://leetcode.com/problems/stream-of-characters/)

## 2. Intuition
Querying suffixes is awkward on a forward trie. Insert reversed words and walk the stream backward from the newest char.

## 3. Brute Force → Optimal
- **Brute:** keep full stream string and check every dictionary word as suffix each time.
- **Optimal:** reversed trie / AC — O(L) per query letter with early stop.

## 4. Data Structure / Approach Justification
**Chosen:** reverse each word into a trie; on query, walk from latest char while path exists.

| Alternative | Note |
|-------------|------|
| Aho-Corasick on reversed dict | Same asymptotics; heavier build |
| Rolling hashes of suffixes | Harder with variable lengths |

## 5. Logic Walkthrough
1. Insert `reverse(word)` for each dictionary word; mark ends.
2. Append query char to a buffer.
3. Walk trie from buffer end toward start; if an end node is hit → true.

## 6. Dry Run
Dict `{cd,f,kl}`; stream `a,b,c,d` → after `d` path `d→c` hits `cd` → **true**.

## 7. Time & Space Complexity
Build **O(total chars)**. Each query **O(max word length)**. Space **O(total chars)**.

## 8. Trade-offs & Alternatives
Reversed trie is simplest for LC 1032. AC shines if you also need all match positions online.

## 9. Common Mistakes / Edge Cases
Forgetting to reverse; not capping walk length; mutating shared state across queries incorrectly.

## 10. Interview Follow-ups / Variations
Return which word matched; bound memory of the stream buffer; AC fail-link version.

## 11. Tags
`stream`, `trie`, `aho-corasick-adjacent`, `lc-1032`, `difficulty:hard`
