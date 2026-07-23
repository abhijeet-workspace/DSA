# Min Stack

## Problem Statement
[LeetCode 155](https://leetcode.com/problems/min-stack/) — design a stack supporting `push`, `pop`, `top`, and `getMin` all in O(1).

- **Inputs:** sequence of stack ops with ints.
- **Output:** correct top and running minimum.
- **Valid answer:** any design with O(1) worst-case ops.
- **Edges:** new global min; pop restoring prior min; single element.

## Intuition
Encode each push relative to the current min. A negative delta means the pushed value became the new min; popping it recovers the old min algebraically.

## Brute Force → Optimal
- **Brute:** scan stack for min — O(N) `getMin`.
- **Two-stack:** value stack + min stack — O(1), O(N) extra.
- **This:** one stack of deltas + scalar `mn_` — O(1), less memory.

## Data Structure / Approach Justification
**Chosen:** `stack<long long>` of `val - mn` with running `mn_`.

- **vs dual stacks:** clearer; uses ~2× stack memory.
- **vs storing pairs `(val,min)`:** simple; same O(N) space.

`long long` avoids overflow when differencing extremes.

## Logic Walkthrough
Empty push stores 0 and sets `mn_`. Else push `val-mn_`; if `val<mn_` update min. Pop negative delta → `mn_ -= t`. Top: if delta `<0` return `mn_`, else `mn_+t`.

## Dry Run
push -2 → mn=-2. push 0 → delta 2. push -3 → delta -1, mn=-3. getMin=-3. pop restores mn=-2. top=0.

## Time & Space Complexity
All ops **O(1)**. Space **O(N)**. Why: constant work per op; one entry per push (section 4).

## Trade-offs & Alternatives
Dual-stack is easier to explain in interviews; delta trick saves memory and is a good follow-up.

## Common Mistakes / Edge Cases
`int` overflow on deltas; forgetting to restore min on pop; `top` when delta encodes new min.

## Interview Follow-ups / Variations
Max stack; dual-stack version; thread-safe min stack.

## Tags
`stack`, `design`, `min-stack`, `leetcode-155`, `difficulty:medium`
