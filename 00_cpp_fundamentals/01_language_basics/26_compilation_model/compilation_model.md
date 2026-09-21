# Compilation Model

## 1. Problem Statement
Show the compile→link model: a header declares `square`, `math_ops.cpp` defines it, `main.cpp` calls it. Both `.cpp` files must be compiled and linked together.

- **Input:** none
- **Output:** `square(5)=25` plus a sample build command
- **Valid answer:** declaration is enough to compile a call; definition is required to link
- **Edges:** duplicate definitions across TUs → linker error (ODR)

## 2. Intuition
Each `.cpp` is a **translation unit** compiled to an object file. The **linker** resolves symbols across object files into one executable.

## 3. Brute Force → Optimal
- **Naive:** put all code in one giant `.cpp`.
- **This approach:** headers for shared declarations; one definition per function/variable across the program.

## 4. Data Structure / Approach Justification
Minimal two-file program — same idea as multi-file practice, focused on the mental model.

| Alternative | Why it loses here |
|-------------|-------------------|
| Header-only inline/templates | Valid; hides linking for non-templates |
| Static libraries | Same linking idea at larger scale |

## 5. Logic Walkthrough
1. Preprocessor includes `math_ops.h` into `main.cpp`.
2. Compiler emits a call to unresolved `square`.
3. Compiler builds `math_ops.cpp` with the definition.
4. Linker wires the call to the definition.

## 6. Dry Run
| Stage | Result |
|-------|--------|
| compile `main.cpp` | object with undefined `square` |
| compile `math_ops.cpp` | object defining `square` |
| link | executable prints 25 |

## 7. Time & Space Complexity
- N/A for runtime of `square` (O(1)).
- Build cost grows with number/size of TUs.

## 8. Trade-offs & Alternatives
- Prefer include guards / `#pragma once` in headers.
- Prefer declarations in headers, definitions in `.cpp` for non-templates.
- Prefer build systems (CMake/Make) once file count grows.

## 9. Common Mistakes / Edge Cases
- Forgetting to link `math_ops.cpp` → undefined reference
- Defining non-inline functions in headers included by multiple TUs
- Circular includes without guards

## 10. Interview Follow-ups / Variations
- What is the One Definition Rule (ODR)?
- Why are templates usually header-only?
- Difference between declaration, definition, and initialization?

## 11. Tags
`cpp-basics`, `compilation`, `linker`, `translation-unit`, `beginner`
