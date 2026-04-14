# Grading Rubric — Lab W7: C++ OOP Review

**Total: 100 points**

## Test-Based Grading (85 points)

| Category | Test Cases | Points |
|----------|-----------|--------|
| **Constructors & Destructor** | Default constructor, Parameterized constructor, Edge values | **20** |
| **Copy Constructor** | Creates correct copy, Copy is independent from original | **15** |
| **Encapsulation (Getters/Setters)** | Getters return correct values, setName rejects empty, setName accepts valid, setGpa rejects out-of-range, setGpa accepts boundaries | **15** |
| **String Operations** | Uppercase conversion, Mixed case, Already uppercase | **10** |
| **Operator Overloading** | `==` by ID, `<` by GPA, `<` with equal GPA, `<<` format, `<<` default student | **25** |
| **Function Overloading** | Two students, Equal GPAs, Array (best in middle), Single element, Best at end | **15** |

### Detailed Breakdown

| Test Name | Points |
|-----------|--------|
| Default constructor initializes correctly | 7 |
| Parameterized constructor initializes correctly | 7 |
| Parameterized constructor with edge values | 6 |
| Copy constructor creates independent copy | 8 |
| Copy is independent from original | 7 |
| Getters return correct values | 5 |
| setName rejects empty string | 3 |
| setName accepts valid name | 2 |
| setGpa rejects out-of-range values | 5 |
| setGpa accepts boundary values | 5 |
| getFormattedName returns uppercase | 4 |
| getFormattedName with mixed case | 3 |
| getFormattedName with already uppercase | 3 |
| Equality operator compares by ID | 5 |
| Less-than operator compares by GPA | 5 |
| Less-than with equal GPA | 5 |
| Stream insertion operator format | 5 |
| Stream insertion with default student | 5 |
| findBestStudent with two students | 4 |
| findBestStudent with two equal GPAs | 3 |
| findBestStudent with array | 3 |
| findBestStudent with single element array | 3 |
| findBestStudent best at end of array | 2 |

## Non-Test Grading (15 points)

| Criteria | Points |
|----------|--------|
| Code compiles without errors or warnings | 10 |
| Clean code style (indentation, naming, no dead code) | 5 |

## Penalty

| Issue | Deduction |
|-------|-----------|
| Modified test.cpp or Catch2 files | -20 |
| Used header files (must be single file) | -10 |
| Late submission (per day) | -10 |
