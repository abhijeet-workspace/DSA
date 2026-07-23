# Inheritance

## 1. Problem Statement
Show C++ inheritance forms: single, multilevel, hierarchical, and multiple/virtual (diamond) inheritance.

- **Input:** none (hardcoded animal/diamond demos)
- **Output:** method calls plus constructor order for the diamond case
- **Valid answer:** derived objects use base + own methods; `LivingThing` constructs once under virtual bases
- **Edges:** without `virtual`, diamond would duplicate `LivingThing` and make `breathe` ambiguous

## 2. Intuition
Reuse: a derived class inherits base state/behavior and adds specialized methods. Virtual inheritance merges a shared base when two parents both derive from it.

## 3. Brute Force → Optimal
- **Brute:** copy-paste fields/methods into every “kind of animal” class.
- **This approach:** IS-A hierarchies + `virtual public` for the diamond.

## 4. Data Structure / Approach Justification
**Chosen:** class hierarchy with `protected` name and public behaviors.

| Alternative | Why it loses / wins |
|-------------|---------------------|
| Composition (“has-a”) | Often preferred in large systems; less IS-A modeling |
| Interfaces-only (pure virtual) | More flexible contracts; covered in abstraction lesson |
| Non-virtual diamond | Ambiguity / duplicate subobjects |

## 5. Logic Walkthrough
1. `Dog : Animal` — single inheritance; `eat` + `bark`.
2. `GermanShepherd : Dog` — multilevel; also `guard`.
3. `Cat : Animal` — hierarchical sibling of `Dog`.
4. `ParentA`/`ParentB` virtually inherit `LivingThing`; `Child` inherits both → one `LivingThing`.

## 6. Dry Run
`Dog("Buddy")`: `eat` → “Buddy is eating.”; `bark` → Woof.
`Child child`: ctor prints `LivingThing` once, then `ParentA`, `ParentB`, `Child`; `breathe()` works unambiguously.

## 7. Time & Space Complexity
- **Time:** O(1) per method call
- **Space:** O(1) per object (+ one shared virtual base subobject in diamond)
- Why: fixed demo objects; no containers

## 8. Trade-offs & Alternatives
- Prefer composition when reuse is “has-a”.
- Virtual bases add slight size/complexity; use only when needed.
- Public vs protected/private inheritance changes interface exposure.

## 9. Common Mistakes / Edge Cases
- Forgetting `virtual` on diamond bases
- Slicing when passing derived by value as base
- Missing virtual destructor when deleting via base pointer (see move-semantics lesson)

## 10. Interview Follow-ups / Variations
- When to prefer composition over inheritance
- Explain ctor/dtor order with virtual bases
- Mix-in style with CRTP vs classic inheritance

## 11. Tags
`oop`, `inheritance`, `diamond-problem`, `difficulty:easy`
