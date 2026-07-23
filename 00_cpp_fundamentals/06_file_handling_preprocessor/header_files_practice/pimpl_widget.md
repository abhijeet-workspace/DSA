# PIMPL Widget

## Problem Statement

Implement the Pointer-to-Implementation (PIMPL) idiom for `PimplWidget`: public header holds only an opaque `std::unique_ptr<Impl>`, while `Impl` and method bodies live in this `.cpp`.

- No `main()` here — linked by the demos.
- Goal: stable ABI / fewer header dependencies for clients.

## Intuition

If private members change, a normal class forces all clients to recompile. PIMPL keeps the header layout stable: only a pointer.

## Brute Force → Optimal

**Naive:** put `std::string name_` in the header — clients include `<string>` and rebuild on private changes.

**This approach:** incomplete type `Impl` in the header; complete type only in the `.cpp`.

## Data Structure / Approach Justification

**Chosen:** `unique_ptr<Impl>` PIMPL.

- **vs opaque `void*`:** less type-safe, manual lifetime.
- **vs abstract interface + factory:** more polymorphic flexibility, heavier design.
- Destructor must be defined in the `.cpp` where `Impl` is complete.

## Logic Walkthrough

1. Define nested `Impl` with `name`.
2. Constructor allocates `Impl` via `make_unique`.
3. `name()` dereferences `impl_`.
4. Default destructor in `.cpp` destroys `Impl` correctly.

## Dry Run

`PimplWidget pw("HiddenWidget");` → heap `Impl{name:"HiddenWidget"}` → `pw.name()` returns `"HiddenWidget"`. Header users never see `Impl` fields.

## Time & Space Complexity

Extra O(1) heap allocation per object. Access is one pointer indirection.

## Trade-offs & Alternatives

+ Faster incremental builds, hidden deps. − Heap traffic, harder inlining, must manage special members carefully.

## Common Mistakes / Edge Cases

- Defaulting destructor in the header while `Impl` is incomplete → compile error.
- Forgetting copy/move policy (unique_ptr makes class move-only by default).
- Leaking by using raw `new` without matching delete.

## Interview Follow-ups / Variations

- Add const-correct accessors returning `string_view`.
- Implement deep copy if copying is required.
- Compare with C++20 modules for dependency control.

## Tags

`pimpl`, `encapsulation`, `unique_ptr`, `difficulty:medium`
