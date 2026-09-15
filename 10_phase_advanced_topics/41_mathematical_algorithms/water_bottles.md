# Water Bottles

## 1. Problem Statement
[LeetCode 1518](https://leetcode.com/problems/water-bottles/) — drink `numBottles`; every `numExchange` empty bottles become one full. Return total drunk.

- **Inputs:** `numBottles`, `numExchange`.
- **Output:** total bottles drunk.
- **Valid answer:** exact total.
- **Edges:** `numExchange > numBottles`; exchange leaves remainder empties.

## 2. Intuition
Simulate: drink all full → empties; while empties ≥ exchange, convert and drink again.

## 3. Brute Force → Optimal
Simulation is already O(log)-ish small; closed form also exists: `numBottles + (numBottles-1)/(numExchange-1)` under constraints.

## 4. Data Structure / Approach Justification
**Chosen:** clear simulation loop for teaching.

- **vs formula:** faster but easier to misremember remainders.

## 5. Logic Walkthrough
`drunk=0`; while bottles: drunk+=bottles; empty+=bottles; bottles=empty/exchange; empty%=exchange.

## 6. Dry Run
`9` bottles, exchange `3` → drink 9, exchange to 3, drink 3, exchange to 1 → **13**.

## 7. Time & Space Complexity
Time **O(log N)** exchanges. Space **O(1)**.

## 8. Trade-offs & Alternatives
Formula is O(1); simulation is safer in interviews.

## 9. Common Mistakes / Edge Cases
Forgetting leftover empties after exchange; off-by-one on last bottle.

## 10. Interview Follow-ups / Variations
Water Bottles II (harder exchange cost).

## 11. Tags
`math`, `simulation`, `leetcode-1518`, `difficulty:easy`
