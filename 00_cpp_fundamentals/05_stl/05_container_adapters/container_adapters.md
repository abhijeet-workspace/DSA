# Container Adapters

## 1. Problem Statement
Demonstrate STL adapters: `stack` (LIFO), `queue` (FIFO), and `priority_queue` (max-heap default + min-heap via `greater`).

- **Input:** pushed ints/strings in each demo
- **Output:** top/front values before and after pops
- **Valid answer:** stack top 30→20; queue front A→B; max top 30→20; min top 5→15
- **Edge cases:** pop/top on empty is UB; no iteration API on adapters

## 2. Intuition
Adapters restrict a richer container to a discipline (LIFO/FIFO/heap). You get a small intentional interface instead of accidental misuse of the underlying sequence.

## 3. Brute Force → Optimal
- **Naive:** raw `vector` and remember which end is “top”.
- **This approach:** `stack`/`queue`/`priority_queue` encode the policy in the type.

## 4. Data Structure / Approach Justification
**Chosen:** standard adapters (default underlying `deque` for stack/queue; `vector` for pq).

| Alternative | Why it loses here |
|-------------|-------------------|
| Manual vector as stack | Easy; less self-documenting |
| `multiset` as priority queue | Works; heavier / different iterator model |
| Homegrown heap | Teaching cost without need |

Trade-off: adapters hide iteration; fine for pure stack/queue/heap use.

## 5. Logic Walkthrough
1. Stack push 10,20,30; top=30; pop → top=20.
2. Queue push A,B,C; front A back C; pop → front B.
3. Max-heap push; top always largest.
4. Min-heap with `greater<int>`; top always smallest.

## 6. Dry Run
| Adapter | After pushes | After one pop |
|---------|--------------|---------------|
| stack | top 30 | top 20 |
| queue | front A | front B |
| maxHeap | top 30 | top 20 |
| minHeap | top 5 | top 15 |

## 7. Time & Space Complexity
- **stack/queue push/pop/top:** O(1) amortized
- **priority_queue push/pop:** O(log n); top O(1)
- **Space:** O(n)
- Why: deque ends are cheap; binary heap is logarithmic

## 8. Trade-offs & Alternatives
- Prefer `priority_queue` for “next best” scheduling.
- Prefer `set`/`multiset` when you need erase-arbitrary + ordered scan.
- Underlying container can be swapped (`stack<int,vector<int>>`) when profiling demands.

## 9. Common Mistakes / Edge Cases
- Calling `pop` before checking `empty()`
- Expecting iterators on `stack`/`queue`
- Forgetting comparator type args for min-heap syntax

## 10. Interview Follow-ups / Variations
- Implement queue with two stacks?
- Heap vs BST for priority workloads?
- Why default underlying container is `deque`?

## 11. Tags
`stl`, `stack`, `queue`, `priority_queue`, `heap`, `difficulty:easy`
