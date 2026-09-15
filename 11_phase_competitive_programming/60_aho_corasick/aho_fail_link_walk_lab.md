# Aho-Corasick Fail-Link Walk Lab

## 1. Problem Statement
Teaching lab: after building the automaton, print each node's fail link and demonstrate walking the fail chain from a state reached by a short text.

- **Inputs:** small pattern set, one text prefix.
- **Output:** link parent per node; fail-chain from final state.
- **Edges:** root link 0; deep nested patterns.

## 2. Intuition
Fail links are KMP borders on the trie: longest proper suffix that is still a trie prefix.

## 3. Brute Force → Optimal
- **Conceptual:** recompute border from scratch each time.
- **BFS build:** O(1) transitions after filling.

## 4. Data Structure / Approach Justification
**Chosen:** standard BFS fail construction; then explicit chain print for learning.

| Alternative | Note |
|-------------|------|
| Suffix links on SAM | Different structure |

## 5. Logic Walkthrough
1. Build AC.
2. Print `node -> link`.
3. Feed text, print fail walk from current state.

## 6. Dry Run
Patterns `he,she`; after reading `she`, fail walk visits nodes ending `he` etc.

## 7. Time & Space Complexity
Build **O(states·|Σ|)**; walk **O(depth)**.

## 8. Trade-offs & Alternatives
Lab-only instrumentation; production omits prints.

## 9. Common Mistakes / Edge Cases
Setting root missing edges wrong; cycles if link incorrectly points to self beyond root.

## 10. Interview Follow-ups / Variations
Visualize output inheritance; compare to KMP π array.

## 11. Tags
`aho-corasick`, `fail-link`, `lab`, `difficulty:medium`
