# Array Insertion

## 1. Problem Statement
Allocate a fixed `int arr[10]`, read 10 integers from stdin into consecutive indices, then print each value and its address.

- **Input:** 10 integers (one per prompt)
- **Output:** length info, then per-index value and address lines
- **Valid answer:** `arr[i]` holds the i-th input; addresses increase by `sizeof(int)` in a contiguous block
- **Edges:** non-integer input leaves `cin` failed; capacity is fixed at 10

## 2. Intuition
A C-style array is a contiguous block. Index `i` means “base address + i * element size”. Filling with a loop is the basic write pattern.

## 3. Brute Force → Optimal
- **Naive:** hardcode ten separate `cin >> arr0; cin >> arr1; ...` variables.
- **This approach:** one array + index loop — scales to any fixed length.

## 4. Data Structure / Approach Justification
Fixed stack array `int arr[10]`.

| Alternative | Why it loses / wins |
|-------------|---------------------|
| `std::vector<int>` | Better when size is runtime-unknown; slightly more API surface for this lesson |
| `std::array<int,10>` | Safer C++ wrapper; good next step |
| Dynamic `new int[n]` | Needs manual `delete[]`; overkill here |

## 5. Logic Walkthrough
1. `arrLength` from `sizeof(arr)/sizeof(arr[0])` → 10.
2. First loop: for each `i`, read into `arr[i]`.
3. Second loop: print `arr[i]` and `&arr[i]` to show contiguous addresses.

## 6. Dry Run
Suppose inputs `7 8 9 ...` for indices 0..2 (abbreviated):

| i | `arr[i]` | Note |
|---|----------|------|
| 0 | 7 | base address A |
| 1 | 8 | address ≈ A + 4 |
| 2 | 9 | address ≈ A + 8 |

## 7. Time & Space Complexity
- **Time:** O(n) for n = `arrLength` (two linear passes)
- **Space:** O(n) for the array (here n = 10 constant)
- Why: one write pass, one read pass over fixed storage

## 8. Trade-offs & Alternatives
- Prefer `std::vector` when n comes from input.
- Prefer `std::array` for fixed size with STL iterators.
- Printing `&arr[i]` is educational; production code rarely dumps raw addresses.

## 9. Common Mistakes / Edge Cases
- Using `sizeof(arr)` as “length” without dividing by element size
- Writing past index 9 (undefined behavior)
- Forgetting that decayed pointers lose `sizeof` length info in functions
- Not checking `cin` failure

## 10. Interview Follow-ups / Variations
- How do you pass arrays to functions without losing length?
- Insert in the middle of a dynamic list — array vs linked list cost?
- What is row-major layout for 2D arrays?

## 11. Tags
`cpp-basics`, `arrays`, `iostream`, `addresses`, `beginner`
