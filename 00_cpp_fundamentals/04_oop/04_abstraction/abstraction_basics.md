# Abstraction Basics

## 1. Problem Statement
Define abstract `SmartDevice` with pure virtual `performDuty` / `getDeviceStatus`, implement `SmartLight` and `SmartThermostat`, and drive them through base pointers.

- **Input:** heap devices created in `main`
- **Output:** status/power/duty messages per device
- **Valid answer:** cannot instantiate `SmartDevice`; derived classes fulfill the contract
- **Edge cases:** duty while OFF; deleting via base requires virtual destructor

## 2. Intuition
Show the essential interface; hide how each device works. Pure virtual functions force every concrete type to supply the missing behavior.

## 3. Brute Force → Optimal
- **Naive:** one fat class with `if (isLight)` branches.
- **This approach:** abstract base + overrides; callers depend on the interface.

## 4. Data Structure / Approach Justification
**Chosen:** abstract class (pure virtuals) + polymorphic pointers.

| Alternative | Why it loses here |
|-------------|-------------------|
| Concrete base with empty stubs | Easy to forget real implementation |
| C++20 concepts / templates | Compile-time only; different lesson |
| `std::function` callbacks | Flexible but no shared protected state story |

Trade-off: heap + virtual dispatch cost; clear teaching of contracts.

## 5. Logic Walkthrough
1. `= 0` pure virtuals make `SmartDevice` abstract.
2. Shared `turnOn`/`turnOff` stay concrete on the base.
3. Each derived class implements duty/status differently.
4. `main` uses `SmartDevice*` then `static_cast` for derived-only setters.
5. `delete` via base is safe because destructor is virtual.

## 6. Dry Run
| Step | Device | isOn | Action |
|------|--------|------|--------|
| status | Light | false | prints OFF, brightness 50 |
| turnOn + setBrightness(85) | Light | true | brightness 85 |
| performDuty | Light | true | illuminates at 85% |
| turnOff + performDuty | Thermo | false | idle message |

## 7. Time & Space Complexity
- **Time:** O(1) per virtual call
- **Space:** O(1) per device on heap
- Why: fixed objects; no collections

## 8. Trade-offs & Alternatives
- Prefer stack objects / smart pointers (`unique_ptr<SmartDevice>`) in production.
- Prefer interface segregation: split status vs control if clients diverge.
- `dynamic_cast` is safer than `static_cast` when type is uncertain.

## 9. Common Mistakes / Edge Cases
- Trying to construct an abstract class
- Non-virtual destructor on polymorphic base
- Forgetting to implement a pure virtual in a derived class
- Leaking heap devices

## 10. Interview Follow-ups / Variations
- Abstract class vs interface (all-pure) vs Java interface?
- Can abstract classes have data members and constructors?
- Dependency Inversion: depend on `SmartDevice`, not concretes?

## 11. Tags
`oop`, `abstraction`, `pure-virtual`, `abstract-class`, `difficulty:medium`
