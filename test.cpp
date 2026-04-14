// ============================================================
// Lab W7: C++ OOP Review - Catch2 Test File
// ============================================================

#define CATCH_CONFIG_MAIN

// Rename student's main to avoid conflict
#define main student_main
#include "MainProgram.cpp"
#undef main

#include "catch_amalgamated.hpp"

// ============================================================
// TEST GROUP 1: Constructors (20 points)
// ============================================================

TEST_CASE("Default constructor initializes correctly", "[constructors]") {
    Student s;
    REQUIRE(s.getName() == "Unknown");
    REQUIRE(s.getId() == 0);
    REQUIRE(s.getGpa() == Catch::Approx(0.0));
}

TEST_CASE("Parameterized constructor initializes correctly", "[constructors]") {
    Student s("Ali", 101, 3.5);
    REQUIRE(s.getName() == "Ali");
    REQUIRE(s.getId() == 101);
    REQUIRE(s.getGpa() == Catch::Approx(3.5));
}

TEST_CASE("Parameterized constructor with edge values", "[constructors]") {
    Student s("A", 1, 0.0);
    REQUIRE(s.getName() == "A");
    REQUIRE(s.getId() == 1);
    REQUIRE(s.getGpa() == Catch::Approx(0.0));

    Student s2("Test Student", 9999, 4.0);
    REQUIRE(s2.getName() == "Test Student");
    REQUIRE(s2.getGpa() == Catch::Approx(4.0));
}

// ============================================================
// TEST GROUP 2: Copy Constructor (15 points)
// ============================================================

TEST_CASE("Copy constructor creates independent copy", "[copy]") {
    Student original("Mehmet", 200, 3.2);
    Student copy(original);

    REQUIRE(copy.getName() == "Mehmet");
    REQUIRE(copy.getId() == 200);
    REQUIRE(copy.getGpa() == Catch::Approx(3.2));
}

TEST_CASE("Copy is independent from original", "[copy]") {
    Student original("Zeynep", 300, 3.6);
    Student copy(original);

    // Modify the copy
    copy.setName("Changed");
    copy.setGpa(2.0);

    // Original should be unchanged
    REQUIRE(original.getName() == "Zeynep");
    REQUIRE(original.getGpa() == Catch::Approx(3.6));
}

// ============================================================
// TEST GROUP 3: Encapsulation - Getters & Setters (15 points)
// ============================================================

TEST_CASE("Getters return correct values", "[encapsulation]") {
    Student s("Fatma", 400, 3.9);
    REQUIRE(s.getName() == "Fatma");
    REQUIRE(s.getId() == 400);
    REQUIRE(s.getGpa() == Catch::Approx(3.9));
}

TEST_CASE("setName rejects empty string", "[encapsulation]") {
    Student s("Original", 500, 3.0);
    s.setName("");
    REQUIRE(s.getName() == "Original");
}

TEST_CASE("setName accepts valid name", "[encapsulation]") {
    Student s("Original", 500, 3.0);
    s.setName("Updated");
    REQUIRE(s.getName() == "Updated");
}

TEST_CASE("setGpa rejects out-of-range values", "[encapsulation]") {
    Student s("Test", 600, 3.0);

    s.setGpa(-0.1);
    REQUIRE(s.getGpa() == Catch::Approx(3.0));

    s.setGpa(4.1);
    REQUIRE(s.getGpa() == Catch::Approx(3.0));

    s.setGpa(5.0);
    REQUIRE(s.getGpa() == Catch::Approx(3.0));
}

TEST_CASE("setGpa accepts boundary values", "[encapsulation]") {
    Student s("Test", 600, 3.0);

    s.setGpa(0.0);
    REQUIRE(s.getGpa() == Catch::Approx(0.0));

    s.setGpa(4.0);
    REQUIRE(s.getGpa() == Catch::Approx(4.0));

    s.setGpa(2.5);
    REQUIRE(s.getGpa() == Catch::Approx(2.5));
}

// ============================================================
// TEST GROUP 4: String Operations (10 points)
// ============================================================

TEST_CASE("getFormattedName returns uppercase", "[strings]") {
    Student s("ali veli", 700, 3.0);
    REQUIRE(s.getFormattedName() == "ALI VELI");
}

TEST_CASE("getFormattedName with mixed case", "[strings]") {
    Student s("Ayse Kaya", 701, 3.0);
    REQUIRE(s.getFormattedName() == "AYSE KAYA");
}

TEST_CASE("getFormattedName with already uppercase", "[strings]") {
    Student s("TEST", 702, 3.0);
    REQUIRE(s.getFormattedName() == "TEST");
}

// ============================================================
// TEST GROUP 5: Operator Overloading (25 points)
// ============================================================

TEST_CASE("Equality operator compares by ID", "[operators]") {
    Student s1("Ali", 101, 3.5);
    Student s2("Ali Copy", 101, 3.8);
    Student s3("Ayse", 102, 3.5);

    REQUIRE(s1 == s2);       // Same ID
    REQUIRE_FALSE(s1 == s3); // Different ID
}

TEST_CASE("Less-than operator compares by GPA", "[operators]") {
    Student s1("Low", 1, 2.0);
    Student s2("High", 2, 3.5);

    REQUIRE(s1 < s2);
    REQUIRE_FALSE(s2 < s1);
}

TEST_CASE("Less-than with equal GPA", "[operators]") {
    Student s1("A", 1, 3.0);
    Student s2("B", 2, 3.0);

    REQUIRE_FALSE(s1 < s2);
    REQUIRE_FALSE(s2 < s1);
}

TEST_CASE("Stream insertion operator format", "[operators]") {
    Student s("Ali", 101, 3.5);
    std::ostringstream oss;
    oss << s;
    REQUIRE(oss.str() == "Student(Ali, ID: 101, GPA: 3.5)");
}

TEST_CASE("Stream insertion with default student", "[operators]") {
    Student s;
    std::ostringstream oss;
    oss << s;
    REQUIRE(oss.str() == "Student(Unknown, ID: 0, GPA: 0)");
}

// ============================================================
// TEST GROUP 6: Function Overloading (15 points)
// ============================================================

TEST_CASE("findBestStudent with two students", "[functions]") {
    Student s1("Ali", 1, 3.0);
    Student s2("Ayse", 2, 3.8);

    Student best = findBestStudent(s1, s2);
    REQUIRE(best.getGpa() == Catch::Approx(3.8));
}

TEST_CASE("findBestStudent with two equal GPAs", "[functions]") {
    Student s1("Ali", 1, 3.5);
    Student s2("Ayse", 2, 3.5);

    Student best = findBestStudent(s1, s2);
    REQUIRE(best.getGpa() == Catch::Approx(3.5));
}

TEST_CASE("findBestStudent with array", "[functions]") {
    Student arr[] = {
        Student("A", 1, 2.0),
        Student("B", 2, 3.9),
        Student("C", 3, 3.1),
        Student("D", 4, 3.5)
    };

    Student best = findBestStudent(arr, 4);
    REQUIRE(best.getGpa() == Catch::Approx(3.9));
}

TEST_CASE("findBestStudent with single element array", "[functions]") {
    Student arr[] = { Student("Solo", 1, 2.5) };
    Student best = findBestStudent(arr, 1);
    REQUIRE(best.getGpa() == Catch::Approx(2.5));
}

TEST_CASE("findBestStudent best at end of array", "[functions]") {
    Student arr[] = {
        Student("A", 1, 1.0),
        Student("B", 2, 2.0),
        Student("C", 3, 4.0)
    };

    Student best = findBestStudent(arr, 3);
    REQUIRE(best.getGpa() == Catch::Approx(4.0));
}
