# Header Files Basics Demo

## Problem Statement

Show how declarations live in headers (`.h`/`.hpp`) and definitions can live in `.cpp`, including include guards, inline/constexpr helpers, templates, a normal class (`Widget`), and PIMPL (`PimplWidget`).

- **Build:** link `widget.cpp` and `pimpl_widget.cpp` with this file.
- **Outputs:** printed demos of macros, globals, helpers, and class APIs.

## Intuition

Headers are the public contract. Including a header pastes declarations so other TUs can call APIs without seeing full implementations (except templates/inline).

## Brute Force → Optimal

**Naive:** put everything in one `.cpp` — no reuse, slow rebuilds for large projects.

**This approach:** split declarations/definitions; use include guards; keep heavy code out of headers when possible.

## Data Structure / Approach Justification

**Chosen:** multiple small headers + two translation units for class impls.

- **vs header-only:** simpler distribution but longer compile times.
- **vs unity builds:** faster CI sometimes, worse incremental rebuild locality.
- Templates (`math_ops.hpp`) must stay visible to the compiler → header-only.

## Logic Walkthrough

1. Include project headers after standard headers.
2. Use `PROJECT_NAME` / `LOG_DEBUG` from `config.h`.
3. Call inline/constexpr helpers from `basics.h` / `utils.h` / `math_ops.hpp`.
4. Construct `Widget` / `PimplWidget` whose methods are defined in sibling `.cpp` files.
5. Print best-practice reminders.

## Dry Run

`greet("World")` → greeting string; `square_constexpr(5)` → `25`; `add<int>(2,3)` → `5`; `Widget("MyWidget").name()` → `"MyWidget"`; `PimplWidget` returns hidden impl name similarly.

## Time & Space Complexity

Runtime of the demo is O(1) (fixed prints). Build cost grows with include graph size — motivation for forward declarations and PIMPL.

## Trade-offs & Alternatives

PIMPL reduces rebuild fan-out at the cost of heap indirection. Header-only libraries trade compile time for easy consumption.

## Common Mistakes / Edge Cases

- Missing include guards → redefinition errors.
- Defining non-inline functions in headers included by multiple TUs → ODR violations.
- `using namespace std;` inside headers pollutes every includer.
- Circular includes without forward declarations.

## Interview Follow-ups / Variations

- Prefers `#pragma once` vs portable include guards.
- Export modules (C++20) as an alternative packaging model.
- When to forward-declare vs include.

## Tags

`headers`, `translation-units`, `pimpl`, `inline`, `difficulty:medium`
