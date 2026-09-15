# Persistent Stack Lab

## 1. Problem Statement
Implement a persistent stack: `push(version, x)` and `pop(version)` return new version ids; old versions remain readable.

- **Inputs:** sequence of push/pop on version ids.
- **Output:** top of any version.
- **Edges:** pop empty; branch two futures from same version.

## 2. Intuition
Each node stores value + pointer to previous; versions are just node handles.

## 3. Brute Force → Optimal
- **Brute:** copy vector each time.
- **Persistent:** O(1) push/pop with sharing.

## 4. Data Structure / Approach Justification
**Chosen:** linked nodes in a pool; version = node index.

| Alternative | Note |
|-------------|------|
| Path-copying array stack | O(n) |
| Fat nodes | Undo log |

## 5. Logic Walkthrough
1. `push`: new node → old top.
2. `pop`: return previous pointer.
3. `top`: read node value.

## 6. Dry Run
v0 empty; v1=push(v0,1); v2=push(v1,2); v3=pop(v2) → top 1; v2 still top 2.

## 7. Time & Space Complexity
**O(1)** per op; space **O(#ops)**.

## 8. Trade-offs & Alternatives
Simplest persistence demo.

## 9. Common Mistakes / Edge Cases
Mutating nodes; confusing version id with value.

## 10. Interview Follow-ups / Variations
Persistent queue; random-access persistent vector.

## 11. Tags
`persistent`, `stack`, `lab`, `difficulty:medium`
