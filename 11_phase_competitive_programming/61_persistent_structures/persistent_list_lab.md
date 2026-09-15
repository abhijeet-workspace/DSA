# Persistent List Lab

## 1. Problem Statement
Persistent singly linked list: `cons(version, x)`, `tail(version)`, `nth(version, i)` with structure sharing.

- **Inputs:** cons operations branching versions.
- **Output:** element access on any version.
- **Edges:** nth out of range; empty list.

## 2. Intuition
Classic Lisp/functional list persistence — each cons is a new head sharing the old tail.

## 3. Brute Force → Optimal
- **Brute:** copy vector.
- **Persistent list:** O(1) cons, O(k) nth.

## 4. Data Structure / Approach Justification
**Chosen:** node pool `{val, next}`; version = head index.

| Alternative | Note |
|-------------|------|
| Persistent vector / RRB | Random access |
| Fat nodes | |

## 5. Logic Walkthrough
1. `cons` allocates head → old.
2. `tail` returns next.
3. `nth` walks k steps.

## 6. Dry Run
v1=cons(v0,1); v2=cons(v1,2); nth(v2,1)=1; nth(v1,0)=1.

## 7. Time & Space Complexity
**O(1)** cons; **O(k)** nth.

## 8. Trade-offs & Alternatives
Poor random updates in middle — use balanced trees.

## 9. Common Mistakes / Edge Cases
Mutating next pointers of shared nodes.

## 10. Interview Follow-ups / Variations
Persistent vector; concatenate with care.

## 11. Tags
`persistent`, `list`, `lab`, `difficulty:easy`
