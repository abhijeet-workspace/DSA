# Serialize and Deserialize Binary Tree

## 1. Problem Statement
[LeetCode 297](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) — design `serialize(tree) → string` and `deserialize(string) → tree` that round-trip correctly.

- **Inputs:** `TreeNode* root` / encoded `string`.
- **Output:** string encoding / rebuilt tree.
- **Valid answer:** any lossless format; structure and values preserved.
- **Edges:** empty; skewed; duplicate values; negatives.

## 2. Intuition
Preorder with explicit null markers uniquely determines every missing child, so the token stream rebuilds the same shape.

## 3. Brute Force → Optimal
- **Brute:** formats without nulls are ambiguous (cannot tell missing left vs right).
- **Optimal:** preorder `"val,"` / `"#,"` tokens; consume stream to rebuild — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** recursive preorder + `stringstream` token split on `,`.

- **vs level-order BFS with nulls:** also unique; matches some judge samples.
- **vs JSON-like trees:** heavier parsing for interviews.

## 5. Logic Walkthrough
Serialize: null → `"#,"`; else `val + "," + left + right`. Deserialize: read next token; `#` → null; else `new` node, build left then right from remaining tokens.

## 6. Dry Run
Tree `1` / left `2` / right `3`:
- serialize → `"1,2,#,#,3,#,#,"`
- deserialize consumes `1` → left `2` (both children `#`) → right `3` (both `#`) → same shape

## 7. Time & Space Complexity
Time **O(N)**. Space **O(N)** for the string (+ O(H) recursion). Why: one token per node/null (section 4).

## 8. Trade-offs & Alternatives
Preorder recursion is short. BFS may match platform examples. BST can omit nulls using value bounds.

## 9. Common Mistakes / Edge Cases
Omitting null tokens; delimiter collisions with values; not freeing rebuilt trees in demos; empty string / only `#`.

## 10. Interview Follow-ups / Variations
BST serialize without nulls; compact binary format; encode N-ary trees.

## 11. Tags
`binary-tree`, `serialize`, `preorder`, `dfs`, `leetcode-297`, `difficulty:hard`
