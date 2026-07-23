# Aho-Corasick Build + Match Exists

## 1. Problem Statement
Insert patterns, build failure links, report whether each pattern occurs in a text.

- **Inputs:** lowercase patterns `pats[]`, text `t`.
- **Output:** boolean per pattern id.
- **Valid answer:** true iff pattern is a substring of `t`.
- **Edges:** empty pattern list; overlapping matches (`he` inside `she`); unused patterns.

## 2. Intuition
Trie of patterns + BFS failure links (KMP-style). While scanning text, follow output lists (including inherited via links) to mark hits.

## 3. Brute Force → Optimal
- **Brute:** run KMP (or `find`) per pattern.
- **Optimal:** one AC automaton — linear in |text| + total pattern length + reports.

## 4. Data Structure / Approach Justification
**Chosen:** trie with `array<26>` edges, BFS failure links, merged `outs` lists.

| Alternative | Note |
|-------------|------|
| Multiple KMP | Fine for few patterns |
| SAM of text | Good when text is fixed, patterns many/query |
| Word Search II DFS | Grid-specific |

## 5. Logic Walkthrough
1. `insert` each pattern into the trie.
2. BFS: root missing edges → 0; deeper missing edges copy from link; set `link` and inherit `outs`.
3. Scan text transitioning on `next[ch]`; mark all `outs` at current node.

## 6. Dry Run
Patterns `he,she,his,hers`, text `ushers` → `she`, `he`, `hers` found; `his` not.

## 7. Time & Space Complexity
Build **O(Σ lengths · |Σ|)**, match **O(|text| + hits)**. Space **O(Σ lengths · |Σ|)**. Why: each char processed amortized O(1) with filled transitions (section 4).

## 8. Trade-offs & Alternatives
Full automaton is heavier than a bare trie but pays off for dictionary matching. Propagating full `outs` lists is simple; output-links save memory.

## 9. Common Mistakes / Edge Cases
Not inheriting outputs through failures; forgetting root self-loops; assuming non-overlapping only.

## 10. Interview Follow-ups / Variations
Count overlapping occurrences; list all start indices; streaming text.

## 11. Tags
`aho-corasick`, `trie`, `string`, `multi-pattern`, `cp`, `difficulty:hard`
