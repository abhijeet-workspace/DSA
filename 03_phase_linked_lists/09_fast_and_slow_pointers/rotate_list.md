# Rotate List

## 1. Problem Statement
[LeetCode 61](https://leetcode.com/problems/rotate-list/) — rotate the list to the right by `k` places.

- **Inputs:** `ListNode* head`, integer `k`.
- **Output:** new head after rotation.
- **Valid answer:** last `k % n` nodes moved to the front.
- **Edges:** empty; `k = 0`; `k` multiple of `n`; single node.

## 2. Intuition
Find length, normalize `k %= n`, connect tail to head (ring), then break the link `n - k` steps from the old head.

## 3. Brute Force → Optimal
- **Brute:** rotate by 1, `k` times — O(Nk).
- **Optimal:** length + close ring + cut — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** measure length then gap-cut (two-pointer / distance idea related to remove-nth).

- **vs k single-step rotates:** too slow for large `k`.
- **vs array rebuild:** O(N) space.

## 5. Logic Walkthrough
1. Count `n`, keep `tail`. If `k % n == 0`, return head.
2. `tail->next = head` (circularize).
3. Walk `n - k % n - 1` steps from head; new head is next; cut link.

## 6. Dry Run
`1→2→3→4→5`, `k = 2`: `n=5`, cut after `3` → `4→5→1→2→3`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: constant passes (section 4).

## 8. Trade-offs & Alternatives
Array of nodes is simpler; ring-cut is the classic O(1)-space answer.

## 9. Common Mistakes / Edge Cases
Forgetting `k %= n`; off-by-one when finding new tail; not breaking the cycle.

## 10. Interview Follow-ups / Variations
Rotate array; reverse in groups; remove nth from end.

## 11. Tags
`linked-list`, `two-pointers`, `leetcode-61`, `difficulty:medium`
