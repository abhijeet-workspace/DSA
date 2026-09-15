# Simplify Path

## Problem Statement
[LeetCode 71](https://leetcode.com/problems/simplify-path/) — convert an absolute Unix path to its canonical form.

- **Inputs:** string `path` starting with `/`.
- **Output:** simplified absolute path (no trailing slash unless root).
- **Valid answer:** resolve `.`, `..`, and multiple `/`; never go above `/`.
- **Edges:** only `/`; trailing slash; many `..`; empty segments; names with dots like `...`.

## Intuition
Split on `/`. Push real directory names; ignore `.` and empties; pop on `..` when the stack is non-empty. Rebuild with `/` separators.

## Brute Force → Optimal
- **Brute:** recursive string rewrites until stable — messy edge cases.
- **Optimal:** one pass with a stack of tokens — O(N).

## Data Structure / Approach Justification
**Chosen:** vector-as-stack of path segments.

- **vs string mutation in place:** harder with variable-length tokens.
- **vs deque of chars:** segment-level stack matches Unix semantics cleanly.

## Logic Walkthrough
Tokenize by `/`. For each token: skip empty/`.`; if `..` pop if possible; else push. Join with `/`, or return `/` if empty.

## Dry Run
`/a/./b/../../c/` → tokens `a`, `.`, `b`, `..`, `..`, `c` → stack ends as `[c]` → `/c`.

`/../` → `..` with empty stack → `/`.

## Time & Space Complexity
Time **O(N)**. Space **O(N)**. Why: one scan and stack of segments (section 4).

## Trade-offs & Alternatives
`stringstream` + `getline` is clear; manual index scanning avoids stream overhead but is similar asymptotically.

## Common Mistakes / Edge Cases
Treating `...` as `..`; going above root; leaving trailing `/`; collapsing only consecutive slashes without handling `.`/`..`.

## Interview Follow-ups / Variations
Relative path resolution given cwd; Windows-style paths; undo/redo with path stack.

## Tags
`stack`, `string`, `path`, `leetcode-71`, `difficulty:medium`
