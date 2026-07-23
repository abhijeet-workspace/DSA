# Widget Class Implementation

## Problem Statement

Provide the out-of-line definitions for `Widget` declared in `widget.h`, and define `GLOBAL_CONST` with external linkage for use from other TUs.

- **Inputs:** constructor `name` string.
- **API:** `name()` returns stored name; `id()` stays inline in the header.
- **Note:** this file has no `main()` — it is linked into the demos.

## Intuition

Keep the header as a lightweight contract. Moving method bodies to a `.cpp` reduces rebuilds when implementations change.

## Brute Force → Optimal

**Naive:** define all methods inline in the header — simple, but every includer recompiles when a method body changes.

**This approach:** declare in `.h`, define in `.cpp`.

## Data Structure / Approach Justification

**Chosen:** classic class split across header/source.

- **vs header-only class:** worse incremental compile locality for non-template code.
- **vs PIMPL:** PIMPL hides private members entirely; here `name_` remains visible in the header.

## Logic Walkthrough

1. `#include "widget.h"` so signatures match.
2. Define `GLOBAL_CONST` once with `extern const` linkage.
3. Constructor initializes `name_` via move.
4. Destructor defaulted; `name()` returns a copy of `name_`.

## Dry Run

`Widget w("MyWidget");` → `name_ == "MyWidget"` → `w.name()` returns `"MyWidget"`. `GLOBAL_CONST` reads as `42` from other TUs.

## Time & Space Complexity

Construction/access are O(L) in name length for copy/move of the string; otherwise O(1).

## Trade-offs & Alternatives

Exposing `name_` type in the header couples clients to `std::string`. PIMPL would hide that at pointer cost.

## Common Mistakes / Edge Cases

- Defining `GLOBAL_CONST` in a header without `inline`/`constexpr` → multiple-definition errors.
- Forgetting to link `widget.cpp` with demos.
- Mismatching signatures between `.h` and `.cpp`.

## Interview Follow-ups / Variations

- Add move constructor/assignment.
- Replace `std::string` return with `std::string_view` carefully (lifetime).
- Hide `id_` generation logic.

## Tags

`oop`, `headers`, `linkage`, `difficulty:easy`
