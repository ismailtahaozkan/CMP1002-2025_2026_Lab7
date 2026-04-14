# Lab W7: C++ OOP Review

## Topic
Comprehensive review of Weeks 1–6: Classes, Encapsulation, Constructors, Destructors, Copy Constructors, Strings, Operator Overloading, and Function Overloading.

## Duration
40 minutes

## Learning Objectives
By the end of this lab, students will be able to:
1. Define a class with private data members and public methods (encapsulation)
2. Implement default, parameterized, and copy constructors
3. Write a destructor with visible output
4. Use getter/setter methods with input validation
5. Perform basic string operations (uppercase conversion)
6. Overload operators (`==`, `<`, `<<`)
7. Implement function overloading with different parameter lists
8. Read and interpret a UML class diagram

## Prerequisites
- Weeks 1–6 lecture material
- Basic understanding of C++ syntax
- Familiarity with `std::string`

## File Structure
```
lab-W7/
├── MainProgram.cpp         <- Your work goes here (single file)
├── test.cpp                <- Catch2 test file (do not modify)
├── catch_amalgamated.hpp   <- Catch2 header (do not modify)
├── catch_amalgamated.cpp   <- Catch2 source (do not modify)
├── Makefile                <- Build system
├── README.md               <- This file
├── explain.txt             <- Quick revision sheet
└── explain.md              <- Detailed concept guide
```

## Instructions

### How to Compile
```bash
make
```

### How to Run
```bash
./main
```

### How to Test (all tests)
```bash
make test
```

### How to Test Individual Sections
```bash
make test1    # Constructors & Destructor       [20 pts]
make test2    # Copy Constructor                 [15 pts]
make test3    # Encapsulation (Getters/Setters)  [15 pts]
make test4    # String Operations                [10 pts]
make test5    # Operator Overloading             [25 pts]
make test6    # Function Overloading             [15 pts]
```

### How to See Grade Summary
```bash
make grade
```

### How to Clean
```bash
make clean
```

## What You Need to Do
1. Open `MainProgram.cpp`
2. Read the class diagram in `explain.md` to understand the structure
3. Find all `// TODO` comments and implement each one
4. There are 6 tasks with sub-parts (approximately 15 code blocks to fill)
5. Test frequently using `make test`

## Task Summary
| Task | Topic | Points |
|------|-------|--------|
| 1 | Constructors & Destructor | 20 |
| 2 | Getters (Encapsulation) | 5 |
| 3 | Setters with Validation | 10 |
| 4 | String Operations | 10 |
| 5 | Operator Overloading | 25 |
| 6 | Function Overloading | 15 |
| — | Code compiles without errors | 10 |
| — | Clean code style | 5 |

## Submission Instructions
1. Submit only `MainProgram.cpp`
2. Ensure `make test` passes before submitting
3. Do not modify `test.cpp` or Catch2 files

## Common Mistakes
- Forgetting `const` on getter methods
- Not returning `os` in the `operator<<` function
- Using `=` instead of `==` in comparisons
- Not handling boundary values in `setGpa` (0.0 and 4.0 are valid)
- Forgetting to cast characters with `toupper()` back to `char`
- Returning by value when reference is needed (and vice versa)

## Academic Integrity
This is an individual lab assignment. You may consult your notes and textbook, but all code must be your own work. Copying from other students or online sources is a violation of academic integrity policy.
