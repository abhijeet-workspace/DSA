# Function Overriding

## 1. Problem Statement
Show runtime polymorphism: `virtual` base `sound()`, overridden in `Dog`/`Cat`, invoked through an `Animal*`.

- **Input:** none
- **Output:** `Dog barks` then `Cat meows`
- **Valid answer:** dynamic dispatch selects the dynamic type’s override
- **Edges:** without `virtual`, base version would run (static binding)

## 2. Intuition
Same call site `animal->sound()` behaves differently based on the object’s actual type when the function is virtual (vtable dispatch).

## 3. Brute Force → Optimal
- **Brute:** `if`/`switch` on a type tag to pick behavior.
- **This approach:** virtual overrides — open for extension without editing a central switch.

## 4. Data Structure / Approach Justification
**Chosen:** classic base pointer + virtual method.

| Alternative | Why it loses / wins |
|-------------|---------------------|
| `std::variant` + `visit` | Value-based; no inheritance |
| CRTP | Compile-time polymorphism; no vtable |
| Non-virtual + hide | Silent wrong call via base pointer |

## 5. Logic Walkthrough
1. Mark `Animal::sound` `virtual`.
2. `Dog`/`Cat` provide overrides (`override` on Cat documents intent).
3. Point `animal` at `d` then `c`; each `->sound()` dispatches dynamically.

## 6. Dry Run
`animal = &d` → vtable → `Dog::sound` → “Dog barks”.
`animal = &c` → `Cat::sound` → “Cat meows”.

## 7. Time & Space Complexity
- **Time:** O(1) per call (+ tiny vtable indirection)
- **Space:** O(1) objects + one vptr per polymorphic object (typical)
- Why: fixed demo instances

## 8. Trade-offs & Alternatives
- Virtual calls inhibit some inlining; fine for most OOP designs.
- Prefer `override` to catch signature mismatches.
- Need virtual destructor if deleting derived via base pointer.

## 9. Common Mistakes / Edge Cases
- Missing `virtual` → wrong function called
- Signature mismatch (not really overriding)
- Object slicing when passing by value
- Deleting via non-virtual base destructor

## 10. Interview Follow-ups / Variations
- Pure virtual / abstract interfaces
- Covariance of return types
- Cost of vtables vs templates

## 11. Tags
`oop`, `polymorphism`, `virtual`, `override`, `difficulty:easy`
