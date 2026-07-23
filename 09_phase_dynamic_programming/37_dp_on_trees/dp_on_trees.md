# DP on Trees

## Problem Statement
Tree DP demos: [House Robber III (337)](https://leetcode.com/problems/house-robber-iii/), [Diameter (543)](https://leetcode.com/problems/diameter-of-binary-tree/), [Distribute Coins (979)](https://leetcode.com/problems/distribute-coins-in-binary-tree/).

- **Inputs:** binary `TreeNode* root` (and problem-specific node values).
- **Output:** max loot / diameter in edges / min moves to balance coins.
- **Valid answer:** optimal over subtree choices; no adjacent rob for 337.
- **Edges:** empty; single node; skewed; all coins on one node.

## Intuition
Post-order DFS: children return compact state; parent combines. Trees have no cycles, so bottom-up DP is natural.

## Brute Force → Optimal
- **Brute:** try all rob/skip assignments with adjacency checks — exponential.
- **Optimal:** O(N) DFS returning `{rob, skip}`, height+diameter, or excess coins.

## Data Structure / Approach Justification
**Chosen:** recursive helpers returning pairs/ints; no extra adjacency table.

- **vs rerooting for all-roots answers:** needed for some “answer for every node” problems.
- **vs converting tree to graph + general DP:** overkill on binary trees.

## Logic Walkthrough
**337:** rob = `val + skipL + skipR`; skip = `max(rob,skip)` of each child. **543:** height = `1+max(L,R)`; diameter = max path through node `L+R`. **979:** excess = `val-1+left+right`; moves += `|excess|` of children.

## Dry Run
337 tree `3 / 2 3 \ 3 1` → rob leaves `3` and `1` plus root? Optimal **7** (2’s child 3 + right child 1 + left? actually 3+3+1). Coins `[3,0,0]` → **2** moves to children.

## Time & Space Complexity
Time **O(N)**. Space **O(H)** recursion. Why: one visit per node (section 4).

## Trade-offs & Alternatives
Pair return is clean for two states. Explicit memo maps keyed by node are rarely needed on trees.

## Common Mistakes / Edge Cases
Robbing parent and child; diameter as nodes vs edges; forgetting `val-1` in coin excess.

## Interview Follow-ups / Variations
Binary Tree Cameras (968); max path sum (124); reroot DP on undirected trees.

## Tags
`tree-dp`, `dfs`, `house-robber-iii`, `leetcode-337`, `difficulty:medium`
