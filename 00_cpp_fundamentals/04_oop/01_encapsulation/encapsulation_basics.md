# Encapsulation Basics

## 1. Problem Statement
Build a `BankAccount` that keeps `owner`, `balance`, and `accountNumber` private and exposes only validated public operations (getters, `deposit`, `withdraw`, `setOwner`).

- **Input:** constructor args and method calls in `main`
- **Output:** printed balances/errors for valid and invalid operations
- **Valid answer:** balance never goes negative via API; empty owner rejected; private fields inaccessible from outside
- **Edge cases:** negative initial balance, negative deposit, overdraft withdraw, empty name

## 2. Intuition
Data and the rules that protect it should live together. Callers should not poke `balance` directly; they go through methods that enforce invariants.

## 3. Brute Force → Optimal
- **Naive:** public fields anyone can set to invalid states.
- **This approach:** `private` data + public interface with validation (encapsulation / information hiding).

## 4. Data Structure / Approach Justification
**Chosen:** a class with private members and public methods.

| Alternative | Why it loses here |
|-------------|-------------------|
| Public `struct` fields | No invariant enforcement |
| Free functions on a POD | Easy to bypass rules; weaker cohesion |

Trade-off: more boilerplate than public fields; gains safety and a stable API.

## 5. Logic Walkthrough
1. Constructor stores owner/id; rejects negative `initialBalance`.
2. `getBalance` / `getOwner` expose read-only views.
3. `deposit` / `withdraw` mutate `balance` only when amounts are valid.
4. `setOwner` rejects empty strings.
5. `main` exercises happy path then invalid calls.

## 6. Dry Run
| Call | balance before | Result | balance after |
|------|----------------|--------|---------------|
| ctor(1000) | — | ok | 1000 |
| deposit(250) | 1000 | ok | 1250 |
| withdraw(500) | 1250 | ok | 750 |
| deposit(-50) | 750 | error | 750 |
| withdraw(2000) | 750 | error | 750 |

## 7. Time & Space Complexity
- **Time:** O(1) per operation (string assign O(length) for owner)
- **Space:** O(1) for the account object (+ string heap)
- Why: no collections; fixed fields

## 8. Trade-offs & Alternatives
- Prefer returning error codes/`std::optional`/`expected` instead of printing errors in library code.
- Prefer throwing consistently for all invariant violations if callers must handle failures.
- Prefer richer money types (cents/`decimal`) over `double` in production finance.

## 9. Common Mistakes / Edge Cases
- Exposing setters that skip validation
- Using `double` for currency (rounding)
- Forgetting `const` on getters
- Assuming friends/subclasses can freely break invariants without design

## 10. Interview Follow-ups / Variations
- Difference between encapsulation and abstraction?
- How would you unit-test validation without printing?
- Thread-safety: what if two threads withdraw concurrently?

## 11. Tags
`oop`, `encapsulation`, `class`, `access-control`, `difficulty:easy`
