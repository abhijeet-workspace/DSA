# Word Search

## Problem Statement
[LeetCode 79](https://leetcode.com/problems/word-search/) — return whether `word` can be formed from adjacent (up/down/left/right) board cells without reusing a cell.

- **Inputs:** `vector<vector<char>> board`, `string word`.
- **Output:** `bool`.
- **Valid path:** 4-directional, each cell once per path.
- **Edges:** single letter; word longer than board; multiple matching starts; reuse attempts.

## Intuition
Try DFS from every cell matching `word[0]`. Mark the cell visited, explore neighbors for the next character, then restore the cell.

## Brute Force → Optimal
- **Brute:** enumerate all paths of length L — same worst bound.
- **Optimal:** backtracking with in-place mark (`'#'`) — O(L) extra space, early prune on mismatch.

## Data Structure / Approach Justification
**Chosen:** DFS + in-place board mark/restore.

- **vs separate visited matrix:** clearer ownership of state; more memory.
- **vs BFS:** awkward for “path without reuse” + early success return; DFS fits naturally.

## Logic Walkthrough
`dfs(r,c,i)`: if `i==len` true; if OOB or mismatch false; save char, set `'#'`, OR four dirs with `i+1`, restore, return.

## Dry Run
Board `ABCE / SFCS / ADEE`, word `ABCCED`:
- start `(0,0)='A'` → `(0,1)='B'` → `(0,2)='C'` → `(1,2)='C'` → `(2,2)='E'` → `(2,1)='D'` → true

## Time & Space Complexity
Time **O(M·N·4^L)** worst. Space **O(L)** recursion (in-place mark). Why: each start × up to 4 branches per letter (section 4).

## Trade-offs & Alternatives
In-place mark avoids visited allocation. Word Search II (212) → Trie + shared DFS. Allow diagonals only if problem says so.

## Common Mistakes / Edge Cases
Not restoring the cell; allowing reuse; starting only from `(0,0)`; modifying board permanently across failed starts.

## Interview Follow-ups / Variations
Find all words (212). Allow diagonal / knight moves. Count occurrences. Immutable board → use visited set.

## Tags
`backtracking`, `dfs`, `matrix`, `leetcode-79`, `difficulty:medium`
