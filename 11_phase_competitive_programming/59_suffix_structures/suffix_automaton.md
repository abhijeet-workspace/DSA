# Suffix Automaton — Distinct Substrings

## 1. Problem Statement
Build the suffix automaton of `s` and count the number of distinct substrings.

- **Inputs:** string `s`.
- **Output:** count of unique contiguous substrings.
- **Valid answer:** exact count.
- **Edges:** empty → 0; single char → 1; all identical chars → N.

## 2. Intuition
SAM is a minimal DFA of all substrings. Each state represents an endpos-equivalence class; lengths between `link` and `len` are unique substrings ending in that class.

## 3. Brute Force → Optimal
- **Brute:** insert all O(N²) substrings into a set.
- **Optimal:** online SAM extend O(N |Σ|) (map) or O(N) with arrays.

## 4. Data Structure / Approach Justification
**Chosen:** classic SAM with clone-on-extend; `map<char,int>` transitions for clarity.

| Alternative | Note |
|-------------|------|
| SA + LCP | `N(N+1)/2 - sum LCP` |
| Trie of all suffixes | O(N²) space |

## 5. Logic Walkthrough
1. Start with state 0.
2. `extend(c)`: create `cur`, walk failure links adding `c`, then set link or clone `q` when lengths mismatch.
3. Distinct count = Σ over states `(len[v] - len[link[v]])`.

## 6. Dry Run
`s=ababa` → 9 distinct substrings (`a,b,ab,ba,aba,bab,abab,baba,ababa`).

## 7. Time & Space Complexity
Time **O(N |Σ|)** with maps (often fine), space **O(N)** states. Why: at most 2N states; each extend amortized O(|Σ|) (section 4).

## 8. Trade-offs & Alternatives
Linear and powerful for occurrence / first-pos problems. SA+LCP is enough for many count queries without SAM complexity.

## 9. Common Mistakes / Edge Cases
Missing the clone step; wrong link length; forgetting state 0 contributes nothing.

## 10. Interview Follow-ups / Variations
First occurrence of a pattern; number of occurrences; LCS of two strings via SAM.

## 11. Tags
`suffix-automaton`, `string`, `distinct-substrings`, `cp`, `difficulty:hard`
