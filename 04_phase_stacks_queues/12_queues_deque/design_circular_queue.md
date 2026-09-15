# Design Circular Queue

## 1. Problem Statement
[LeetCode 622](https://leetcode.com/problems/design-circular-queue/) — fixed-capacity FIFO ring buffer with `enQueue`, `deQueue`, `Front`, `Rear`, `isEmpty`, `isFull`.

- **Inputs:** capacity `k`; operations on integers.
- **Output:** bool success / int front or rear / empty-full flags.
- **Edges:** empty dequeue; full enqueue; capacity 1; wrap-around.

## 2. Intuition
Store elements in an array; track `head` index and `count`. Tail is `(head + count - 1) % k`. Circular index avoids shifting.

## 3. Brute Force → Optimal
- **Brute:** `vector` erase front — O(N) dequeue.
- **Optimal:** ring buffer — O(1) all ops, O(k) space.

## 4. Data Structure / Approach Justification
**Chosen:** array + `head` + `count` (or head/tail with sentinel).

| Alternative | Note |
|-------------|------|
| Linked list | O(1) but unbounded / extra pointers |
| `std::deque` | Hides the ring design under test |

## 5. Logic Walkthrough
1. `enQueue`: if full false; write at `(head+count)%k`; `++count`.
2. `deQueue`: if empty false; `head = (head+1)%k`; `--count`.
3. `Front`/`Rear`: empty → -1; else `buf[head]` / `buf[(head+count-1)%k]`.

## 6. Dry Run
`k=3`: en 1,2,3 → full; de → head at 2; en 4 wraps into slot 0; Rear=4.

## 7. Time & Space Complexity
- **Time:** O(1) per operation
- **Space:** O(k)

## 8. Trade-offs & Alternatives
Head+tail without count needs a wasted slot or bool flag to distinguish empty/full.

## 9. Common Mistakes / Edge Cases
Modulo on negative; returning Front when empty; forgetting wrap on enqueue index.

## 10. Interview Follow-ups / Variations
Circular deque (641); lock-free ring buffers; producer-consumer.

## 11. Tags
`queue`, `design`, `array`, `leetcode-622`, `difficulty:medium`
