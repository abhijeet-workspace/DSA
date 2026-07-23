# File Handling

## Problem Statement

Teach basic C++ file I/O: write a string to `data.txt`, then read it back and print it.

- **Inputs:** a literal message (`"Hello File"`).
- **Outputs:** file on disk + console line `Read: Hello File`.
- **Constraints:** text mode; single line; no error-path handling in this demo.
- **Edge cases:** missing file on read, write failure, not closing streams (resource leak).

## Intuition

Disk persistence needs a stream bound to a path. `ofstream` writes; `ifstream` reads. After writing, reopen (or seek) before reading so the file contents are visible.

## Brute Force → Optimal

**Naive:** print only to `std::cout` — nothing persists across runs.

**This approach:** open an output file stream, write, close; open an input stream, `getline`, print. Same pattern scales to logs, configs, and datasets.

## Data Structure / Approach Justification

**Chosen:** `std::ofstream` / `std::ifstream` (stream abstraction over files).

- **vs C `FILE*`:** streams are type-safe with `<<`/`>>` and RAII-friendly when scoped.
- **vs `stdio` freopen:** less portable and harder to compose with C++ types.
- **Trade-off:** streams can be slightly heavier than raw C I/O; fine for learning and most apps.

## Logic Walkthrough

1. Construct `out` → creates/truncates `data.txt`.
2. `out << "Hello File"` writes bytes; `endl` adds newline and flushes.
3. `out.close()` finishes the write.
4. Construct `in` on the same path.
5. `getline(in, line)` fills `line` until newline.
6. Print `line`; close `in`.

## Dry Run

Start: no file (or old content).

1. Write → file contains `Hello File\n`.
2. Read → `line == "Hello File"`.
3. Console: `Read: Hello File`.

## Time & Space Complexity

- **Time:** O(L) for line length L (one write + one read).
- **Space:** O(L) for `line`.
- Disk I/O dominates; asymptotic cost is linear in bytes transferred.

## Trade-offs & Alternatives

- Prefer RAII scopes (`{ ofstream out(...); }`) over manual `close()`.
- Binary I/O needs `ios::binary` and unformatted read/write.
- For large files, prefer buffered block reads over line-by-line when parsing formats allow.

## Common Mistakes / Edge Cases

- Forgetting to check `out`/`in` failbit after open.
- Reading before closing/flushing the writer (same stream without seek).
- Assuming `getline` strips only `\n` on all platforms without caring about `\r`.
- Leaving files open across long lifetimes.

## Interview Follow-ups / Variations

- Append mode (`ios::app`).
- Read whole file into `stringstream`.
- Error handling with exceptions (`exceptions()` on stream).
- Binary serialization of structs.

## Tags

`file-io`, `fstream`, `basics`, `difficulty:easy`
