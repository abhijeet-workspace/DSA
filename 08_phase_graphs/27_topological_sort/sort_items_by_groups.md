# Sort Items by Groups Respecting Dependencies

## Problem Statement
[LeetCode 1203](https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/) — order `n` items so (1) `beforeItems` precedence holds and (2) items of the same group are contiguous. `group[i]=-1` means a singleton group. Return `[]` if impossible.

- **Inputs:** `n`, `m`, `group`, `beforeItems`.
- **Output:** valid item order or empty.
- **Valid answer:** any topo order satisfying both constraints.
- **Edges:** all `-1` groups; cycle in items or groups; empty before lists.

## Intuition
Two-level topo: dependencies *between* groups induce a group graph; dependencies *within* a group stay in the item graph. Sort groups first, then concatenate each group’s internal item order.

## Brute Force → Optimal
- **Brute:** try all permutations — impossible at scale.
- **Optimal:** Kahn on group graph + Kahn on item graph — **O(n + e)**.

## Data Structure / Approach Justification
**Chosen:** assign fresh group ids for `-1`, build item + group DAGs, Kahn both.

- **vs single graph only:** misses contiguity of groups.
- **vs DFS topo:** Kahn is easy to detect cycles via size check.

## Logic Walkthrough
Map `-1` → unique groups. For each `u before v`: edge `u→v`; if groups differ, edge `group(u)→group(v)`. Topo groups and items. Emit items by group order using items sorted within group.

## Dry Run
LC sample `n=8,m=2`: group edges from cross-group befores; valid emission yields length 8 (e.g. `6,3,4,1,5,2,0,7` or similar).

## Time & Space Complexity
Time **O(n + e)**. Space **O(n + e)**. Why: two Kahn passes (section 4).

## Trade-offs & Alternatives
Deduplicate group edges if many parallel cross edges inflate indegrees incorrectly — either use a set or only add unique group edges.

## Common Mistakes / Edge Cases
Double-counting parallel group edges in indegree; forgetting to give `-1` items unique groups; returning item topo alone (groups not contiguous).

## Interview Follow-ups / Variations
Lex-smallest order (priority queue Kahn). Only group constraints. Detect which constraint failed.

## Tags
`graph`, `topological-sort`, `kahn`, `leetcode-1203`, `difficulty:hard`
