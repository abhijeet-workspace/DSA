# Friend Functions and Classes

## 1. Problem Statement
Show three friendship forms for `Customer` private data: a free friend function, a friend member of `BankInspector`, and a full friend class `CreditBureau`.

- **Input:** one customer (score 750, debt 15000)
- **Output:** eligibility, audit, and profile prints using private fields
- **Valid answer:** friends access privates; non-friends still cannot
- **Edge cases:** friendship is not symmetric/transitive/inherited

## 2. Intuition
Encapsulation is the default; friendship is an explicit exception for tightly coupled helpers (operators, factories, auditors) that need internals without becoming members.

## 3. Brute Force → Optimal
- **Naive:** public getters for every private field (widens API surface).
- **This approach:** grant minimal friend access to specific functions/classes.

## 4. Data Structure / Approach Justification
**Chosen:** `friend` declarations scoped to needed APIs.

| Alternative | Why it loses here |
|-------------|-------------------|
| All-public fields | Breaks encapsulation globally |
| Only getters | Works, but friends teach controlled bypass |
| Nested classes always | Heavier coupling / different design |

Trade-off: friends increase coupling; use sparingly and document why.

## 5. Logic Walkthrough
1. Forward-declare `Customer` so `BankInspector` can name it.
2. Declare three friend relationships inside `Customer`.
3. `checkLoanEligibility` reads score/debt directly.
4. `BankInspector::auditAccount` likewise (friend member).
5. `CreditBureau` methods access all privates (friend class).

## 6. Dry Run
| Actor | Reads | Decision/Output |
|-------|-------|-----------------|
| checkLoanEligibility | 750, 15000 | ELIGIBLE |
| auditAccount | same | prints score/debt |
| printCustomerProfile | name/score/debt | full summary |

## 7. Time & Space Complexity
- **Time:** O(1) per check/print
- **Space:** O(1) (+ string)
- Why: no containers

## 8. Trade-offs & Alternatives
- Prefer public narrow accessors when many clients need the same data.
- Prefer friend non-member `operator<<` pattern for streaming.
- Prefer breaking a class rather than befriending half the codebase.

## 9. Common Mistakes / Edge Cases
- Assuming friendship is mutual
- Assuming derived classes inherit friendship
- Overusing `friend class` instead of one friend function
- Declaring friend without defining the function

## 10. Interview Follow-ups / Variations
- Friend vs public method vs nested class?
- Why are some operators often friends?
- Does `friend` hurt testability or help it?

## 11. Tags
`oop`, `friend`, `encapsulation`, `access-control`, `difficulty:medium`
