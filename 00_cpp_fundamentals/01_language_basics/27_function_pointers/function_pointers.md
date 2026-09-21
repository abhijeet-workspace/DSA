# Function Pointers

## 1. Problem Statement
Show pointers to functions: assign `add`/`mul`, invoke through the pointer, and pass a function as a callback to `apply`.

- **Input:** none
- **Output:** results `5`, `6`, `9`, `20`, and lambda `5`
- **Valid answer:** function name decays to a pointer; call syntax looks like a normal call
- **Edges:** signature must match exactly; prefer lambdas/`std::function` in modern code

## 2. Intuition
Functions live at addresses too. A function pointer lets you choose *which* operation to run at runtime (strategy/callback).

## 3. Brute Force → Optimal
- **Naive:** giant `switch` on an enum for every operation.
- **This approach:** pass the operation itself (function pointer / later lambda).

## 4. Data Structure / Approach Justification
Raw `int (*)(int,int)` — clearest teaching form before `std::function`.

| Alternative | Why it loses / wins |
|-------------|---------------------|
| Lambdas | Cleaner; can capture state |
| Virtual methods | OOP strategy pattern |
| `std::function` | Type-erased; slight overhead |

## 5. Logic Walkthrough
1. Point `fn` at `add`, call it.
2. Reseat `fn` to `mul`.
3. Pass `add`/`mul` into `apply`.
4. Show a lambda as the modern callback style.

## 6. Dry Run
| Call | Result |
|------|--------|
| `fn=add; fn(2,3)` | 5 |
| `fn=mul; fn(2,3)` | 6 |
| `apply(4,5,mul)` | 20 |

## 7. Time & Space Complexity
- **Time:** O(1) per call (+ indirect call cost)
- **Space:** O(1)
- Why: no heap

## 8. Trade-offs & Alternatives
- Prefer lambdas for local callbacks.
- Prefer `std::function` when you must store heterogeneous callables.
- Prefer templates when the callable is known at compile time.

## 9. Common Mistakes / Edge Cases
- Mismatched signatures
- Calling a null function pointer
- Forgetting parentheses in complex pointer-to-function types (use `using`)

## 10. Interview Follow-ups / Variations
- Pointer to member function syntax?
- `noexcept` in function types?
- How do qsort-style C APIs use callbacks?

## 11. Tags
`cpp-basics`, `function-pointers`, `callbacks`, `beginner`
