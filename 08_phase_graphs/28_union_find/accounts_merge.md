# Accounts Merge

## Problem Statement
[LeetCode 721](https://leetcode.com/problems/accounts-merge/) — merge accounts that share any email; output name + sorted unique emails per person.

- **Inputs:** `vector<vector<string>> accounts` where `accounts[i][0]` is name and the rest are emails.
- **Output:** merged accounts (name + sorted emails).
- **Valid answer:** same person iff transitive email sharing; order of accounts unrestricted.
- **Edges:** same name different people; one email; disjoint Johns; transitive merge A–B–C.

## Intuition
Treat each account index as a DSU node. When an email was already seen under another account, union those indices. Group emails by root, then sort.

## Brute Force → Optimal
- **Brute:** graph of accounts with edges on shared emails + DFS components — O(N·E) string work.
- **Optimal:** DSU on account indices keyed by first-seen email — near-linear in emails with hashing.

## Data Structure / Approach Justification
**Chosen:** `email → accountIndex` map + DSU on account indices.

- **vs DSU on emails:** more string parents; indexing accounts is simpler.
- **vs union-find per name:** names collide; emails are the identity key.

## Logic Walkthrough
For each account’s emails: if email known, `unite(i, known)`; else map email→i. Then for each email, push into `merged[find(acc)]`. Sort emails; prepend name from root account.

## Dry Run
John A: `smith`, `ny`; John B: `smith`, `00` → unite A–B. Mary alone. John C: `johnny` alone. Merged John has `00, ny, smith` sorted.

## Time & Space Complexity
Time **O(N α(N) + M log M)** for M emails (sort dominates). Space **O(N + M)**. Why: DSU merges + per-component sort (section 4).

## Trade-offs & Alternatives
DFS on email graph is fine if you prefer adjacency over DSU. Sorting globally once vs per component is similar cost.

## Common Mistakes / Edge Cases
Merging solely by name; forgetting to sort; using a non-root name; duplicate emails inside one account.

## Interview Follow-ups / Variations
Return count of people. Online streaming merges. Case-insensitive emails.

## Tags
`union-find`, `hash-map`, `sorting`, `leetcode-721`, `difficulty:medium`
