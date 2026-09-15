# Persistent Queue Lab

## 1. Problem Statement
Teaching lab: persistent queue via two persistent stacks (Okasaki-style simplified) or paired lists with versions.

- **Inputs:** enqueue/dequeue on version handles.
- **Output:** front of any version.
- **Edges:** dequeue empty; branch versions.
- **Note:** Fully balancéd real-time persistent queues are complex; lab uses two stacks with occasional reverse copy for clarity.

## 2. Intuition
Queue = front stack + back stack; reverse back onto front when front empty — path copy to keep old versions.

## 3. Brute Force → Optimal
- **Brute:** copy deque.
- **Two persistent stacks:** amortized sharing.

## 4. Data Structure / Approach Justification
**Chosen:** version struct `{front, back}` of persistent stack indices; reverse by pushing pops into new front.

| Alternative | Note |
|-------------|------|
| Linked list with head/tail copy | Tail updates costly without more structure |

## 5. Logic Walkthrough
1. `enq`: push onto back stack.
2. `deq`: ensure front nonempty by reversing back; then pop front.
3. Store new version pair.

## 6. Dry Run
enq 1,2; deq → front was 1; old version still has front 1.

## 7. Time & Space Complexity
Amortized **O(1)** / **O(n)** reverse episodes; lab focuses on correctness.

## 8. Trade-offs & Alternatives
Simplified vs Okasaki real-time queues.

## 9. Common Mistakes / Edge Cases
Reversing in place destroying old versions; forgetting empty checks.

## 10. Interview Follow-ups / Variations
Fully persistent deque; banker's method.

## 11. Tags
`persistent`, `queue`, `lab`, `difficulty:hard`
