# Aho-Corasick Linked Output Counts

## 1. Problem Statement
Count total pattern occurrences in text using output-link style aggregation (`outCnt`), not full id lists.

- **Inputs:** patterns (may share nodes), text.
- **Output:** total hit count (with overlaps).
- **Edges:** multiple patterns ending at same node; nested patterns.

## 2. Intuition
Each node stores how many pattern ends are reachable via its fail chain; visiting a node adds that count.

## 3. Brute Force → Optimal
- **Brute:** walk fail chain at every step.
- **Better:** precompute `outCnt` during BFS build.

## 4. Data Structure / Approach Justification
**Chosen:** `outCnt` = own ends + link's `outCnt`.

| Alternative | Note |
|-------------|------|
| Explicit outs lists | Needed for which patterns |
| Output links only | Walk until 0 when reporting ids |

## 5. Logic Walkthrough
1. Insert; ++end mark.
2. BFS: `outCnt[u] += outCnt[link[u]]`.
3. Scan: answer += outCnt[state].

## 6. Dry Run
Patterns `a,aa`; text `aaa` → occurrences **4** (classic nested count).

## 7. Time & Space Complexity
Build **O(Σ|p|·|Σ|)**, scan **O(|t|)**.

## 8. Trade-offs & Alternatives
Counts only — no pattern identities.

## 9. Common Mistakes / Edge Cases
Forgetting to add link counts; double-counting own ends.

## 10. Interview Follow-ups / Variations
Per-pattern counts; online streaming counts.

## 11. Tags
`aho-corasick`, `output-link`, `counting`, `lab`, `difficulty:hard`
