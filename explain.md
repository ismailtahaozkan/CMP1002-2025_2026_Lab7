# C++ OOP Review: Comprehensive Concept Guide

## 1. Concept Overview

This lab reviews all major object-oriented programming concepts covered in Weeks 1–5. You will build a complete `Student` class that demonstrates encapsulation, constructors, destructors, copy constructors, string manipulation, operator overloading, and function overloading — all in a single file.

The idea is simple: a `Student` has a name, an ID, and a GPA. But implementing it properly requires applying every OOP concept you have learned so far.

## 2. Key Concepts

- **Class**: A user-defined type that groups data and functions together
- **Object**: An instance of a class (a variable whose type is a class)
- **Encapsulation**: Hiding internal data (`private`) and exposing a controlled interface (`public`)
- **Constructor**: Special function that runs when an object is created
- **Destructor**: Special function that runs when an object is destroyed
- **Copy Constructor**: A constructor that creates a new object as a copy of an existing one
- **Operator Overloading**: Defining custom behavior for operators like `==`, `<`, `<<`
- **Function Overloading**: Multiple functions with the same name but different parameters
- **`const` correctness**: Marking methods/parameters as `const` when they don't modify data
- **UML Class Diagram**: A visual representation of a class showing its attributes and methods

## 3. Important Keywords

| Keyword | Meaning |
|---------|---------|
| `class` | Declares a new class type |
| `private` | Members accessible only inside the class |
| `public` | Members accessible from anywhere |
| `const` | Promises not to modify data |
| `friend` | Grants a non-member function access to private members |
| `this` | Pointer to the current object |
| `~ClassName` | Destructor syntax |
| `operator` | Keyword used to overload an operator |
| `string` | C++ standard string class (from `<string>`) |
| `toupper()` | Converts a character to uppercase |

## 4. Common Mistakes

- **Forgetting `const` on getters**: `getName()` should be `const` because it doesn't change the object
- **Not returning the stream in `operator<<`**: You must `return os;` at the end
- **Missing `&` in copy constructor**: `Student(Student other)` causes infinite recursion! Must be `Student(const Student& other)`
- **Wrong boundary check in setters**: `if (g >= 0.0 && g <= 4.0)` — both 0.0 and 4.0 are valid
- **Empty string validation**: Check `!n.empty()` or `n.length() > 0`, not `n != ""`
- **Confusing `=` and `==`**: `=` assigns, `==` compares
- **Forgetting `friend` for `operator<<`**: Without it, the function can't access private members

## 5. Mini Examples

### Constructor Types
```cpp
// Default
Student() : name("Unknown"), id(0), gpa(0.0) {}

// Parameterized
Student(string n, int i, double g) : name(n), id(i), gpa(g) {}

// Copy
Student(const Student& other) : name(other.name), id(other.id), gpa(other.gpa) {}
```

### Operator Overloading
```cpp
// Compare two students by ID
bool operator==(const Student& other) const {
    return id == other.id;
}

// Print a student
friend ostream& operator<<(ostream& os, const Student& s) {
    os << s.name << " (GPA: " << s.gpa << ")";
    return os;
}
```

### Function Overloading
```cpp
// Same name, different parameters
Student findBest(const Student& a, const Student& b);
Student findBest(Student arr[], int size);
```

### String to Uppercase
```cpp
string upper = name;
for (size_t i = 0; i < upper.length(); i++) {
    upper[i] = toupper(upper[i]);
}
```

## 6. When to Use This

| Concept | Use When... |
|---------|-------------|
| Encapsulation | You need to protect data from invalid changes |
| Copy Constructor | You need an independent copy of an object |
| Destructor | You need to clean up resources (memory, files) |
| `operator==` | You want to compare objects with `==` |
| `operator<` | You want to sort or compare objects |
| `operator<<` | You want to print objects with `cout` |
| Function Overloading | You want the same operation on different types/counts of inputs |
| `const` methods | The method only reads data, never writes |

## 7. Reading a UML Class Diagram

A UML class diagram is a box with three sections:

```
+----------------------------+
|         Student            |   <- Class name (top section)
+----------------------------+
| - name: string             |   <- Attributes (middle section)
| - id: int                  |      "-" means private
| - gpa: double              |
+----------------------------+
| + Student()                |   <- Methods (bottom section)
| + Student(string, int, double) |   "+" means public
| + Student(const Student&)  |
| + ~Student()               |
| + getName(): string        |
| + getId(): int             |
| + getGpa(): double         |
| + setName(string): void    |
| + setGpa(double): void     |
| + getFormattedName(): string |
| + operator==(Student): bool |
| + operator<(Student): bool |
+----------------------------+
```

**Access modifiers:**
- `-` = private (only the class itself can access)
- `+` = public (anyone can access)
- `#` = protected (class and its children can access)

**How to read a method line:**
`+ getName(): string` means: public method called `getName`, takes no parameters, returns a `string`.
