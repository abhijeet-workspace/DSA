# Constructors, Move Semantics & Virtual Destructors

## 1. Problem Statement
Implement Rule-of-Five ownership for a heap buffer (`ResourceManager`) and show why a virtual base destructor is required when deleting derived objects via `Base*`.

- **Input:** none
- **Output:** ctor/copy/move/dtor messages; moved-from prints empty; both Base and Derived dtors run
- **Valid answer:** deep copy allocates new buffer; move steals pointer and nulls source
- **Edges:** self-assignment checks; moved-from must be destructible; non-virtual base dtor would leak `derivedData`

## 2. Intuition
Owning raw `new[]` means you must define copy/move/destroy correctly. Moves transfer ownership cheaply. Polymorphic delete needs a virtual destructor so the most-derived cleanup runs.

## 3. Brute Force → Optimal
- **Brute:** shallow copy (double-free) or always deep-copy even for temporaries.
- **This approach:** deep copy for lvalues; move for rvalues; virtual `~Base`.

## 4. Data Structure / Approach Justification
**Chosen:** manual Rule of Five on `int* data`.

| Alternative | Why it loses / wins |
|-------------|---------------------|
| `std::vector<int>` | RAII; preferred in production |
| `unique_ptr<int[]>` | Correct ownership with less code |
| Rule of zero | Best when members already manage resources |

## 5. Logic Walkthrough
1. Param ctor allocates `size` ints initialized to `i*10`.
2. Copy ctor/assign allocate + copy bytes (deep).
3. Move ctor/assign steal pointer; null source.
4. `print` shows up to 5 values or empty-after-move.
5. `delete` via `Base*` runs `~Derived` then `~Base` because `~Base` is virtual.

## 6. Dry Run
`r1(10)` → `0 10 20 30 40 ...`
`r2 = r1` → deep copy message; independent buffer.
`r3 = move(r1)` → r3 prints data; r1 “No data”.
`r4 = move(r3)` → r4 owns; r3 empty.
`new Derived` / `delete` → Derived then Base destructor lines.

## 7. Time & Space Complexity
- **Copy:** O(n) time/space for buffer size n
- **Move:** O(1) time/space
- **Virtual delete demo:** O(1) (+ 100 ints in Derived)
- Why: copy walks all elements; move only rebinds pointers

## 8. Trade-offs & Alternatives
- Prefer rule of zero with STL/smart pointers.
- Mark moves `noexcept` so containers prefer them on reallocation.
- Copy-and-swap can simplify assignment exception safety.

## 9. Common Mistakes / Edge Cases
- Shallow copy → double-free
- Forgetting to null moved-from pointer
- Missing self-assignment guard (esp. with delete-first assign)
- Non-virtual destructor on polymorphic base

## 10. Interview Follow-ups / Variations
- Implement copy-and-swap assignment
- Explain when compilers generate moves
- Contrast `unique_ptr` vs manual Rule of Five

## 11. Tags
`oop`, `move-semantics`, `rule-of-five`, `virtual-destructor`, `difficulty:medium`
